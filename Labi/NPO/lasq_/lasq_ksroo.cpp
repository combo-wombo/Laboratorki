#include "lasq_ksroo.h"
#include "ui_lasq_ksroo.h"
#include <QSqlQuery>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <cstdio>

lasq_ksroo::lasq_ksroo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_ksroo)
{
    ui->setupUi(this);
    connect(ui->lasq_ksroo_exit_c, SIGNAL(clicked()), this, SLOT(lasq_ksroo_exit_cClick()));
    QSqlQuery query("SELECT lasq_cd_s, lasq_cd_datad, lasq_cd_datas FROM lasq_cd");
    query.next();
    QString lasq_cd_s = query.value(0).toString();
    QString lasq_cd_datad = query.value(1).toString();
    QString lasq_cd_datas = query.value(2).toString();
    FILE* file;
    file = fopen("lasq_otchet.txt", "w");
    fprintf(file, "%85s\n", "");
    fprintf(file, "%4s%-20.20s%8s%s%13s%s%2s\n", "", "=Lud A. S.=", "", "oborotno-saldovaa vedomost", "", "=lasq_krsoo=", "");
    fprintf(file, "%8s%s%4s%4s%13s%s%4s%10s%s%10s     \n", "", "schet", "", lasq_cd_s.toLocal8Bit().data(), "", "interval s", "", lasq_cd_datas.toLocal8Bit().data(), "      do    ", lasq_cd_datad.toLocal8Bit().data());
    fprintf(file, "%85s\n", "");
    fprintf(file, "  %s  \n", "---------------------------------------------------------------------------------");
    fprintf(file, "   data      | sae  | dokument   | schet | korr schet | vx | oborot db kr | isx      \n");
    fprintf(file, "  %s  \n", "---------------------------------------------------------------------------------");
    fprintf(file, "%85s\n", "");
    QSqlQuery query_ks("SELECT lasq_ks_data, lasq_ks_sae, lasq_ks_dokk, lasq_ks_s, lasq_ks_ks, lasq_ks_rubdb, lasq_ks_rubkr, lasq_ks_dokn, lasq_ks_dokd FROM lasq_ks");
    while (query_ks.next()) {
        QString lasq_ks_data = query_ks.value(0).toString();
        QString lasq_ks_sae = query_ks.value(1).toString();
        QString lasq_ks_dokk = query_ks.value(2).toString();
        QString lasq_ks_s = query_ks.value(3).toString();
        QString lasq_ks_ks = query_ks.value(4).toString();
        QString lasq_ks_rubdb = query_ks.value(5).toString();
        QString lasq_ks_rubkr = query_ks.value(6).toString();
        QString lasq_ks_dokn = query_ks.value(7).toString();
        QString lasq_ks_dokd = query_ks.value(8).toString();
        fprintf(file, "  %10s   %4s   %-4s%10s%4s%9s%4s%9s%5s%7s%5s%6s\n",
                lasq_ks_data.toLocal8Bit().data(),
                lasq_ks_sae.toLocal8Bit().data(),
                lasq_ks_dokk.toLocal8Bit().data(),
                "",
                lasq_ks_s.toLocal8Bit().data(),
                "",
                lasq_ks_ks.toLocal8Bit().data(),
                "",
                lasq_ks_rubdb.toLocal8Bit().data(),
                "",
                lasq_ks_rubkr.toLocal8Bit().data(),
                "");
        fprintf(file, "%22s%-4s%59s\n", "", lasq_ks_dokn.toLocal8Bit().data(), "");
        fprintf(file, "%22s%-10s%53s\n", "", lasq_ks_dokd.toLocal8Bit().data(), "");
        fprintf(file, "%85s\n", "");
    }
    fprintf(file, "%85s\n", "");
    QSqlQuery query_sum("SELECT SUM(lasq_ks_rubdb), SUM(lasq_ks_rubkr) FROM lasq_ks");
    query_sum.next();
    QString lasq_ks_rubdb_sum = query_sum.value(0).toString();
    QString lasq_ks_rubkr_sum = query_sum.value(1).toString();
    fprintf(file, "%39s%s%3s%5s%7s%5s%6s\n", "", "lasq_itogo po schetu", "", lasq_ks_rubdb_sum.toLocal8Bit().data(), "", lasq_ks_rubkr_sum.toLocal8Bit().data(), "");
    fprintf(file, "%85s\n", "");
    fclose(file);
    QFile qfile("lasq_otchet.txt");
    if (!qfile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "info", qfile.errorString());
    }
    QTextStream in(&qfile);
    ui->lasq_ksroo_qr->setText(in.readAll());
}

lasq_ksroo::~lasq_ksroo()
{
    delete ui;
}

void lasq_ksroo::lasq_ksroo_exit_cClick() {
    this->close();
}
