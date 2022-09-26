#include "lasq_cdstt.h"
#include "ui_lasq_cdstt.h"

lasq_cdstt::lasq_cdstt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_cdstt)
{
    ui->setupUi(this);
    connect(ui->lasq_cdstt_exit_c, SIGNAL(clicked()), this, SLOT(lasq_cdstt_exit_cClick()));
    QSqlQuery query("SELECT lasq_cd_datat FROM lasq_cd");
    query.next();
    QString lasq_cd_datat = query.value(0).toString();
    ui->lasq_cdstt_datat_e->setText(lasq_cd_datat);
}

void lasq_cdstt::lasq_cdstt_exit_cClick() {
    this->reject();
}

void lasq_cdstt::reject() {
    QSqlQuery query;
    query.prepare("UPDATE lasq_cd SET lasq_cd_datat = :lasq_cd_datat");
    QString lasq_cd_datat = ui->lasq_cdstt_datat_e->text();
    query.bindValue(":lasq_cd_datat", lasq_cd_datat);
    query.exec();
    QDialog::reject();
}

lasq_cdstt::~lasq_cdstt()
{
    delete ui;
}
