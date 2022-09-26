#include "lasq_tosxx.h"
#include "ui_lasq_tosxx.h"

#include <QDebug>

lasq_tosxx::lasq_tosxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_tosxx)
{
    ui->setupUi(this);
    connect(ui->lasq_tosxx_grid_c, SIGNAL(clicked()), this, SLOT(lasq_tosxx_grid_cClick()));
    connect(ui->lasq_tosxx_back_c, SIGNAL(clicked()), this, SLOT(lasq_tosxx_back_cClick()));
    connect(ui->lasq_tosxx_next_c, SIGNAL(clicked()), this, SLOT(lasq_tosxx_next_cClick()));
    connect(ui->lasq_tosxx_exit_c, SIGNAL(clicked()), this, SLOT(lasq_tosxx_exit_cClick()));
    connect(ui->lasq_tosxx_add_c, SIGNAL(clicked()), this, SLOT(lasq_tosxx_add_cClick()));
    connect(ui->lasq_tosxx_del_c, SIGNAL(clicked()), this, SLOT(lasq_tosxx_del_cClick()));

    connect(ui->lasq_tosxx_dbn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_tosxx_dbn_eTextChanged(QString)));
    connect(ui->lasq_tosxx_db_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_tosxx_db_eTextChanged(QString)));
    connect(ui->lasq_tosxx_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_tosxx_dokk_eTextChanged(QString)));
    connect(ui->lasq_tosxx_k_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_tosxx_k_eTextChanged(QString)));
    connect(ui->lasq_tosxx_n_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_tosxx_n_eTextChanged(QString)));
    connect(ui->lasq_tosxx_kr_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_tosxx_kr_eTextChanged(QString)));
    connect(ui->lasq_tosxx_krn_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_tosxx_krn_eTextChanged(QString)));
    connect(ui->lasq_tosxx_sae_e, SIGNAL(textChanged(QString)), this, SLOT(lasq_tosxx_sae_eTextChanged(QString)));

    model.setTable("lasq_to");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);
}

lasq_tosxx::~lasq_tosxx()
{
    delete ui;
}

void lasq_tosxx::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString lasq_to_db = model.record(currentIndex).value("lasq_to_db").toString();
        QString lasq_to_dbn = model.record(currentIndex).value("lasq_to_dbn").toString();
        QString lasq_to_dokk = model.record(currentIndex).value("lasq_to_dokk").toString();
        QString lasq_to_k = model.record(currentIndex).value("lasq_to_k").toString();
        QString lasq_to_kr = model.record(currentIndex).value("lasq_to_kr").toString();
        QString lasq_to_krn = model.record(currentIndex).value("lasq_to_krn").toString();
        QString lasq_to_sae = model.record(currentIndex).value("lasq_to_sae").toString();
        QString lasq_to_n = model.record(currentIndex).value("lasq_to_n").toString();
        ui->lasq_tosxx_db_e->setText(lasq_to_db);
        ui->lasq_tosxx_dbn_e->setText(lasq_to_dbn);
        ui->lasq_tosxx_dokk_e->setText(lasq_to_dokk);
        ui->lasq_tosxx_k_e->setText(lasq_to_k);
        ui->lasq_tosxx_kr_e->setText(lasq_to_kr);
        ui->lasq_tosxx_krn_e->setText(lasq_to_krn);
        ui->lasq_tosxx_sae_e->setText(lasq_to_sae);
        ui->lasq_tosxx_n_e->setText(lasq_to_n);
    }
}

void lasq_tosxx::lasq_tosxx_grid_cClick() {
   lasq_xxsgrid* lasq_xxsgrid1 = new lasq_xxsgrid(this, &model, currentIndex);
   lasq_xxsgrid1->setWindowTitle("lasq_tosxx  viberi operaciu");
   lasq_xxsgrid1->exec();
   changeEdits(lasq_xxsgrid1->currentIndex);
}

void lasq_tosxx::lasq_tosxx_back_cClick() {
    changeEdits(currentIndex - 1);
}

void lasq_tosxx::lasq_tosxx_next_cClick() {
    changeEdits(currentIndex + 1);
}

void lasq_tosxx::lasq_tosxx_exit_cClick() {
    QDialog::reject();
}

void lasq_tosxx::lasq_tosxx_add_cClick() {
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

void lasq_tosxx::lasq_tosxx_del_cClick() {
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

void lasq_tosxx::lasq_tosxx_db_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_to_db")), text);
}

void lasq_tosxx::lasq_tosxx_dbn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_to_dbn")), text);
}

void lasq_tosxx::lasq_tosxx_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_to_dokk")), text);
}

void lasq_tosxx::lasq_tosxx_k_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_to_k")), text);
}

void lasq_tosxx::lasq_tosxx_n_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_to_n")), text);
}

void lasq_tosxx::lasq_tosxx_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_to_kr")), text);
}

void lasq_tosxx::lasq_tosxx_krn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_to_krn")), text);
}

void lasq_tosxx::lasq_tosxx_sae_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("lasq_to_sae")), text);
}
