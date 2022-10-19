#include "lasq_ksrvv.h"
#include "ui_lasq_ksrvv.h"

lasq_ksrvv::lasq_ksrvv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_ksrvv)
{
    ui->setupUi(this);
    connect(ui->lasq_ksrvv_exit_c, SIGNAL(clicked()), this, SLOT(lasq_ksrvv_exit_cClick()));
}

lasq_ksrvv::~lasq_ksrvv()
{
    delete ui;
}

void lasq_ksrvv::lasq_ksrvv_exit_cClick() {
    this->close();
}
