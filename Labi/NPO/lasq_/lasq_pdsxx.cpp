#include "lasq_pdsxx.h"
#include "ui_lasq_pdsxx.h"

#include <QDebug>

lasq_pdsxx::lasq_pdsxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_pdsxx)
{
    ui->setupUi(this);
    connect(ui->lasq_pdsxx_grid_c, SIGNAL(clicked()), this, SLOT(lasq_pdsxx_grid_cClick()));
    connect(ui->lasq_pdsxx_back_c, SIGNAL(clicked()), this, SLOT(lasq_pdsxx_back_cClick()));
    connect(ui->lasq_pdsxx_next_c, SIGNAL(clicked()), this, SLOT(lasq_pdsxx_next_cClick()));
    connect(ui->lasq_pdsxx_exit_c, SIGNAL(clicked()), this, SLOT(lasq_pdsxx_exit_cClick()));
    connect(ui->lasq_pdsxx_add_c, SIGNAL(clicked()), this, SLOT(lasq_pdsxx_add_cClick()));
    connect(ui->lasq_pdsxx_del_c, SIGNAL(clicked()), this, SLOT(lasq_pdsxx_del_cClick()));
    connect(ui->lasq_pdsxx_pdtrj_c, SIGNAL(clicked()), this, SLOT(lasq_pdsxx_pdtrj_cClick()));
    connect(ui->lasq_pdsxx_to_c, SIGNAL(clicked()), this, SLOT(lasq_pdsxx_to_cClick()));

    connect(ui->lasq_pdsxx_dbn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_pdsxx_dbn_eTextChanged(QString)));
    connect(ui->lasq_pdsxx_db_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_pdsxx_db_eTextChanged(QString)));
    connect(ui->lasq_pdsxx_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_pdsxx_dokk_eTextChanged(QString)));
    connect(ui->lasq_pdsxx_dokn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_pdsxx_dokn_eTextChanged(QString)));
    connect(ui->lasq_pdsxx_dokd_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_pdsxx_dokd_eTextChanged(QString)));
    connect(ui->lasq_pdsxx_rub_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_pdsxx_rub_eTextChanged(QString)));
    connect(ui->lasq_pdsxx_kr_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_pdsxx_kr_eTextChanged(QString)));
    connect(ui->lasq_pdsxx_to_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_pdsxx_to_eTextChanged(QString)));
    connect(ui->lasq_pdsxx_krn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_pdsxx_krn_eTextChanged(QString)));
    connect(ui->lasq_pdsxx_sae_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_pdsxx_sae_eTextChanged(QString)));

    ui->lasq_pdsxx_to_e->setStyleSheet("color: red;");
    ui->lasq_pdsxx_sae_e->setStyleSheet("color: red;");
    ui->lasq_pdsxx_dbn_e->setStyleSheet("color: red;");
    ui->lasq_pdsxx_db_e->setStyleSheet("color: red;");
    ui->lasq_pdsxx_kr_e->setStyleSheet("color: red;");
    ui->lasq_pdsxx_db_l->setStyleSheet("color: red;");
    ui->lasq_pdsxx_kr_l->setStyleSheet("color: red;");
    ui->lasq_pdsxx_sae_l->setStyleSheet("color: red;");
    ui->lasq_pdsxx_krn_e->setStyleSheet("color: red;");

    model.setTable("lasq_pd");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);
}

lasq_pdsxx::~lasq_pdsxx()
{
    delete ui;
}

void lasq_pdsxx::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString lasq_pd_db = model.record(currentIndex).value("lasq_pd_db").toString();
        QString lasq_pd_dbn = model.record(currentIndex).value("lasq_pd_dbn").toString();
        QString lasq_pd_dokk = model.record(currentIndex).value("lasq_pd_dokk").toString();
        QString lasq_pd_dokd = model.record(currentIndex).value("lasq_pd_dokd").toString();
        QString lasq_pd_dokn = model.record(currentIndex).value("lasq_pd_dokn").toString();
        QString lasq_pd_kr = model.record(currentIndex).value("lasq_pd_kr").toString();
        QString lasq_pd_krn = model.record(currentIndex).value("lasq_pd_krn").toString();
        QString lasq_pd_sae = model.record(currentIndex).value("lasq_pd_sae").toString();
        QString lasq_pd_rub = model.record(currentIndex).value("lasq_pd_rub").toString();
        QString lasq_pd_to = model.record(currentIndex).value("lasq_pd_to").toString();
        ui->lasq_pdsxx_db_e->setText(lasq_pd_db);
        ui->lasq_pdsxx_dbn_e->setText(lasq_pd_dbn);
        ui->lasq_pdsxx_dokk_e->setText(lasq_pd_dokk);
        ui->lasq_pdsxx_dokn_e->setText(lasq_pd_dokn);
        ui->lasq_pdsxx_dokd_e->setText(lasq_pd_dokd);
        ui->lasq_pdsxx_kr_e->setText(lasq_pd_kr);
        ui->lasq_pdsxx_krn_e->setText(lasq_pd_krn);
        ui->lasq_pdsxx_sae_e->setText(lasq_pd_sae);
        ui->lasq_pdsxx_rub_e->setText(lasq_pd_rub);
        ui->lasq_pdsxx_to_e->setText(lasq_pd_to);
    }
}

