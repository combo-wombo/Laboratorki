#ifndef lasQ_CDSTT_H
#define lasQ_CDSTT_H

#include <QDialog>
#include <QDebug>
#include <QtSql>

namespace Ui {
class lasq_cdstt;
}

class lasq_cdstt : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_cdstt(QWidget *parent = 0);
    ~lasq_cdstt();

private:
    Ui::lasq_cdstt *ui;

private slots:
    void lasq_cdstt_exit_cClick();
    void reject();
};

#endif // lasQ_CDSTT_H
