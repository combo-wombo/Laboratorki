#ifndef lasQ_XXSSAVE_H
#define lasQ_XXSSAVE_H

#include <QDialog>

namespace Ui {
class lasq_xxssave;
}

class lasq_xxssave : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_xxssave(QWidget *parent = 0);
    ~lasq_xxssave();

private:
    Ui::lasq_xxssave *ui;

private slots:
    void lasq_xxssave_exit_cClick();
};

#endif // lasQ_XXSSAVE_H
