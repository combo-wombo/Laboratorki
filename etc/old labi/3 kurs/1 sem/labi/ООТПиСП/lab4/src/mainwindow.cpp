#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rows = ui->tableWidget->rowCount();
    columns = ui->tableWidget->columnCount();

    for(int i = 0; i < rows; i++) {
        ui->tableWidget->setColumnWidth(i, 40);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generate_btn_clicked()
{
    two_deg_count = 0;
    three_deg_count = 0;

    ui->two_res_lbl->setText(QString("Количество чисел, являющихся степенью 2: %1").arg(two_deg_count));
    ui->three_res_lbl->setText(QString("Количество чисел, являющихся степенью 3: %1").arg(three_deg_count));

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int randomValue = QRandomGenerator::global()->bounded(1, 244);
            QTableWidgetItem *theItem = new QTableWidgetItem();
            theItem->setData(Qt::EditRole, randomValue);
            ui->tableWidget->setItem(i, j, theItem);
        }
    }
}


void MainWindow::on_two_degree_btn_clicked()
{
    two_deg_count = 0;

    if (!ui->tableWidget->item(0, 0)) {
        on_generate_btn_clicked();
    }

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            QTableWidgetItem *widgetItem = ui->tableWidget->item(i, j);
            int value = widgetItem->text().toInt();
            if (is_deg2(value)) {
                two_deg_count++;
                widgetItem->setBackground(Qt::darkGreen);
            }
        }
    }

    ui->two_res_lbl->setText(QString("Количество чисел, являющихся степенью 2: %1").arg(two_deg_count));
}


void MainWindow::on_three_degree_btn_2_clicked()
{
    three_deg_count = 0;

    if (!ui->tableWidget->item(0, 0)) {
        on_generate_btn_clicked();
    }

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            QTableWidgetItem *widgetItem = ui->tableWidget->item(i, j);
            int value = widgetItem->text().toInt();
            if (is_deg3(value)) {
                three_deg_count++;
                widgetItem->setBackground(Qt::darkBlue);
            }
        }
    }

    ui->three_res_lbl->setText(QString("Количество чисел, являющихся степенью 3: %1").arg(three_deg_count));
}

bool MainWindow::is_deg3(const int num) {
    int value = num;

    while (value % 3 == 0) {
        value /= 3;
    }

    return value == 1;
}

bool MainWindow::is_deg2(const int num) {
    int value = num;

    while (value % 2 == 0) {
        value /= 2;
    }

    return value == 1;
}
