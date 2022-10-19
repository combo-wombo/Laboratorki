#ifndef lasQ_KSRJJ_H
#define lasQ_KSRJJ_H

#include <QDialog>

namespace Ui {
class lasq_ksrjj;
}

class lasq_ksrjj : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_ksrjj(QWidget *parent = 0);
    ~lasq_ksrjj();

private:
    Ui::lasq_ksrjj *ui;

private slots:
    void lasq_ksrjj_exit_cClick();
};

#endif // lasQ_KSRJJ_H
