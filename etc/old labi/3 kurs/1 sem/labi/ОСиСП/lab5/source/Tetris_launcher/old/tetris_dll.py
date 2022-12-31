from PyQt5.QtWidgets import QMessageBox, QApplication

def TetrisAboutWindow():
    msgBox = QMessageBox(
                QMessageBox.Information,
                "О программе",
                "Данная программа была сделана в ходе выполнения третьей лабораторной работы по дисциплине ОСиСП (ПО-7, Комиссаров А.Е.)",
                QMessageBox.Ok
                )
    return msgBox

