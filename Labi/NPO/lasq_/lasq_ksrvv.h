#ifndef lasQ_KSRVV_H
#define lasQ_KSRVV_H

#include <QDialog>

namespace Ui {
class lasq_ksrvv;
}

class lasq_ksrvv : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_ksrvv(QWidget *parent = 0);
    ~lasq_ksrvv();

private:
    Ui::lasq_ksrvv *ui;

private slots:
    void lasq_ksrvv_exit_cClick();
};

#endif // lasQ_KSRVV_H
