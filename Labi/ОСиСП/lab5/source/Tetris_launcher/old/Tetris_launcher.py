from PyQt5 import uic, QtTest
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from github import Github
import os
from threading import *
import sys
import tetris
import time as time_module

GLOBAL_UPDATE_PROGRESS = 0

class Thread(QThread):
    _signal = pyqtSignal(int)
    def __init__(self,contents,repo):
        super(Thread, self).__init__()
        self.contents = contents
        self.repo = repo

    def __del__(self):
        self.wait()

    def run(self):
        len1 = len(self.contents) +1
        while self.contents:
            percentage = round((len(self.contents)/len1)*100)
            print("percentage", percentage)
            file_content = self.contents.pop(0)
            self._signal.emit(100-percentage)
            if file_content.type == "dir":
                self.contents.extend(self.repo.get_contents(file_content.path))
            else:
                if(len(file_content.path) > len(file_content.name)):
                    print("Checking " + file_content.path)
                    if not os.path.isdir(file_content.path[:(len(file_content.path) - len(file_content.name))]):
                        print("\"" + file_content.path + "\" does not exist, creating...")
                        os.makedirs(file_content.path[:(len(file_content.path) - len(file_content.name))])
                print("Writing " + file_content.name)
                binary_file = open(file_content.path, "wb")
                if file_content.encoding != 'base64':
                    binary_file.write(b'encoding unsupported')
                    binary_file.close()
                else:
                    binary_file.write(file_content.decoded_content)
                    binary_file.close()
        self._signal.emit(999)

class LauncherWindow(QDialog):
    def __init__(self):
        super(LauncherWindow, self).__init__()
        uic.loadUi("UI/Launcher.ui", self)
        self.show()
        self.buttonLaunch = self.findChild(QPushButton, "LaunchButton")
        self.buttonLaunch.clicked.connect(self.LaunchPress)
        self.buttonUpdate = self.findChild(QPushButton, "CheckUpdatesButton")
        self.buttonUpdate.clicked.connect(self.UpdatePress)
        self.buttonExit = self.findChild(QPushButton, "ExitButton")
        self.buttonExit.clicked.connect(self.ExitPress)
        self.versionText = self.findChild(QLabel, "VersionText")
        self.versionText.setText("ver. " + self.getLocalVersion())
        self.keepSoundAwake = QTimer()
        self.keepSoundAwake.setInterval(2700)
        self.keepSoundAwake.start() 

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
            diff_h = (height - self.height())/9
            diff_w = (width - self.width())/9
            i+=1
            offset_w = old_w - self.width()
            offset_h = old_h - self.height()
            new_x = round(x + (offset_w/2))
            new_y = round(y + (offset_h/2))
            self.move(new_x, new_y)

            if(prevW != diff_w or prevH != diff_h):
                prevW = diff_w
                prevH = diff_h
                self.setFixedHeight(round(self.height() + diff_h))
                self.setFixedWidth( round(self.width() + diff_w))
            else:
                self.move(end_x, end_y)
                self.setFixedHeight(height)
                self.setFixedWidth(width)
                break
            QtTest.QTest.qWait(tick_duration)
        
            
    def showLauncher(self):
        self.show()
        self.game.hide()
        self.transformToSize(630, 360)

    #Launch button is pressed
    def LaunchPress(self):
        self.transformToSize(360, 480)
        self.hide()
        self.game = tetris.launchGame()
        self.game.closed.connect(self.showLauncher)

    #Update button is pressed
    def UpdatePress(self):
        self.Update()

    #Exit button is pressed
    def ExitPress(self):
        app.quit()

    def getLocalVersion(self):
        try:
            version_file = open("version.txt")
            version = version_file.readline()
            return version
        except OSError:
            print("could not open file")
            return None

    def getRemoteVersion(self):
        repo = self.githubInstance.get_repo(self.repository)
        return repo.get_contents("version.txt").decoded_content.decode()


    def Authenticate(self,token):
        g = Github(token)
        print("Authenticated as " + g.get_user().name)
        return g

    def noUpdateNeeded(self):
        print("No update needed.")
        self.updateNotFound = QMessageBox(
            QMessageBox.Information, "No update needed",
            "You are already running the latest version, no need to update.",
            (QMessageBox.Ok)
            )
        self.updateNotFound.exec()

    def showUpdateConfirm(self,lcVersion, rmVersion):
        '''
        Asks the user if he wants to update.
        '''
        self.updateConfirm = QMessageBox(
            QMessageBox.Information, "Update detected",
            "A new update has been detected. Your local version is " + lcVersion + ". Are you willing to update your game version to " + rmVersion + "?",
            (QMessageBox.Yes | QMessageBox.No)
            )
        return self.updateConfirm.exec()

    def Update(self):
        self.access_token = "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"
        self.repository = "combo-wombo/OSiSP_Lab4"
        self.githubInstance = self.Authenticate(self.access_token)
        self.repo = self.githubInstance.get_repo(self.repository)
        self.contents = self.repo.get_contents("")
        local = self.getLocalVersion()
        remote = self.getRemoteVersion()
        if(local < remote):
            print("Update detected (local : " + local + ", remote : " + remote + ").")
            if(self.showUpdateConfirm(local, remote) == QMessageBox.Yes):
                self.updProg = QWidget()
                self.updProg.setWindowTitle('QProgressBar')
                self.updProg.pbar = QProgressBar(self.updProg)
                self.updProg.pbar.setValue(0)
                self.updProg.resize(300, 100)
                self.updProg.vbox = QVBoxLayout()
                self.updProg.vbox.addWidget(self.updProg.pbar)
                self.updProg.setLayout(self.updProg.vbox)
                self.updProg.show()
                self.updProg.pbar.show()
                self.thread = Thread(self.contents,self.repo)
                self.thread._signal.connect(self.signal_accept)
                self.thread.start()
        else:
            self.noUpdateNeeded()

    def signal_accept(self, msg):
        msg = int(msg)
        print("received",msg)
        if msg == 999:
            self.versionText.setText("ver. " + self.getLocalVersion())
            self.updProg.close()
            self.updProg = QMessageBox(
                QMessageBox.Information, "App updated",
                "The app has been updated to the latest version.",
                (QMessageBox.Ok)
                )
            self.updProg.exec()
        else:
            if self.updProg.pbar.value() > 99:
                self.updProg.pbar.setValue(100)
            else:
                self.updProg.pbar.setValue(msg)
            

#=================================##=================================#

app = QApplication(sys.argv)
launcher = LauncherWindow()
app.exec_()

#=================================##=================================#
