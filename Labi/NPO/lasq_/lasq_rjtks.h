#ifndef lasQ_RJTKS_H
#define lasQ_RJTKS_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include "lasq_xxsgrid.h"

namespace Ui {
class lasq_rjtks;
}

class lasq_rjtks : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_rjtks(QWidget *parent = 0);
    ~lasq_rjtks();

private:
    Ui::lasq_rjtks *ui;
    QSqlTableModel model_rj;
    QSqlTableModel model_ks;
    int index_rj, index_ks, size_rj, size_ks;

    void changeIndexRJ(int newIndex);
    void changeIndexKS(int newIndex);

private slots:
    void lasq_rjtks_gridrj_cClick();
    void lasq_rjtks_gridks_cClick();
    void lasq_rjtks_wk_cClick();
    void lasq_rjtks_exit_cClick();
};

#endif // lasQ_RJTKS_H
