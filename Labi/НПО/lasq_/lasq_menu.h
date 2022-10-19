#ifndef lasQ_MENU_H
#define lasQ_MENU_H

#include <QMainWindow>
#include "lasq_xxsrest.h"
#include "lasq_xxssave.h"
#include "lasq_cdsnn.h"
#include "lasq_cdstt.h"
#include "lasq_tosxx.h"
#include "lasq_pdsxx.h"
#include "lasq_rjsxx.h"
#include "lasq_rjtks.h"
#include "lasq_kssrr.h"
#include "lasq_cdsff.h"
#include "lasq_ksrjj.h"
#include "lasq_ksrvv.h"
#include "lasq_ksroo.h"

namespace Ui {
class lasq_menu;
}

class lasq_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit lasq_menu(QWidget *parent = 0);
    ~lasq_menu();

    lasq_xxsrest* lasq_xxsrest1;
    lasq_xxssave* lasq_xxssave1;
    lasq_cdsnn* lasq_cdsnn1;
    lasq_cdstt* lasq_cdstt1;
    lasq_tosxx* lasq_tosxx1;
    lasq_pdsxx* lasq_pdsxx1;
    lasq_rjsxx* lasq_rjsxx1;
    lasq_rjtks* lasq_rjtks1;
    lasq_kssrr* lasq_kssrr1;
    lasq_cdsff* lasq_cdsff1;
    lasq_ksrvv* lasq_ksrvv1;
    lasq_ksrjj* lasq_ksrjj1;
    lasq_ksroo* lasq_ksroo1;

private:
    Ui::lasq_menu *ui;

private slots:
    void lasq_menu_arch_xxsrest_cClick();
    void lasq_menu_arch_xxssave_cClick();
    void lasq_menu_end_close_cClick();
    void lasq_menu_krt_cdsnn_cClick();
    void lasq_menu_krt_tosxx_cClick();
    void lasq_menu_dok_cdstt_cClick();
    void lasq_menu_dok_pdsxx_cClick();
    void lasq_menu_rj_rjsxx_cClick();
    void lasq_menu_rj_rjtks_cClick();
    void lasq_menu_rj_kssrr_cClick();
    void lasq_menu_bo_cdsff_cClick();
    void lasq_menu_bo_ksrvv_cClick();
    void lasq_menu_bo_ksrjj_cClick();
    void lasq_menu_bo_ksroo_cClick();
};

#endif // lasQ_MENU_H

