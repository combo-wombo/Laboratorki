#ifndef lasQ_RJSXX_H
#define lasQ_RJSXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "lasq_xxsgrid.h"

#include <QSqlError>

namespace Ui {
class lasq_rjsxx;
}

class lasq_rjsxx : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_rjsxx(QWidget *parent = 0);
    ~lasq_rjsxx();

private:
    Ui::lasq_rjsxx *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void lasq_rjsxx_grid_cClick();
    void lasq_rjsxx_back_cClick();
    void lasq_rjsxx_next_cClick();
    void lasq_rjsxx_exit_cClick();
    void lasq_rjsxx_add_cClick();
    void lasq_rjsxx_del_cClick();

    void lasq_rjsxx_dbn_eTextChanged(QString);
    void lasq_rjsxx_db_eTextChanged(QString);
    void lasq_rjsxx_dokk_eTextChanged(QString);
    void lasq_rjsxx_dokd_eTextChanged(QString);
    void lasq_rjsxx_dokn_eTextChanged(QString);
    void lasq_rjsxx_data_eTextChanged(QString);
    void lasq_rjsxx_kr_eTextChanged(QString);
    void lasq_rjsxx_krn_eTextChanged(QString);
    void lasq_rjsxx_sae_eTextChanged(QString);
    void lasq_rjsxx_to_eTextChanged(QString);
    void lasq_rjsxx_rub_eTextChanged(QString);
};

#endif // lasQ_RJSXX_H

