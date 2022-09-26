#include "lasq_rjsxx.h"
#include "ui_lasq_rjsxx.h"

#include <QDebug>

lasq_rjsxx::lasq_rjsxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_rjsxx)
{
    ui->setupUi(this);
    connect(ui->lasq_rjsxx_grid_c, SIGNAL(clicked()), this, SLOT(lasq_rjsxx_grid_cClick()));
    connect(ui->lasq_rjsxx_back_c, SIGNAL(clicked()), this, SLOT(lasq_rjsxx_back_cClick()));
    connect(ui->lasq_rjsxx_next_c, SIGNAL(clicked()), this, SLOT(lasq_rjsxx_next_cClick()));
    connect(ui->lasq_rjsxx_exit_c, SIGNAL(clicked()), this, SLOT(lasq_rjsxx_exit_cClick()));
    connect(ui->lasq_rjsxx_add_c, SIGNAL(clicked()), this, SLOT(lasq_rjsxx_add_cClick()));
    connect(ui->lasq_rjsxx_del_c, SIGNAL(clicked()), this, SLOT(lasq_rjsxx_del_cClick()));

    connect(ui->lasq_rjsxx_dbn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_dbn_eTextChanged(QString)));
    connect(ui->lasq_rjsxx_db_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_db_eTextChanged(QString)));
    connect(ui->lasq_rjsxx_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_dokk_eTextChanged(QString)));
    connect(ui->lasq_rjsxx_data_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_data_eTextChanged(QString)));
    connect(ui->lasq_rjsxx_dokn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_dokn_eTextChanged(QString)));
    connect(ui->lasq_rjsxx_dokd_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_dokd_eTextChanged(QString)));
    connect(ui->lasq_rjsxx_kr_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_kr_eTextChanged(QString)));
    connect(ui->lasq_rjsxx_krn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_krn_eTextChanged(QString)));
    connect(ui->lasq_rjsxx_sae_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_sae_eTextChanged(QString)));
    connect(ui->lasq_rjsxx_to_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_to_eTextChanged(QString)));
    connect(ui->lasq_rjsxx_rub_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_rjsxx_rub_eTextChanged(QString)));

    model.setTable("lasq_rj");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);
}

lasq_rjsxx::~lasq_rjsxx()
{
    delete ui;
}

void lasq_rjsxx::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString lasq_rj_db = model.record(currentIndex).value("lasq_rj_db").toString();
        QString lasq_rj_dbn = model.record(currentIndex).value("lasq_rj_dbn").toString();
        QString lasq_rj_dokk = model.record(currentIndex).value("lasq_rj_dokk").toString();
        QString lasq_rj_dokd = model.record(currentIndex).value("lasq_rj_dokd").toString();
        QString lasq_rj_dokn = model.record(currentIndex).value("lasq_rj_dokn").toString();
        QString lasq_rj_data = model.record(currentIndex).value("lasq_rj_data").toString();
        QString lasq_rj_to = model.record(currentIndex).value("lasq_rj_to").toString();
        QString lasq_rj_kr = model.record(currentIndex).value("lasq_rj_kr").toString();
        QString lasq_rj_krn = model.record(currentIndex).value("lasq_rj_krn").toString();
        QString lasq_rj_sae = model.record(currentIndex).value("lasq_rj_sae").toString();
        QString lasq_rj_rub = model.record(currentIndex).value("lasq_rj_rub").toString();
        ui->lasq_rjsxx_db_e->setText(lasq_rj_db);
        ui->lasq_rjsxx_dbn_e->setText(lasq_rj_dbn);
        ui->lasq_rjsxx_dokk_e->setText(lasq_rj_dokk);
        ui->lasq_rjsxx_dokd_e->setText(lasq_rj_dokd);
        ui->lasq_rjsxx_dokn_e->setText(lasq_rj_dokn);
        ui->lasq_rjsxx_data_e->setText(lasq_rj_data);
        ui->lasq_rjsxx_kr_e->setText(lasq_rj_kr);
        ui->lasq_rjsxx_krn_e->setText(lasq_rj_krn);
        ui->lasq_rjsxx_sae_e->setText(lasq_rj_sae);
        ui->lasq_rjsxx_rub_e->setText(lasq_rj_rub);
        ui->lasq_rjsxx_to_e->setText(lasq_rj_to);
    }
}

void lasq_rjsxx::lasq_rjsxx_grid_cClick() {
   lasq_xxsgrid* lasq_xxsgrid1 = new lasq_xxsgrid(this, &model, currentIndex);
   lasq_xxsgrid1->setWindowTitle("lasq_rjsxx  viberi dokument");
   lasq_xxsgrid1->exec();
   changeEdits(lasq_xxsgrid1->currentIndex);
}

void lasq_rjsxx::lasq_rjsxx_back_cClick() {
    changeEdits(currentIndex - 1);
}

void lasq_rjsxx::lasq_rjsxx_next_cClick() {
    changeEdits(currentIndex + 1);
}

void lasq_rjsxx::lasq_rjsxx_exit_cClick() {
    QDialog::reject();
}

void lasq_rjsxx::lasq_rjsxx_add_cClick() {
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

void lasq_rjsxx::lasq_rjsxx_del_cClick() {
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

void lasq_rjsxx::lasq_rjsxx_db_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_db")), text);
}

void lasq_rjsxx::lasq_rjsxx_dbn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_dbn")), text);
}

void lasq_rjsxx::lasq_rjsxx_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_dokk")), text);
}

void lasq_rjsxx::lasq_rjsxx_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_kr")), text);
}

void lasq_rjsxx::lasq_rjsxx_krn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_krn")), text);
}

void lasq_rjsxx::lasq_rjsxx_sae_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_sae")), text);
}

void lasq_rjsxx::lasq_rjsxx_data_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_data")), text);
}

void lasq_rjsxx::lasq_rjsxx_dokn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_dokn")), text);
}

void lasq_rjsxx::lasq_rjsxx_dokd_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_dokd")), text);
}

void lasq_rjsxx::lasq_rjsxx_to_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_to")), text);
}

void lasq_rjsxx::lasq_rjsxx_rub_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_rj_rub")), text);
}
