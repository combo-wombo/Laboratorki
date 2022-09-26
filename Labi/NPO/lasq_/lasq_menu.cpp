#include "lasq_menu.h"
#include "ui_lasq_menu.h"

lasq_menu::lasq_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lasq_menu)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //qDebug() << QApplication::applicationDirPath();
    db.setDatabaseName("R:/lasq_/lasq_data.sqlite");
    if (!db.open()) {
        qDebug() << db.lastError().text();
    } else {
        qDebug() << "OK";
    }
    connect(ui->lasq_menu_arch_xxsrest_c, SIGNAL(clicked()), this, SLOT(lasq_menu_arch_xxsrest_cClick()));
    connect(ui->lasq_menu_arch_xxssave_c, SIGNAL(clicked()), this, SLOT(lasq_menu_arch_xxssave_cClick()));
    connect(ui->lasq_menu_end_close_c, SIGNAL(clicked()), this, SLOT(lasq_menu_end_close_cClick()));
    connect(ui->lasq_menu_krt_cdsnn_c, SIGNAL(clicked()), this, SLOT(lasq_menu_krt_cdsnn_cClick()));
    connect(ui->lasq_menu_krt_tosxx_c, SIGNAL(clicked()), this, SLOT(lasq_menu_krt_tosxx_cClick()));
    connect(ui->lasq_menu_dok_cdstt_c, SIGNAL(clicked()), this, SLOT(lasq_menu_dok_cdstt_cClick()));
    connect(ui->lasq_menu_dok_pdsxx_c, SIGNAL(clicked()), this, SLOT(lasq_menu_dok_pdsxx_cClick()));
    connect(ui->lasq_menu_rj_rjsxx_c, SIGNAL(clicked()), this, SLOT(lasq_menu_rj_rjsxx_cClick()));
    connect(ui->lasq_menu_rj_rjtks_c, SIGNAL(clicked()), this, SLOT(lasq_menu_rj_rjtks_cClick()));
    connect(ui->lasq_menu_rj_kssrr_c, SIGNAL(clicked()), this, SLOT(lasq_menu_rj_kssrr_cClick()));
    connect(ui->lasq_menu_bo_cdsff_c, SIGNAL(clicked()), this, SLOT(lasq_menu_bo_cdsff_cClick()));
    connect(ui->lasq_menu_bo_ksrvv_c, SIGNAL(clicked()), this, SLOT(lasq_menu_bo_ksrvv_cClick()));
    connect(ui->lasq_menu_bo_ksrjj_c, SIGNAL(clicked()), this, SLOT(lasq_menu_bo_ksrjj_cClick()));
    connect(ui->lasq_menu_bo_ksroo_c, SIGNAL(clicked()), this, SLOT(lasq_menu_bo_ksroo_cClick()));
}

lasq_menu::~lasq_menu()
{
    delete ui;
}

void lasq_menu::lasq_menu_arch_xxsrest_cClick() {
    lasq_xxsrest1 = new lasq_xxsrest;
    lasq_xxsrest1->setWindowFlags(lasq_xxsrest1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_xxsrest1->show();
}

void lasq_menu::lasq_menu_arch_xxssave_cClick() {
    lasq_xxssave1 = new lasq_xxssave;
    lasq_xxssave1->setWindowFlags(lasq_xxssave1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_xxssave1->show();
}

void lasq_menu::lasq_menu_end_close_cClick(){
    exit(0);
}

void lasq_menu::lasq_menu_krt_cdsnn_cClick() {
    lasq_cdsnn1 = new lasq_cdsnn;
    lasq_cdsnn1->setWindowFlags(lasq_cdsnn1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_cdsnn1->show();
}

void lasq_menu::lasq_menu_dok_cdstt_cClick() {
    lasq_cdstt1 = new lasq_cdstt;
    lasq_cdstt1->setWindowFlags(lasq_cdstt1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_cdstt1->show();
}

void lasq_menu::lasq_menu_krt_tosxx_cClick() {
    lasq_tosxx1 = new lasq_tosxx;
    lasq_tosxx1->setWindowFlags(lasq_tosxx1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_tosxx1->show();
}

void lasq_menu::lasq_menu_dok_pdsxx_cClick() {
    lasq_pdsxx1 = new lasq_pdsxx;
    lasq_pdsxx1->setWindowFlags(lasq_pdsxx1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_pdsxx1->show();
}

void lasq_menu::lasq_menu_rj_rjsxx_cClick() {
    lasq_rjsxx1 = new lasq_rjsxx;
    lasq_rjsxx1->setWindowFlags(lasq_rjsxx1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_rjsxx1->show();
}

void lasq_menu::lasq_menu_rj_rjtks_cClick() {
    lasq_rjtks1 = new lasq_rjtks;
    lasq_rjtks1->setWindowFlags(lasq_rjtks1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_rjtks1->show();
}

void lasq_menu::lasq_menu_rj_kssrr_cClick() {
    lasq_kssrr1 = new lasq_kssrr;
    lasq_kssrr1->setWindowFlags(lasq_kssrr1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_kssrr1->show();
}

void lasq_menu::lasq_menu_bo_cdsff_cClick() {
    lasq_cdsff1 = new lasq_cdsff;
    lasq_cdsff1->setWindowFlags(lasq_cdsff1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_cdsff1->show();
}

void lasq_menu::lasq_menu_bo_ksrvv_cClick() {
    lasq_ksrvv1 = new lasq_ksrvv;
    lasq_ksrvv1->setWindowFlags(lasq_ksrvv1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_ksrvv1->show();
}

void lasq_menu::lasq_menu_bo_ksrjj_cClick() {
    lasq_ksrjj1 = new lasq_ksrjj;
    lasq_ksrjj1->setWindowFlags(lasq_ksrjj1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_ksrjj1->show();
}


void lasq_menu::lasq_menu_bo_ksroo_cClick() {
    lasq_ksroo1 = new lasq_ksroo;
    lasq_ksroo1->setWindowFlags(lasq_ksroo1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    lasq_ksroo1->show();
}
