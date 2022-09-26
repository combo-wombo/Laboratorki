#ifndef lasQ_TOSXX_H
#define lasQ_TOSXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "lasq_xxsgrid.h"

#include <QSqlError>

namespace Ui {
class lasq_tosxx;
}

class lasq_tosxx : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_tosxx(QWidget *parent = 0);
    ~lasq_tosxx();


private:
    Ui::lasq_tosxx *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void lasq_tosxx_grid_cClick();
    void lasq_tosxx_back_cClick();
    void lasq_tosxx_next_cClick();
    void lasq_tosxx_exit_cClick();
    void lasq_tosxx_add_cClick();
    void lasq_tosxx_del_cClick();

    void lasq_tosxx_dbn_eTextChanged(QString);
    void lasq_tosxx_db_eTextChanged(QString);
    void lasq_tosxx_dokk_eTextChanged(QString);
    void lasq_tosxx_k_eTextChanged(QString);
    void lasq_tosxx_n_eTextChanged(QString);
    void lasq_tosxx_kr_eTextChanged(QString);
    void lasq_tosxx_krn_eTextChanged(QString);
    void lasq_tosxx_sae_eTextChanged(QString);
};

#endif // lasQ_TOSXX_H
