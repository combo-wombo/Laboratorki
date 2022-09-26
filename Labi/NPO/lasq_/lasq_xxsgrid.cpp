#include "lasq_xxsgrid.h"
#include "ui_lasq_xxsgrid.h"

lasq_xxsgrid::lasq_xxsgrid(QWidget *parent, QSqlTableModel *model, int currentIndex) :
    QDialog(parent),
    ui(new Ui::lasq_xxsgrid)
{
    ui->setupUi(this);

    connect(ui->lasq_xxsgrid_exit_c, SIGNAL(clicked()), this, SLOT(lasq_xxsgrid_exit_cClick()));
    this->currentIndex = currentIndex;
    ui->lasq_xxsgrid_g->setModel(model);
    ui->lasq_xxsgrid_g->setCurrentIndex(model->index(currentIndex, 0));
}

void lasq_xxsgrid::lasq_xxsgrid_exit_cClick() {
    this->reject();
}

void lasq_xxsgrid::reject() {
    currentIndex = ui->lasq_xxsgrid_g->currentIndex().row();
    QDialog::reject();
}

lasq_xxsgrid::~lasq_xxsgrid()
{
    delete ui;
}