void lasq_pdsxx::lasq_pdsxx_grid_cClick() {
   lasq_xxsgrid* lasq_xxsgrid1 = new lasq_xxsgrid(this, &model, currentIndex);
   lasq_xxsgrid1->setWindowTitle("lasq_pdsxx  viberi dokument");
   lasq_xxsgrid1->exec();
   changeEdits(lasq_xxsgrid1->currentIndex);
}

void lasq_pdsxx::lasq_pdsxx_back_cClick() {
    changeEdits(currentIndex - 1);
}

void lasq_pdsxx::lasq_pdsxx_next_cClick() {
    changeEdits(currentIndex + 1);
}

void lasq_pdsxx::lasq_pdsxx_exit_cClick() {
    QDialog::reject();
}

void lasq_pdsxx::lasq_pdsxx_add_cClick() {
    model.insertRow(size);
    model.setData(model.index(size,0), 0);
    if(model.submitAll()) {
        model.database().commit();
    } else {
        model.database().rollback();
                qDebug() << "Database Write Error" <<
                     "The database reported an error: " <<
                       model.lastError().text();

    }
    size++;
    changeEdits(size - 1);
}

void lasq_pdsxx::lasq_pdsxx_del_cClick() {
    model.removeRow(currentIndex);
    if(model.submitAll()) {
        model.database().commit();
    } else {
        model.database().rollback();
                qDebug() << "Database Write Error" <<
                     "The database reported an error: " <<
                       model.lastError().text();

    }
    size--;
    model.select();
    changeEdits(currentIndex - 1);
}

void lasq_pdsxx::lasq_pdsxx_pdtrj_cClick() {
    QSqlQuery query;
    query.prepare("INSERT INTO lasq_rj VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue("0");
    query.addBindValue(ui->lasq_pdsxx_dokd_e->text());
    query.addBindValue(ui->lasq_pdsxx_dokk_e->text());
    query.addBindValue(ui->lasq_pdsxx_dokn_e->text().toInt());
    query.addBindValue(ui->lasq_pdsxx_dokd_e->text());
    query.addBindValue(ui->lasq_pdsxx_to_e->text());
    query.addBindValue(ui->lasq_pdsxx_db_e->text().toInt());
    query.addBindValue(ui->lasq_pdsxx_dbn_e->text());
    query.addBindValue(ui->lasq_pdsxx_kr_e->text().toInt());
    query.addBindValue(ui->lasq_pdsxx_krn_e->text());
    query.addBindValue(ui->lasq_pdsxx_rub_e->text().toInt());
    query.addBindValue(ui->lasq_pdsxx_sae_e->text());
    query.exec();
}

void lasq_pdsxx::lasq_pdsxx_to_cClick() {
    lasq_togxx* lasq_togxx1 = new lasq_togxx(this);
    lasq_togxx1->setWindowTitle("lasq_pdsxx  viberi operaciu");
    lasq_togxx1->exec();
    ui->lasq_pdsxx_db_e->setText(lasq_togxx1->lasq_to_db);
    ui->lasq_pdsxx_dbn_e->setText(lasq_togxx1->lasq_to_dbn);
    ui->lasq_pdsxx_kr_e->setText(lasq_togxx1->lasq_to_kr);
    ui->lasq_pdsxx_krn_e->setText(lasq_togxx1->lasq_to_krn);
    ui->lasq_pdsxx_sae_e->setText(lasq_togxx1->lasq_to_sae);
    ui->lasq_pdsxx_to_e->setText(lasq_togxx1->lasq_to_k);
}

void lasq_pdsxx::lasq_pdsxx_db_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_pd_db")), text);
}

void lasq_pdsxx::lasq_pdsxx_dbn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_pd_dbn")), text);
}

void lasq_pdsxx::lasq_pdsxx_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_pd_dokk")), text);
}

void lasq_pdsxx::lasq_pdsxx_dokd_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_pd_dokd")), text);
}

void lasq_pdsxx::lasq_pdsxx_dokn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_pd_dokn")), text);
}

void lasq_pdsxx::lasq_pdsxx_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_pd_kr")), text);
}

void lasq_pdsxx::lasq_pdsxx_krn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_pd_krn")), text);
}

void lasq_pdsxx::lasq_pdsxx_sae_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_pd_sae")), text);
}

void lasq_pdsxx::lasq_pdsxx_to_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_pd_to")), text);
}

void lasq_pdsxx::lasq_pdsxx_rub_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_pd_rub")), text);
}
