#include "lasq_cdsnn.h"
#include "ui_lasq_cdsnn.h"

lasq_cdsnn::lasq_cdsnn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_cdsnn)
{
    ui->setupUi(this);
    connect(ui->lasq_cdsnn_exit_c, SIGNAL(clicked()), this, SLOT(lasq_cdsnn_exit_cClick()));
    QSqlQuery query("SELECT lasq_cd_firma FROM lasq_cd");
    query.next();
    QString lasq_cd_firma = query.value(0).toString();
    ui->lasq_cdsnn_firma_e->setText(lasq_cd_firma);
}

void lasq_cdsnn::lasq_cdsnn_exit_cClick() {
    this->reject();
}

void lasq_cdsnn::reject() {
    QSqlQuery query;
    query.prepare("UPDATE lasq_cd SET lasq_cd_firma = :lasq_cd_firma");
    QString lasq_cd_firma = ui->lasq_cdsnn_firma_e->text();
    query.bindValue(":lasq_cd_firma", lasq_cd_firma);
    query.exec();
    QDialog::reject();
}

lasq_cdsnn::~lasq_cdsnn()
{
    delete ui;
}
