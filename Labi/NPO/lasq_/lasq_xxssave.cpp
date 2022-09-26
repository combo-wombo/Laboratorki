#include "lasq_xxssave.h"
#include "ui_lasq_xxssave.h"

lasq_xxssave::lasq_xxssave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_xxssave)
{
    ui->setupUi(this);
    connect(ui->lasq_xxssave_exit_c, SIGNAL(clicked()), this, SLOT(lasq_xxssave_exit_cClick()));
}

lasq_xxssave::~lasq_xxssave()
{
    delete ui;
}

void lasq_xxssave::lasq_xxssave_exit_cClick() {
    this->close();
}
