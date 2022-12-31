import cv2
import sys
from PyQt5 import QtTest
from PyQt5.QtWidgets import  *
from PyQt5.QtCore import QThread, Qt, pyqtSignal, pyqtSlot, QTimer
from PyQt5.QtGui import QImage, QPixmap
import os
import numpy as np
import tensorflow as tf
from object_detection.utils import label_map_util
from object_detection.utils import config_util
from object_detection.utils import visualization_utils as viz_utils
from object_detection.utils.visualization_utils import STANDARD_COLORS
from object_detection.builders import model_builder
from PIL import ImageColor

MODELS_DIR = os.path.join(os.path.join(os.getcwd(), 'data'), 'models')
MODEL_NAME = 'efficientdet'
PATH_TO_CKPT = os.path.join(MODELS_DIR, os.path.join(MODEL_NAME, 'checkpoint/'))
PATH_TO_CFG = os.path.join(MODELS_DIR, os.path.join(MODEL_NAME, 'pipeline.config'))
PATH_TO_LABELS = os.path.join(MODELS_DIR, os.path.join(MODEL_NAME, 'label_map.pbtxt'))
TRACKED_NAME = 'person'
LAST_TRACKED_NAME = 'person'

class Thread(QThread):
    changePixmap = pyqtSignal(QImage)
    not_found_signal = pyqtSignal(int)
    loaded = pyqtSignal()
    source = 0
    stopvar = 0

    def stop(self):
        self.stopvar = 1

    def run(self):

        gpus = tf.config.experimental.list_physical_devices('GPU')
        for gpu in gpus:
            tf.config.experimental.set_memory_growth(gpu, True)

        configs = config_util.get_configs_from_pipeline_file(PATH_TO_CFG)
        model_config = configs['model']
        detection_model = model_builder.build(model_config=model_config, is_training=False)

        ckpt = tf.compat.v2.train.Checkpoint(model=detection_model)
        ckpt.restore(os.path.join(PATH_TO_CKPT, 'ckpt-0')).expect_partial()

        @tf.function
        def detect_fn(image):
            image, shapes = detection_model.preprocess(image)
            prediction_dict = detection_model.predict(image, shapes)
            detections = detection_model.postprocess(prediction_dict, shapes)
            return detections, prediction_dict, tf.reshape(shapes, [-1])

        category_index = label_map_util.create_category_index_from_labelmap(PATH_TO_LABELS, use_display_name=True)

        cap = cv2.VideoCapture(0)
        detect_history = []

        class Overlay():
            lines = []
            def __init__(self, x1, y1, x2, y2, color):
                self.x1 = x1
                self.y1 = y1
                self.x2 = x2
                self.y2 = y2
                self.color = color
            def addLine(self):
                Overlay.lines.append([self.x1, self.y1, self.x2, self.y2, self.color])
        
        def saveDetect(name, curX, curY, color):
            global TRACKED_NAME
            global LAST_TRACKED_NAME
            if TRACKED_NAME != LAST_TRACKED_NAME:
                Overlay.lines.clear()
                LAST_TRACKED_NAME = TRACKED_NAME
                return
            if name == LAST_TRACKED_NAME:
                if len(detect_history) == 0:
                    detect_history.append([name, curX, curY, color])
                else:
                    buf = 0
                    for i in range(len(detect_history)):
                        if detect_history[i][0] == name:
                            prevX = detect_history[i][1]
                            prevY = detect_history[i][2]
                            color = detect_history[i][3]
                            Overlay.addLine(Overlay(prevY, prevX, curY, curX, color))
                            detect_history[i][1] = curX
                            detect_history[i][2] = curY
                        buf = i
                    if buf == (len(detect_history)-1):
                        detect_history.append([name, curX, curY, color])
        cap = cv2.VideoCapture(self.source)
        self.loaded.emit()
        not_found = 0
        while True:
            ret, image_np = cap.read()
            image_np = cv2.resize(image_np, (640,480))
            input_tensor = tf.convert_to_tensor(value=np.expand_dims(image_np, 0), dtype=tf.float32)
            detections, predictions_dict, shapes = detect_fn(input_tensor)
            label_id_offset = 1
            image_np_with_detections = image_np.copy()

            viz_utils.visualize_boxes_and_labels_on_image_array(                                                                                                      
                image_np_with_detections,                   detections['detection_boxes'][0].numpy(),     (detections['detection_classes'][0].numpy() + label_id_offset).astype(int),
                detections['detection_scores'][0].numpy(),  category_index,                               use_normalized_coordinates=True,          
                max_boxes_to_draw=10,                       min_score_thresh=.6,                         agnostic_mode=False)
            
            is_found = False
            for i in range(6):
                if (detections['detection_scores'][0][i].numpy() > 0.6):
                    #print("name:  ", category_index.get((detections['detection_classes'][0][i].numpy() + label_id_offset).astype(int)).get('name'))
                    yCur = (detections['detection_boxes'][0][i][0].numpy() + detections['detection_boxes'][0][i][2].numpy()) / 2
                    xCur = (detections['detection_boxes'][0][i][1].numpy() + detections['detection_boxes'][0][i][3].numpy()) / 2
                    box_color = ImageColor.getrgb(STANDARD_COLORS[((detections['detection_classes'][0].numpy() + label_id_offset).astype(int)[i])% len(STANDARD_COLORS)])
                    box_title = category_index.get((detections['detection_classes'][0][i].numpy() + label_id_offset).astype(int)).get('name')
                    if box_title == TRACKED_NAME:
                        is_found = True
                    saveDetect(box_title, round(yCur*480), round(xCur*640), box_color)
            if not is_found:
                not_found +=1
                print("Selected object not found, refreshing... ", not_found)
            else:
                not_found = 0

            if not_found > 5:
                Overlay.lines.clear()
                self.not_found_signal.emit(1)
            else:
                self.not_found_signal.emit(0)
                for line in Overlay.lines:
                    cv2.line(image_np_with_detections, (line[0],line[1]), (line[2],line[3]), line[4], 3)
                
            cv2.putText(image_np_with_detections , 'KAMISARAU, PO-7, 2022', (20,460), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255,255,255), 1, 2)
            if cv2.waitKey(25) & 0xFF == ord('q'):
                break
            if self.stopvar == 1:
                break
            if ret:
                # https://stackoverflow.com/a/55468544/6622587
                rgbImage = cv2.cvtColor(image_np_with_detections, cv2.COLOR_BGR2RGB)
                h, w, ch = rgbImage.shape
                bytesPerLine = ch * w
                convertToQtFormat = QImage(rgbImage.data, w, h, bytesPerLine, QImage.Format_RGB888)
                p = convertToQtFormat.scaled(640, 480, Qt.KeepAspectRatio)
                self.changePixmap.emit(p)
        cap.release()
        print("finished thread")
        self.stopvar = 0
        

