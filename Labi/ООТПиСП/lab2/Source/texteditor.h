#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(const QString &fileName = QString(), QWidget *parent = nullptr);
    ~TextEditor();

private slots:
    bool saveFile();

    bool saveFileAs();

    void on_actionNew_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void documentModified();

    void on_textEdit_textChanged();

    void on_actionSelectFont_triggered();

    void on_actionAboutQt_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_redoAvailable(bool b);

    void on_textEdit_undoAvailable(bool b);

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSaveAs_triggered();

private:
    void loadFile(const QString &fileName);
    void setFileName(const QString &fileName);
    Ui::TextEditor *ui;
    QString m_fileName;
protected:
    void closeEvent(QCloseEvent *e);
};
#endif // TEXTEDITOR_H
