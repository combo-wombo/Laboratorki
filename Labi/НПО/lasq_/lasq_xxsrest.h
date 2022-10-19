#ifndef lasQ_XXSREST_H
#define lasQ_XXSREST_H

#include <QDialog>

namespace Ui {
class lasq_xxsrest;
}

class lasq_xxsrest : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_xxsrest(QWidget *parent = 0);
    ~lasq_xxsrest();

private:
    Ui::lasq_xxsrest *ui;

private slots:
    void lasq_xxsrest_exit_cClick();
};

#endif // lasQ_XXSREST_H
