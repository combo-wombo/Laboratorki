#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QTableView>

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

    void on_connect_btn_clicked();

    void on_add_seller_clicked();

    void on_add_product_clicked();

    void on_query_select_currentIndexChanged(int index);

    void on_execute_query_btn_clicked();

    void on_remove_product_clicked();

    void on_remove_seller_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *sellerModel;
    QSqlTableModel *productModel;
    QSqlDatabase db;

    void updateTypes();
    void updateSellerIds();
};
#endif // MAINWINDOW_H
