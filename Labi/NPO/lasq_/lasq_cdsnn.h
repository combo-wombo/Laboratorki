#ifndef lasQ_CDSNN_H
#define lasQ_CDSNN_H

#include <QDialog>
#include <QDebug>
#include <QtSql>

namespace Ui {
class lasq_cdsnn;
}

class lasq_cdsnn : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_cdsnn(QWidget *parent = 0);
    ~lasq_cdsnn();

private:
    Ui::lasq_cdsnn *ui;

private slots:
    void lasq_cdsnn_exit_cClick();
    void reject();
};

#endif // lasQ_CDSNN_H
