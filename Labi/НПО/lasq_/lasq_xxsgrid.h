#ifndef lasQ_XXSGRID_H
#define lasQ_XXSGRID_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class lasq_xxsgrid;
}

class lasq_xxsgrid : public QDialog
{
    Q_OBJECT

public:
    explicit lasq_xxsgrid(QWidget *parent, QSqlTableModel *model, int currentIndex);
    ~lasq_xxsgrid();

    int currentIndex;

private:
    Ui::lasq_xxsgrid *ui; 

private slots:
    void lasq_xxsgrid_exit_cClick();
    void reject();

};

#endif // lasQ_XXSGRID_H
