#include "lasq_rjtks.h"
#include "ui_lasq_rjtks.h"

lasq_rjtks::lasq_rjtks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasq_rjtks)
{
    ui->setupUi(this);
    connect(ui->lasq_rjtks_gridrj_c, SIGNAL(clicked()), this, SLOT(lasq_rjtks_gridrj_cClick()));
    connect(ui->lasq_rjtks_gridks_c, SIGNAL(clicked()), this, SLOT(lasq_rjtks_gridks_cClick()));
    connect(ui->lasq_rjtks_exit_c, SIGNAL(clicked()), this, SLOT(lasq_rjtks_exit_cClick()));
    connect(ui->lasq_rjtks_wk_c, SIGNAL(clicked()), this, SLOT(lasq_rjtks_wk_cClick()));

    model_rj.setTable("lasq_rj");
    model_rj.select();
    model_rj.setEditStrategy(QSqlTableModel::OnFieldChange);

    size_rj = model_rj.rowCount();
    index_rj = size_rj - 1;

    model_ks.setTable("lasq_ks");
    model_ks.select();
    model_ks.setEditStrategy(QSqlTableModel::OnFieldChange);

    size_ks = model_ks.rowCount();
    index_ks = size_ks - 1;

}

lasq_rjtks::~lasq_rjtks()
{
    delete ui;
}

void lasq_rjtks::changeIndexRJ(int newIndex) {
    if (newIndex >=0 && newIndex < size_rj) {
        index_rj = newIndex;
    }
}

void lasq_rjtks::changeIndexKS(int newIndex) {
    if (newIndex >=0 && newIndex < size_ks) {
        index_ks = newIndex;
    }
}

void lasq_rjtks::lasq_rjtks_gridrj_cClick() {
    lasq_xxsgrid* lasq_xxsgrid1 = new lasq_xxsgrid(this, &model_rj, index_rj);
    lasq_xxsgrid1->setWindowTitle("lasq_rjtks  posmotri reg jurnal i viidi");
    lasq_xxsgrid1->exec();
    changeIndexRJ(lasq_xxsgrid1->currentIndex);
}

void lasq_rjtks::lasq_rjtks_gridks_cClick() {
    lasq_xxsgrid* lasq_xxsgrid1 = new lasq_xxsgrid(this, &model_ks, index_ks);
    lasq_xxsgrid1->setWindowTitle("lasq_rjtks  posmotri knigu schetov i viidi");
    lasq_xxsgrid1->exec();
    changeIndexKS(lasq_xxsgrid1->currentIndex);
}

void lasq_rjtks::lasq_rjtks_exit_cClick() {
    QDialog::reject();
}

void lasq_rjtks::lasq_rjtks_wk_cClick() {
    QSqlQuery query;
    query.prepare("DELETE FROM lasq_ks");
    query.exec();

    for (int i = 0; i < size_rj; i++) {
        query.prepare("INSERT INTO lasq_ks VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue("0");
        query.addBindValue(model_rj.record(i).value("lasq_rj_data").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_dokk").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_dokn").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_dokd").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_to").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_db").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_dbn").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_kr").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_krn").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_rub").toString());
        query.addBindValue("0");
        query.addBindValue(model_rj.record(i).value("lasq_rj_sae").toString());
        query.exec();

        query.prepare("INSERT INTO lasq_ks VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue("0");
        query.addBindValue(model_rj.record(i).value("lasq_rj_data").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_dokk").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_dokn").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_dokd").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_to"));
        query.addBindValue(model_rj.record(i).value("lasq_rj_kr").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_krn").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_db").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_dbn").toString());
        query.addBindValue("0");
        query.addBindValue(model_rj.record(i).value("lasq_rj_rub").toString());
        query.addBindValue(model_rj.record(i).value("lasq_rj_sae").toString());
        query.exec();
    }

    model_ks.setTable("lasq_ks");
    model_ks.select();
    model_ks.setEditStrategy(QSqlTableModel::OnFieldChange);

    size_ks = model_ks.rowCount();
    index_ks = size_ks - 1;
}

