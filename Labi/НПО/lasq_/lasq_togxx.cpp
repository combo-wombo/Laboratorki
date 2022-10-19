#include "lasq_togxx.h"
#include "ui_lasq_togxx.h"

lasq_togxx::lasq_togxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_togxx)
{
    ui->setupUi(this);

    connect(ui->lasq_togxx_exit_c, SIGNAL(clicked()), this, SLOT(lasq_togxx_exit_cClick()));

    model.setTable("lasq_to");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    int size = model.rowCount();
    currentIndex = size - 1;

    ui->lasq_togxx_g->setModel(&model);
    ui->lasq_togxx_g->setCurrentIndex(model.index(currentIndex, 0));
}

void lasq_togxx::lasq_togxx_exit_cClick() {
    this->reject();
}

void lasq_togxx::reject() {
    currentIndex = ui->lasq_togxx_g->currentIndex().row();
    lasq_to_k = model.record(currentIndex).value("lasq_to_k").toString();
    lasq_to_db = model.record(currentIndex).value("lasq_to_db").toString();
    lasq_to_dbn = model.record(currentIndex).value("lasq_to_dbn").toString();
    lasq_to_kr = model.record(currentIndex).value("lasq_to_kr").toString();
    lasq_to_krn = model.record(currentIndex).value("lasq_to_krn").toString();
    lasq_to_sae = model.record(currentIndex).value("lasq_to_sae").toString();
    QDialog::reject();
}

lasq_togxx::~lasq_togxx()
{
    delete ui;
}
