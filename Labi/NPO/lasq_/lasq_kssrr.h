#ifndef lasQ_KSSRR_H
#define lasQ_KSSRR_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "lasq_xxsgrid.h"

#include <QSqlError>

namespace Ui {
class lasq_kssrr;
}

class lasq_kssrr : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_kssrr(QWidget *parent = 0);
    ~lasq_kssrr();


private:
    Ui::lasq_kssrr *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void lasq_kssrr_grid_cClick();
    void lasq_kssrr_back_cClick();
    void lasq_kssrr_next_cClick();
    void lasq_kssrr_exit_cClick();

    void lasq_kssrr_data_eTextChanged(QString);
    void lasq_kssrr_dokd_eTextChanged(QString);
    void lasq_kssrr_dokk_eTextChanged(QString);
    void lasq_kssrr_ksn_eTextChanged(QString);
    void lasq_kssrr_rubdb_eTextChanged(QString);
    void lasq_kssrr_kr_eTextChanged(QString);
    void lasq_kssrr_dokn_eTextChanged(QString);
    void lasq_kssrr_sae_eTextChanged(QString);
    void lasq_kssrr_s_eTextChanged(QString);
    void lasq_kssrr_sn_eTextChanged(QString);
    void lasq_kssrr_to_eTextChanged(QString);
    void lasq_kssrr_rubkr_eTextChanged(QString);

};

#endif // lasq_kssrr_H