class Placeholder(QLabel):
    def __init__(self, parent):
        super(Placeholder,self).__init__(parent)
        self.i = 0
        self.timer=QTimer()
        self.timer.setInterval(400)
        self.timer.timeout.connect(self.animateText)

    def stopTimer(self):
        QtTest.QTest.qWait(40000)
        self.timer.stop()

    def animateText(self):
        self.i += 1
        self.i = self.i%4
        self.setText("Loading" + ("."*self.i))
        

class App(QWidget):
    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 Video'
        self.left = 100
        self.top = 100
        self.width = 640
        self.height = 500
        self.initUI()

    def notFoundText(self, msg):
        if msg == 0:
            self.labelNotFound.setText("")
        else:
            self.labelNotFound.setText("Selected object not found")

    @pyqtSlot(QImage)
    def setImage(self, image):
        self.label.setPixmap(QPixmap.fromImage(image))

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        self.resize(850, 550)

        self.labelNotFound = QLabel(self)
        self.labelNotFound.setText("")
        self.labelNotFound.setStyleSheet('''QLabel{text-align: center; font-size: 10px; color: red;}''')
        self.labelNotFound.setGeometry(360,520,120,16)

        self.labelExit = QLabel(self)
        self.labelExit.setText("Press to exit")
        self.labelExit.setGeometry(30,420,120,16)
        self.buttonExit = QPushButton(self)
        self.buttonExit.clicked.connect(self.close)
        self.buttonExit.setGeometry(30,440,140,50)
        self.buttonExit.setText("Exit")
        self.buttonExit.show()

        self.labelSelect = QLabel(self)
        self.labelSelect.setText("Select item to track")
        self.labelSelect.setGeometry(30,320,120,16)
        self.selection = QComboBox(self)
        self.selection.setGeometry(30,340,140,50)
        for item in self.listOptions():
            self.selection.addItem(item)
            self.selection.activated[str].connect(self.onChanged)

        self.labelCamera = QLabel(self)
        self.labelCamera.setText("Press to load camera feed")
        self.labelCamera.setGeometry(30,220,140,16)
        self.buttonCamera = QPushButton(self)
        self.buttonCamera.clicked.connect(self.openCamera)
        self.buttonCamera.setGeometry(30,240,140,50)
        self.buttonCamera.setText("Webcam")
        self.buttonCamera.show()

        self.labelFile = QLabel(self)
        self.labelFile.setText("Press to open a video file")
        self.labelFile.setGeometry(30,120,120,16)
        self.buttonFile = QPushButton(self)
        self.buttonFile.clicked.connect(self.openFile)
        self.buttonFile.setGeometry(30,140,140,50)
        self.buttonFile.setText("Video file")
        self.buttonFile.show()

        self.labelStop = QLabel(self)
        self.labelStop.setText("Press to stop everything")
        self.labelStop.setGeometry(30,10,140,16)
        self.buttonStop = QPushButton(self)
        self.buttonStop.clicked.connect(self.stopAll)
        self.buttonStop.setGeometry(30,30,140,50)
        self.buttonStop.setText("Stop")
        self.buttonStop.show()

        self.placeholder = Placeholder(self)
        self.placeholder.setText("Waiting for command")
        self.placeholder.setGeometry(191,11,638,478)
        self.placeholder.setStyleSheet('''QWidget{text-align: center; font-size: 30px; border: 1px solid black;}''')
        self.placeholder.show()
        self.label = QLabel(self)
        self.label.setStyleSheet('''QWidget{border: 1px solid black;}''')
        self.label.move(190, 10)
        self.label.resize(640, 480)
        self.show()

        self.thC = Thread(self)
        self.thC.source = 0
        self.thC.loaded.connect(self.placeholder.stopTimer)
        self.thC.changePixmap.connect(self.setImage)
        self.thC.not_found_signal.connect(self.notFoundText)

        self.thF = Thread(self)
        self.thF.loaded.connect(self.placeholder.stopTimer)
        self.thF.changePixmap.connect(self.setImage)
        self.thF.not_found_signal.connect(self.notFoundText)

    def openFileNameDialog(self):
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        fileName, _ = QFileDialog.getOpenFileName(self,"QFileDialog.getOpenFileName()", "","Video files (*.mp4)", options=options)
        if fileName:
            return fileName

    def openCamera(self):
        self.label.show()
        self.placeholder.timer.start()
        self.thF.stop()
        self.thC.stopvar = 0
        self.thC.start()

    def openFile(self):
        file = self.openFileNameDialog()
        self.thF.source = file
        self.label.show()
        self.placeholder.timer.start()
        self.thC.stop()
        self.thF.stopvar = 0
        self.thF.start()

    def stopAll(self):
        self.placeholder.setText("Waiting for command")
        self.label.hide()
        self.thC.stop()
        self.thF.stop()

    def onChanged(self, text):
        global TRACKED_NAME
        TRACKED_NAME = text
    
    def listOptions(self):
        li = []
        category_index = label_map_util.create_category_index_from_labelmap(PATH_TO_LABELS, use_display_name=True)
        for a in category_index:
            li.append(category_index.get(a).get('name'))
        return li

app = QApplication(sys.argv)
application = App()
app.exec_()