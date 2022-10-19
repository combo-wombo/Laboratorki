#ifndef lasQ_KSROO_H
#define lasQ_KSROO_H

#include <QDialog>

namespace Ui {
class lasq_ksroo;
}

class lasq_ksroo : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_ksroo(QWidget *parent = 0);
    ~lasq_ksroo();

private:
    Ui::lasq_ksroo *ui;

private slots:
    void lasq_ksroo_exit_cClick();
};

#endif // lasQ_KSROO_H
