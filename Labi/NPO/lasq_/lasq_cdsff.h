#ifndef lasQ_CDSFF_H
#define lasQ_CDSFF_H

#include <QDialog>
#include <QDebug>
#include <QtSql>

namespace Ui {
class lasq_cdsff;
}

class lasq_cdsff : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_cdsff(QWidget *parent = 0);
    ~lasq_cdsff();

private:
    Ui::lasq_cdsff *ui;

private slots:
    void lasq_cdsff_exit_cClick();
    void reject();
};

#endif // lasQ_CDSFF_H
