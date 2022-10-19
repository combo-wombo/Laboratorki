#ifndef lasQ_TOGXX_H
#define lasQ_TOGXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class lasq_togxx;
}

class lasq_togxx : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_togxx(QWidget *parent);
    ~lasq_togxx();

    QSqlTableModel model;
    int currentIndex;
    QString lasq_to_k, lasq_to_db, lasq_to_dbn, lasq_to_kr, lasq_to_krn, lasq_to_sae;

private:
    Ui::lasq_togxx *ui;

private slots:
    void lasq_togxx_exit_cClick();
    void reject();

};

#endif // lasQ_TOGXX_H
