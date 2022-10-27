#include "texteditor.h"
#include "./ui_texteditor.h"
#include <QTextEdit>
#include <QMessageBox>
#include <QCloseEvent>
#include <QIcon>
#include <QFontDialog>
#include <QFont>
#include <QFile>
#include <QString>
#include <QFileInfo>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <iostream>
#include <stdio.h>

TextEditor::TextEditor(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("Text Editor[*]");
    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    loadFile(fileName);
}

void TextEditor::loadFile(const QString &fileName){
    if (fileName.isEmpty()){
        setFileName(QString());
        return;
    }
    QString fileContents;
    QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        while (!file.atEnd()) {
            QByteArray line = file.readLine();
            fileContents = fileContents + line + "\n";
        }
    ui->textEdit->setText(fileContents);
    file.close();
    setFileName(fileName);
    this->setWindowModified(false);
}

void TextEditor::setFileName(const QString &fileName){
    this->m_fileName = fileName;
    this->setWindowTitle(QString("%1[*] - %2")
                         .arg(m_fileName.isNull()?"untitled":QFileInfo(m_fileName).fileName())
                         .arg(QApplication::applicationName()));
}

bool TextEditor::saveFileAs(){
    QString fileName = QFileDialog::getSaveFileName(this, "Save document", m_fileName.isNull()?QDir::currentPath():m_fileName, "Text documents (*.txt)");
    if(fileName.isNull()){return false;
    }else{setFileName(fileName);
        return saveFile();}
}

bool TextEditor::saveFile(){
    if(this->m_fileName.isNull()){
        return saveFileAs();
    }else{
        QFile file(m_fileName);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.setText("File could not be saved properly, try again.");
                msgBox.exec();
                setFileName(QString());
                return false;
            }else{
                QTextStream out(&file);
                out << ui->textEdit->toPlainText();
                file.close();
                this->setWindowModified(false);
                return true;
            }
    }
}

TextEditor::~TextEditor()
{
    delete ui;
}


void TextEditor::on_actionNew_triggered()
{
    TextEditor *new_editor = new TextEditor;
    new_editor->show();
}


void TextEditor::on_actionClose_triggered()
{
    this->close();
}


void TextEditor::on_actionExit_triggered()
{
    qApp->closeAllWindows();
}

void TextEditor::documentModified(){
    this->setWindowModified(true);
}

void TextEditor::closeEvent(QCloseEvent *e){
    if (this->isWindowModified() == true){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("This document has been modified, do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        switch(ret){
        case QMessageBox::Yes :
            saveFile();
            break;
        case QMessageBox::No :
            e->accept();
            break;
        case QMessageBox::Cancel :
            e->ignore();
            break;
        default :
            e->ignore();
            break;
        }
    }else{
        e->accept();
    }
}


void TextEditor::on_textEdit_textChanged()
{
    this->documentModified();
}


void TextEditor::on_actionSelectFont_triggered()
{
    this->setFont(QFontDialog::getFont(0, this->font()));
}


void TextEditor::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}


void TextEditor::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void TextEditor::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void TextEditor::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void TextEditor::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void TextEditor::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void TextEditor::on_textEdit_copyAvailable(bool b)
{
    ui->actionCopy->setEnabled(b);
    ui->actionCut->setEnabled(b);
}


void TextEditor::on_textEdit_redoAvailable(bool b)
{
    ui->actionRedo->setEnabled(b);
}


void TextEditor::on_textEdit_undoAvailable(bool b)
{
    ui->actionUndo->setEnabled(b);
}


void TextEditor::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Laboratornaya rabota 2 Qt.");
    msgBox.exec();
}


void TextEditor::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open document", QDir::currentPath(), "Text documents (*.txt)");
    if (fileName.isNull()){return;}
    if (!fileName.isNull() && !this->isWindowModified()){
        loadFile(fileName);
    } else {
        TextEditor *new_editor = new TextEditor(fileName);
        new_editor->show();
    }
}


void TextEditor::on_actionSave_triggered()
{
    saveFile();
}


void TextEditor::on_actionSaveAs_triggered()
{
    saveFileAs();
}

