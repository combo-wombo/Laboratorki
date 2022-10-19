#include "lasq_kssrr.h"
#include "ui_lasq_kssrr.h"

#include <QDebug>

lasq_kssrr::lasq_kssrr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_kssrr)
{
    ui->setupUi(this);
    connect(ui->lasq_kssrr_grid_c, SIGNAL(clicked()), this, SLOT(lasq_kssrr_grid_cClick()));
    connect(ui->lasq_kssrr_back_c, SIGNAL(clicked()), this, SLOT(lasq_kssrr_back_cClick()));
    connect(ui->lasq_kssrr_next_c, SIGNAL(clicked()), this, SLOT(lasq_kssrr_next_cClick()));
    connect(ui->lasq_kssrr_exit_c, SIGNAL(clicked()), this, SLOT(lasq_kssrr_exit_cClick()));

    connect(ui->lasq_kssrr_data_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_data_eTextChanged(QString)));
    connect(ui->lasq_kssrr_dokd_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_dokd_eTextChanged(QString)));
    connect(ui->lasq_kssrr_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_dokk_eTextChanged(QString)));
    connect(ui->lasq_kssrr_ksn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_ksn_eTextChanged(QString)));
    connect(ui->lasq_kssrr_rubdb_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_rubdb_eTextChanged(QString)));
    connect(ui->lasq_kssrr_kr_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_kr_eTextChanged(QString)));
    connect(ui->lasq_kssrr_dokn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_dokn_eTextChanged(QString)));
    connect(ui->lasq_kssrr_sae_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_sae_eTextChanged(QString)));
    connect(ui->lasq_kssrr_s_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_s_eTextChanged(QString)));
    connect(ui->lasq_kssrr_sn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_sn_eTextChanged(QString)));
    connect(ui->lasq_kssrr_to_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_to_eTextChanged(QString)));
    connect(ui->lasq_kssrr_rubkr_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_kssrr_rubkr_eTextChanged(QString)));

    model.setTable("lasq_ks");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);
}

lasq_kssrr::~lasq_kssrr()
{
    delete ui;
}

void lasq_kssrr::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString lasq_ks_data = model.record(currentIndex).value("lasq_ks_data").toString();
        QString lasq_ks_dokd = model.record(currentIndex).value("lasq_ks_dokd").toString();
        QString lasq_ks_dokk = model.record(currentIndex).value("lasq_ks_dokk").toString();
        QString lasq_ks_rubdb = model.record(currentIndex).value("lasq_ks_rubdb").toString();
        QString lasq_ks_kr = model.record(currentIndex).value("lasq_ks_ks").toString();
        QString lasq_ks_ksn = model.record(currentIndex).value("lasq_ks_ksn").toString();
        QString lasq_ks_sae = model.record(currentIndex).value("lasq_ks_sae").toString();
        QString lasq_ks_dokn = model.record(currentIndex).value("lasq_ks_dokn").toString();
        QString lasq_ks_s = model.record(currentIndex).value("lasq_ks_s").toString();
        QString lasq_ks_sn = model.record(currentIndex).value("lasq_ks_sn").toString();
        QString lasq_ks_to = model.record(currentIndex).value("lasq_ks_to").toString();
        QString lasq_ks_rubkr = model.record(currentIndex).value("lasq_ks_rubkr").toString();
        ui->lasq_kssrr_dokd_e->setText(lasq_ks_data);
        ui->lasq_kssrr_data_e->setText(lasq_ks_dokd);
        ui->lasq_kssrr_dokk_e->setText(lasq_ks_dokk);
        ui->lasq_kssrr_ksn_e->setText(lasq_ks_ksn);
        ui->lasq_kssrr_kr_e->setText(lasq_ks_kr);
        ui->lasq_kssrr_dokn_e->setText(lasq_ks_dokn);
        ui->lasq_kssrr_sae_e->setText(lasq_ks_sae);
        ui->lasq_kssrr_rubdb_e->setText(lasq_ks_rubdb);
        ui->lasq_kssrr_s_e->setText(lasq_ks_s);
        ui->lasq_kssrr_sn_e->setText(lasq_ks_sn);
        ui->lasq_kssrr_to_e->setText(lasq_ks_to);
        ui->lasq_kssrr_rubkr_e->setText(lasq_ks_rubkr);
    }
}

void lasq_kssrr::lasq_kssrr_grid_cClick() {
   lasq_xxsgrid* lasq_xxsgrid1 = new lasq_xxsgrid(this, &model, currentIndex);
   lasq_xxsgrid1->setWindowTitle("lasq_kssrr  viberi operaciu");
   lasq_xxsgrid1->exec();
   changeEdits(lasq_xxsgrid1->currentIndex);
}

void lasq_kssrr::lasq_kssrr_back_cClick() {
    changeEdits(currentIndex - 1);
}

void lasq_kssrr::lasq_kssrr_next_cClick() {
    changeEdits(currentIndex + 1);
}

void lasq_kssrr::lasq_kssrr_exit_cClick() {
    QDialog::reject();
}

void lasq_kssrr::lasq_kssrr_dokd_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_dokd")), text);
}

void lasq_kssrr::lasq_kssrr_data_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_data")), text);
}

void lasq_kssrr::lasq_kssrr_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_dokk")), text);
}

void lasq_kssrr::lasq_kssrr_ksn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_ksn")), text);
}

void lasq_kssrr::lasq_kssrr_rubdb_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_rubdb")), text);
}

void lasq_kssrr::lasq_kssrr_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_kr")), text);
}

void lasq_kssrr::lasq_kssrr_dokn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_dokn")), text);
}

void lasq_kssrr::lasq_kssrr_sae_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_sae")), text);
}

void lasq_kssrr::lasq_kssrr_s_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_s")), text);
}

void lasq_kssrr::lasq_kssrr_sn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_sn")), text);
}

void lasq_kssrr::lasq_kssrr_to_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_to")), text);
}

void lasq_kssrr::lasq_kssrr_rubkr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_ks_rubkr")), text);
}
