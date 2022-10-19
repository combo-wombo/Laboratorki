#include "lasq_cdsff.h"
#include "ui_lasq_cdsff.h"

lasq_cdsff::lasq_cdsff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_cdsff)
{
    ui->setupUi(this);
    connect(ui->lasq_cdsff_exit_c, SIGNAL(clicked()), this, SLOT(lasq_cdsff_exit_cClick()));
    QSqlQuery query("SELECT lasq_cd_datas, lasq_cd_datad, lasq_cd_s FROM lasq_cd");
    query.next();
    QString lasq_cd_datas = query.value(0).toString();
    QString lasq_cd_datad = query.value(1).toString();
    QString lasq_cd_s = query.value(2).toString();
    ui->lasq_cdsff_datas_e->setText(lasq_cd_datas);
    ui->lasq_cdsff_datad_e->setText(lasq_cd_datad);
    ui->lasq_cdsff_s_e->setText(lasq_cd_s);
}

void lasq_cdsff::lasq_cdsff_exit_cClick() {
    this->reject();
}

void lasq_cdsff::reject() {
    QSqlQuery query;
    query.prepare("UPDATE lasq_cd SET lasq_cd_datas = :datas, lasq_cd_datad = :datad, lasq_cd_s = :s");
    QString lasq_cd_datas = ui->lasq_cdsff_datas_e->text();
    QString lasq_cd_datad = ui->lasq_cdsff_datad_e->text();
    QString lasq_cd_s = ui->lasq_cdsff_s_e->text();
    query.bindValue(":datas", lasq_cd_datas);
    query.bindValue(":datad", lasq_cd_datad);
    query.bindValue(":s", lasq_cd_s);
    query.exec();
    QDialog::reject();
}

lasq_cdsff::~lasq_cdsff()
{
    delete ui;
}
