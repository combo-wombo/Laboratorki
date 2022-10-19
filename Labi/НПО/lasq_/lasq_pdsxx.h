#ifndef lasQ_PDSXX_H
#define lasQ_PDSXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include "lasq_xxsgrid.h"
#include "lasq_togxx.h"

#include <QSqlError>

namespace Ui {
class lasq_pdsxx;
}

class lasq_pdsxx : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_pdsxx(QWidget *parent = 0);
    ~lasq_pdsxx();


private:
    Ui::lasq_pdsxx *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void lasq_pdsxx_grid_cClick();
    void lasq_pdsxx_back_cClick();
    void lasq_pdsxx_next_cClick();
    void lasq_pdsxx_exit_cClick();
    void lasq_pdsxx_add_cClick();
    void lasq_pdsxx_del_cClick();
    void lasq_pdsxx_pdtrj_cClick();
    void lasq_pdsxx_to_cClick();

    void lasq_pdsxx_dbn_eTextChanged(QString);
    void lasq_pdsxx_db_eTextChanged(QString);
    void lasq_pdsxx_dokk_eTextChanged(QString);
    void lasq_pdsxx_dokn_eTextChanged(QString);
    void lasq_pdsxx_dokd_eTextChanged(QString);
    void lasq_pdsxx_kr_eTextChanged(QString);
    void lasq_pdsxx_to_eTextChanged(QString);
    void lasq_pdsxx_rub_eTextChanged(QString);
    void lasq_pdsxx_krn_eTextChanged(QString);
    void lasq_pdsxx_sae_eTextChanged(QString);
};

#endif // lasQ_PDSXX_H
