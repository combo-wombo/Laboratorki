from PyQt5.QtWidgets import *
from PyQt5.QtCore import pyqtSignal, QTimer, Qt
from PyQt5.QtGui import QPainter, QColor
from PyQt5 import uic, QtGui, QtCore
from PyQt5 import QtTest
import random
import keyboard
        
#=====SHAPES===================================================================================================
                                     
S = [['.....',  '.....',    '..00.',    '.00..',    '.....'],   ['.....',   '..0..',    '..00.',    '...0.',    '.....']]
Z = [['.....',  '.....',    '.00..',    '..00.',    '.....'],   ['.....',   '..0..',    '.00..',    '.0...',    '.....']]
I = [['..0..',  '..0..',    '..0..',    '..0..',    '.....'],   ['.....',   '.....',    '0000.',    '.....',    '.....'],  
     ['.....',  '..0..',    '..0..',    '..0..',    '..0..'],   ['.....',   '.....',    '.0000',    '.....',    '.....']]
O = [['.....',  '.....',    '.00..',    '.00..',    '.....']]
J = [['.....',  '.0...',    '.000.',    '.....',    '.....'],   ['.....',   '..00.',    '..0..',    '..0..',    '.....'],
     ['.....',  '.....',    '.000.',    '...0.',    '.....'],   ['.....',   '..0..',    '..0..',    '.00..',    '.....']]

shapes = [S, Z, I, O, J]
shape_colors = [1,2,3,4,5]

#=====TETRIS FUNCTIONS=========================================================================================

class Figure(object):
    def __init__(self, x, y, shape):
        self.x = x
        self.y = y
        self.shape = shape
        self.color = shape_colors[shapes.index(shape)]
        self.rotation = 0

def createField(locked_pos={}):
    board = [[0 for _ in range(15)] for _ in range(20)]

    for i in range(len(board)):
        for j in range(len(board[i])):
            if (j, i) in locked_pos:
                c = locked_pos[(j, i)]
                board[i][j] = c
    return board

def getShape():
    return Figure(7, 1, random.choice(shapes))

def convertShapeFormat(shape):
    positions = []
    format = shape.shape[shape.rotation % len(shape.shape)]
    for i, line in enumerate(format):
        row = list(line)
        for j, column in enumerate(row):
            if column == '0':
                positions.append((shape.x + j , shape.y + i))

    for i, pos in enumerate(positions):
        positions[i] = (pos[0] - 2, pos[1] - 4)
    return positions

def validSpace(shape, board):
    accepted_pos = [[(j, i) for j in range(15) if board[i][j] == 0] for i in range(20)]
    accepted_pos = [j for sub in accepted_pos for j in sub]

    formatted = convertShapeFormat(shape)

    for pos in formatted:
        if pos not in accepted_pos:
            if pos[1] > -1:
                return False
    return True

def checkLost(positions):
    for pos in positions:
        x, y = pos
        if y < 1:
            return True
    return False

def tryRotate(current_piece, board):
    current_piece.rotation += 1
    if not (validSpace(current_piece, board)):
        current_piece.rotation -= 1

def tryMoveLeft(current_piece, board):
    current_piece.x -= 1
    if not (validSpace(current_piece, board)):
        current_piece.x += 1

def tryMoveRight(current_piece, board):
    current_piece.x += 1
    if not (validSpace(current_piece, board)):
        current_piece.x -= 1

def tryMoveDown(current_piece, board):
    current_piece.y += 1
    snd = 1
    if not (validSpace(current_piece, board)):
        snd = 0
        current_piece.y -= 1

def clearRows(info, board, locked, self):
    inc = 0
    for i in range(len(board)-1, -1, -1):
        row = board[i]
        if 0 not in row:
            inc += 1
            ind = i
            for j in range(len(row)):
                try:
                    del locked[(j,i)]
                except:
                    continue
    if inc > 0:
        for key in sorted(list(locked), key = lambda x: x[1])[::-1]:
            x, y = key
            if y < ind:
                newKey = (x, y + inc)
                locked[newKey] = locked.pop(key)
    score_map = {
        0: 0, 
        1: 40,
        2: 100,
        3: 300,
        4: 1200
    }   
    info.score += score_map[inc]
    self.scoreText.setText("Score : " + str(info.score))

