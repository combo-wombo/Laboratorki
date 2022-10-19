#include "lasq_xxsrest.h"
#include "ui_lasq_xxsrest.h"

lasq_xxsrest::lasq_xxsrest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_xxsrest)
{
    ui->setupUi(this);
    connect(ui->lasq_xxsrest_exit_c, SIGNAL(clicked()), this, SLOT(lasq_xxsrest_exit_cClick()));
}

lasq_xxsrest::~lasq_xxsrest()
{
    delete ui;
}

void lasq_xxsrest::lasq_xxsrest_exit_cClick() {
    this->close();
}
