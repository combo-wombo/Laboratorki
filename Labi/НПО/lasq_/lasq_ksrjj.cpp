#include "lasq_ksrjj.h"
#include "ui_lasq_ksrjj.h"

lasq_ksrjj::lasq_ksrjj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_ksrjj)
{
    ui->setupUi(this);
    connect(ui->lasq_ksrjj_exit_c, SIGNAL(clicked()), this, SLOT(lasq_ksrjj_exit_cClick()));
}

lasq_ksrjj::~lasq_ksrjj()
{
    delete ui;
}

void lasq_ksrjj::lasq_ksrjj_exit_cClick() {
    this->close();
}
