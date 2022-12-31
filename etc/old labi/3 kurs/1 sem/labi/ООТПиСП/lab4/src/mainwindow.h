#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generate_btn_clicked();

    void on_two_degree_btn_clicked();

    void on_three_degree_btn_2_clicked();

private:
    Ui::MainWindow *ui;
    int rows, columns;
    bool is_deg3(const int num);
    bool is_deg2(const int num);

    int two_deg_count = 0;
    int three_deg_count = 0;
};
#endif // MAINWINDOW_H