def checkLevel(time):
    time = time // 20
    level = 6
    if time < 60:
        level = 6
    elif time < 120:
        level = 5
    elif time < 180:
        level = 4
    elif time < 360:
        level = 3
    elif time < 600:
        level = 2
    else: 
        level = 1
    return level

#=====QT CLASSES===============================================================================================

class PlayWindow(QDialog):
    closed = pyqtSignal()   
    def __init__(self, info):
        self.needsReset = 0
        super(PlayWindow, self).__init__()
        uic.loadUi("UI/PlayWindow.ui", self)
        self.pause = 1
        self.buttonExit = self.findChild(QPushButton, "ExitButton")
        self.tableWidget = self.findChild(QTableWidget, "PlayTable")
        self.figureWidget = self.findChild(QTableWidget, "FigureWindow")
        self.buttonPause = self.findChild(QPushButton, "PauseButton")
        self.timeText = self.findChild(QLabel, "TimeText")
        self.timestr = "Time passed : "
        self.scoreText = self.findChild(QLabel, "ScoreText")
        self.buttonPause.clicked.connect(self.PauseGame)
        self.buttonExit.clicked.connect(self.ExitB)
        self.tableWidget.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.tableWidget.verticalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.figureWidget.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.figureWidget.verticalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.gameTimer = QTimer()
        self.gameTimer.setInterval(50)
        self.gameTimer.timeout.connect(lambda: self.GameStateUpdate(info))
        self.time = 0
    
    def GameStateUpdate(self, info):
        if(self.needsReset == 1):
            self.time = 0
            self.pause = 0
            self.PauseGame()
            self.gameTimer.stop()
            info.reset()
            for y in range(20):
                for x in range(15):
                    self.tableWidget.setItem(y, x, QTableWidgetItem(None))
            for y in range(5):
                for x in range(5):
                    self.figureWidget.setItem(y, x, QTableWidgetItem(None))
            self.buttonPause.setEnabled(True)
            self.buttonPause.setStyleSheet("""
                    QPushButton {
                    background-color: rgba(255, 255, 255, 0);
                    border: 0;
                    color: rgb(150, 150, 150);
                    }
                    QPushButton:hover{
                    background-color: rgba(255, 255, 255, 45);
                    color: rgb(255,255,255);
                    }
            """)
            self.buttonPause.setText("Start")
            self.scoreText.setText("Score : ")
            self.timeText.setText(self.timestr)
            self.needsReset = 0

        if(self.pause != 1):
            print("update : ", self.time)
            info.board = createField(info.locked_positions)
            
            level = checkLevel(self.time)

            if (self.time % level == 0) :
                info.current_piece.y += 1 

            if not(validSpace(info.current_piece, info.board)) and info.current_piece.y > 0:
                info.current_piece.y -= 1
                info.change_piece = True

            if keyboard.is_pressed('w') or keyboard.is_pressed('up'):
                if (self.time % 2 == 0) : tryRotate(info.current_piece, info.board)
            if keyboard.is_pressed('s') or keyboard.is_pressed('down'):
                tryMoveDown(info.current_piece, info.board)
            if keyboard.is_pressed('a') or keyboard.is_pressed('left'):
                tryMoveLeft(info.current_piece, info.board)
            if keyboard.is_pressed('d') or keyboard.is_pressed('right'):
                tryMoveRight(info.current_piece, info.board)
            if keyboard.is_pressed('p'):
                self.time+=400

            self.time += 1
            self.timeText.setText(self.timestr + str(self.time//20) + "s")

            shape_pos = convertShapeFormat(info.current_piece)
            for i in range(len(shape_pos)):
                x, y = shape_pos[i]
                if y > -1:
                    info.board[y][x] = info.current_piece.color
            
            if info.change_piece:
                for pos in shape_pos:
                    p = (pos[0], pos[1])
                    info.locked_positions[p] = info.current_piece.color
                info.current_piece = info.next_piece
                info.next_piece = getShape()
                info.change_piece = False
                clearRows(info, info.board, info.locked_positions, self)

            if checkLost(info.locked_positions):
                self.timeText.setText("Game Over!")
                self.PauseGame()
                self.buttonPause.setEnabled(False)
                self.buttonPause.setStyleSheet("""
                    QPushButton {
                    background-color: rgba(255, 150, 150, 45);
                    border: 0;
                    color: rgb(20, 20, 20);
                    }
                    QPushButton:hover{
                    background-color: rgba(255, 150, 150, 65);
                    color: rgb(20,20,20);
                    }
                """)
                self.leadb = Leaderboard(info, 6-level)
                self.leadb.closed.connect(self.close)
                self.leadb.show()

            
            self.UpdateCell(info.board)
            self.UpdateFigure(info.next_piece)

        else: 
            print("update : ", self.time, " (paused)")

    def UpdateCell(self, board):
        for y in range(20):
            for x in range(15):
                item = board[y][x]
                tableWidgetItem = QTableWidgetItem(str(item))
                self.tableWidget.setItem(y, x, tableWidgetItem)
                if(self.tableWidget.item(y,x).text() == '0'):blockColor = QtGui.QColor(0,0,0)       #Black
                if(self.tableWidget.item(y,x).text() == '1'):blockColor = QtGui.QColor(255,0,0)     
                if(self.tableWidget.item(y,x).text() == '2'):blockColor = QtGui.QColor(0,255,0)     
                if(self.tableWidget.item(y,x).text() == '3'):blockColor = QtGui.QColor(0,0,255)     
                if(self.tableWidget.item(y,x).text() == '4'):blockColor = QtGui.QColor(255,255,0)   
                if(self.tableWidget.item(y,x).text() == '5'):blockColor = QtGui.QColor(255,0,255)   
                if(self.tableWidget.item(y,x).text() == '6'):blockColor = QtGui.QColor(0,255,255)   
                if(self.tableWidget.item(y,x).text() == '7'):blockColor = QtGui.QColor(255,255,255) 
                self.tableWidget.item(y, x).setBackground(blockColor)

    def UpdateFigure(self, shape):
        for y in range(5):
            for x in range(5):
                self.figureWidget.setItem(y, x, QTableWidgetItem(str('.')))
        if(shape.color == 1):blockColor = QtGui.QColor(255,0,0)     
        if(shape.color == 2):blockColor = QtGui.QColor(0,255,0)     
        if(shape.color == 3):blockColor = QtGui.QColor(0,0,255)     
        if(shape.color == 4):blockColor = QtGui.QColor(255,255,0)   
        if(shape.color == 5):blockColor = QtGui.QColor(255,0,255)   
        if(shape.color == 6):blockColor = QtGui.QColor(0,255,255)   
        if(shape.color == 7):blockColor = QtGui.QColor(255,255,255) 
        format = shape.shape[shape.rotation % len(shape.shape)]
        for i, line in enumerate(format):
            row = list(line)
            for j, column in enumerate(row):
                if column == '.':
                    self.figureWidget.item(i, j).setBackground(QtGui.QColor(0,0,0))
                if column == '0':
                    self.figureWidget.item(i, j).setBackground(blockColor)
                        
    def PauseGame(self):
         
        #---------#is paused
        if(self.pause):
            self.buttonPause.setStyleSheet("""
                    QPushButton {
                    background-color: rgba(255, 255, 255, 45);
                    color: rgb(255,255,255);
                    border: 0;
                    }
                    QPushButton:hover{
                    background-color: rgba(255, 255, 255, 65);
                    color: rgb(255,255,255);
                    }
            """)
            self.buttonPause.setText("Pause")
            self.pause = 0
            self.gameTimer.start()
        #---------#is unpaused
        else:
            self.buttonPause.setStyleSheet("""
                    QPushButton {
                    background-color: rgba(255, 255, 255, 0);
                    border: 0;
                    color: rgb(150, 150, 150);
                    }
                    QPushButton:hover{
                    background-color: rgba(255, 255, 255, 45);
                    color: rgb(255,255,255);
                    }
            """)
            self.buttonPause.setText("Start")
            self.pause = 1

    def ExitB(self):
         
        self.close()

    def closeEvent(self, event):
        self.needsReset = 1
        self.closed.emit()
        QDialog.closeEvent(self, event)

#==============================================================================================================

class Leaderboard(QDialog):
    closed = pyqtSignal()
    def __init__(self, info, level):
        super(Leaderboard, self).__init__()
        uic.loadUi("UI/Leaderboard.ui", self)
        #------------
        self.buttonClose = self.findChild(QPushButton, "CloseButton")
        self.buttonClose.clicked.connect(self.CloseWindow)
        self.scoreText = self.findChild(QLabel, "ScoreText")
        self.levelText = self.findChild(QLabel, "LevelText")
        #------------
        self.scoreText.setText("Score : " + str(info.score))
        self.levelText.setText("Level : " + str(level))

    def CloseWindow(self):
        self.close()
         

    def closeEvent(self, event):
        self.closed.emit()
        QDialog.closeEvent(self, event)

#==============================================================================================================
                                                         
class StartWindow(QDialog):
    closed = pyqtSignal()   #signal attribute for parent window
    def __init__(self, info):
        super(StartWindow, self).__init__()
        uic.loadUi("UI/Title.ui", self)
        self.show()
        #------------
        self.info = info
        self.buttonStart = self.findChild(QPushButton, "StartButton")
        self.buttonStart.clicked.connect(self.StartB)
        self.buttonExit = self.findChild(QPushButton, "ExitButton")
        self.buttonExit.clicked.connect(self.ExitB)
        self.buttonAbout = self.findChild(QPushButton, "AboutButton")
        self.buttonAbout.clicked.connect(self.AboutB)
        
        #------------
        self.mainw = PlayWindow(info)       #create playwindow child
        self.mainw.closed.connect(self.showStart) #show title when closing playwindow

    def showStart(self):
        
        self.show()
        self.mainw.hide()
        self.transformToSize(360, 480)

    #Start button is pressed
    def StartB(self):
        self.transformToSize(640, 480)
        self.hide()
        
        self.mainw.show()

    def transformToSize(self, width, height):
        old_h = self.height()
        old_w = self.width()
        end_x = round(self.x() + ((self.width() - width)/2))
        end_y = round(self.y() + ((self.height() - height)/2))
        tick_duration = 10 #default = 10
        prevH = 9999
        prevW = 9999
        x = self.x()
        y = self.y()
        i = 0
        while not (self.height() == height and self.width() == width):
            i+=1
            curr_h = self.height()
            curr_w = self.width()
            diff_h = (height - curr_h) / 8
            diff_w = (width - curr_w) / 8

            offset_w = old_w - curr_w
            offset_h = old_h - curr_h
            new_x = round(x + (offset_w/2))
            new_y = round(y + (offset_h/2))
            self.move(new_x, new_y)

            if(prevW != diff_w or prevH != diff_h):
                prevW = diff_w
                prevH = diff_h
                self.setFixedHeight(round(curr_h + diff_h))
                self.setFixedWidth( round(curr_w + diff_w))
            else:
                self.move(end_x, end_y)
                self.setFixedHeight(height)
                self.setFixedWidth(width)
                break
            QtTest.QTest.qWait(tick_duration)

    #About button is pressed
    def AboutB(self):
        self.msgBox = tetris_dll.TetrisAboutWindow()
        self.msgBox.show()

    #Exit button is pressed
    def ExitB(self):
        self.close()

    def closeEvent(self, event):
        
        self.closed.emit()
        QDialog.closeEvent(self, event)

#==============================================================================================================

class GameInfo():
    def __init__(self, locked_positions, board, change_piece, current_piece, next_piece, score):
        self.locked_positions = locked_positions
        self.board = board
        self.change_piece = change_piece
        self.current_piece = current_piece
        self.next_piece = next_piece
        self.score = score
    def reset(self):
        self.locked_positions = {}
        self.board = createField(self.locked_positions)
        self.change_piece = False
        self.current_piece = getShape()
        self.next_piece = getShape()
        self.score = 0

#==============================================================================================================

def launchGame():
    locked_positions = {}
    board = createField(locked_positions)
    change_piece = False
    current_piece = getShape()
    next_piece = getShape()
    score = 0
    info = GameInfo(locked_positions, board, change_piece, current_piece, next_piece, score)
    UIWindow = StartWindow(info)
    return UIWindow
