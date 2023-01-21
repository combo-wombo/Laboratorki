#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->products_table_view->resizeColumnsToContents();
    ui->sellers_table_view->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTypes() {
    ui->type_select->clear();
    for (int i = 0; i < productModel->rowCount(); i++) {
        QString typeValue = productModel->record(i).value("type").toString();
        ui->type_select->addItem(typeValue);
    }
}

void MainWindow::updateSellerIds() {
    ui->seller_id_combobox->clear();
    for (int i = 0; i < sellerModel->rowCount(); i++) {
        QString sellerIdValue = sellerModel->record(i).value("id").toString();
        ui->seller_id_combobox->addItem(sellerIdValue);
    }
}

void MainWindow::on_connect_btn_clicked()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydata.sqlite");
    bool ok = db.open();

    if (!ok) {
        ui->connection_lbl->setText("Connection state: Something went wrong");
        ui->connection_lbl->setStyleSheet("color: red;");
        return;
    }

    ui->connection_lbl->setText("Connection state: Connected...");
    ui->connection_lbl->setStyleSheet("color: green;");

    sellerModel = new QSqlTableModel();

    sellerModel->setTable("seller");
    sellerModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    sellerModel->select();

    ui->sellers_table_view->setModel(sellerModel);

    productModel = new QSqlTableModel();

    productModel->setTable("product");
    productModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    productModel->select();

    ui->products_table_view->setModel(productModel);

    ui->tabWidget->setEnabled(true);
    ui->connect_btn->setDisabled(true);

    updateTypes();
    updateSellerIds();
}

void MainWindow::on_add_seller_clicked()
{
    QString name = ui->name_edit->text();
    QString surname = ui->surname_edit->text();
    QString patronymic = ui->patronymic_edit->text();

    QSqlRecord newRecord = sellerModel->record();

    newRecord.remove(newRecord.indexOf("id"));
    newRecord.setValue("name", name);
    newRecord.setValue("surname", surname);
    newRecord.setValue("patronymic", patronymic);

    if(sellerModel->insertRecord(-1, newRecord)){
        sellerModel->submitAll();
    } else{
        db.rollback();
    }

    updateSellerIds();

    ui->name_edit->clear();
    ui->surname_edit->clear();
    ui->patronymic_edit->clear();
    ui->name_edit->setFocus();
}


void MainWindow::on_add_product_clicked()
{
    QString type = ui->type_edit->text();
    int price = ui->price_edit->text().toInt();
    int quantity = ui->quantity_edit->text().toInt();
    int sellerId = ui->seller_id_combobox->currentText().toInt();

    QSqlRecord newRecord = productModel->record();

    newRecord.remove(newRecord.indexOf("id"));
    newRecord.setValue("type", type);
    newRecord.setValue("price", price);
    newRecord.setValue("quantity", quantity);
    newRecord.setValue("seller_id", sellerId);

    if(productModel->insertRecord(-1, newRecord)){
        productModel->submitAll();
    } else{
        db.rollback();
    }

    updateTypes();

    ui->type_edit->clear();
    ui->price_edit->clear();
    ui->quantity_edit->clear();
}


void MainWindow::on_query_select_currentIndexChanged(int index)
{
    if (index == 0) {
        ui->type_select->setEnabled(true);
    } else {
        ui->type_select->setEnabled(false);
    }
}


void MainWindow::on_execute_query_btn_clicked()
{
    QSqlQuery query;
    ui->accounting_table->setRowCount(0);

    if (ui->query_select->currentIndex() == 1) {
        QStringList headers = QStringList() << "id" << "Name" << "Surname" << "Patronymic" << "Total Sum";

        ui->accounting_table->setColumnCount(5);
        ui->accounting_table->setShowGrid(true);
        ui->accounting_table->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->accounting_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->accounting_table->setHorizontalHeaderLabels(headers);

        query.clear();
        query.exec("select s.id, s.name, s.surname, s.patronymic, SUM(p.price * p.quantity) as total_sum from seller s "
                   "inner join product p on s.id = p.seller_id "
                   "group by s.name "
                   "order by s.id;");
        for(int i = 0; query.next(); i++){

            QString id = query.value(0).toString();
            QString name = query.value(1).toString();
            QString surname = query.value(2).toString();
            QString patronymic = query.value(3).toString();
            QString total_sum = query.value(4).toString();

            ui->accounting_table->insertRow(i);

            ui->accounting_table->setItem(i, 0, new QTableWidgetItem(id));
            ui->accounting_table->setItem(i, 1, new QTableWidgetItem(name));
            ui->accounting_table->setItem(i, 2, new QTableWidgetItem(surname));
            ui->accounting_table->setItem(i, 3, new QTableWidgetItem(patronymic));
            ui->accounting_table->setItem(i, 4, new QTableWidgetItem(total_sum));
        }

        ui->accounting_table->resizeColumnsToContents();
    } else if (ui->query_select->currentIndex() == 0) {
        QString type = ui->type_select->currentText();

        QStringList headers = QStringList() << "id" << "Name" << "Surname" << "Patronymic" << "Type";

        ui->accounting_table->setColumnCount(5);
        ui->accounting_table->setShowGrid(true);
        ui->accounting_table->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->accounting_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->accounting_table->setHorizontalHeaderLabels(headers);

        query.clear();
        query.exec(QString("select s.id, s.name, s.surname, s.patronymic, p.type from seller s "
                           "left join product p on p.seller_id = s.id "
                           "where p.type = '%1';").arg(type));

        for(int i = 0; query.next(); i++){

            QString id = query.value(0).toString();
            QString name = query.value(1).toString();
            QString surname = query.value(2).toString();
            QString patronymic = query.value(3).toString();
            QString type = query.value(4).toString();

            qDebug() << name;

            ui->accounting_table->insertRow(i);

            ui->accounting_table->setItem(i, 0, new QTableWidgetItem(id));
            ui->accounting_table->setItem(i, 1, new QTableWidgetItem(name));
            ui->accounting_table->setItem(i, 2, new QTableWidgetItem(surname));
            ui->accounting_table->setItem(i, 3, new QTableWidgetItem(patronymic));
            ui->accounting_table->setItem(i, 4, new QTableWidgetItem(type));
        }

        ui->accounting_table->resizeColumnsToContents();
    }
}


void MainWindow::on_remove_product_clicked()
{
    int row = ui->products_table_view->currentIndex().row();

    if(productModel->removeRows(row, 1)) {
        productModel->submitAll();
        updateTypes();
    } else{
        db.rollback();
    }
}


void MainWindow::on_remove_seller_clicked()
{
    int row = ui->sellers_table_view->currentIndex().row();

    if(sellerModel->removeRows(row, 1)) {
        sellerModel->submitAll();
        updateSellerIds();
    } else{
        db.rollback();
    }
}

