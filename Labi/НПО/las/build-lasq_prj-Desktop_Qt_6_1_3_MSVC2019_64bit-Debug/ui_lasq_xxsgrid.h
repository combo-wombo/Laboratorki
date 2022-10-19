/********************************************************************************
** Form generated from reading UI file 'lasq_xxsgrid.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASQ_XXSGRID_H
#define UI_LASQ_XXSGRID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_lasq_xxsgrid
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *lasq_xxsgrid_g;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lasq_xxsgrid_exit_c;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *lasq_xxsgrid)
    {
        if (lasq_xxsgrid->objectName().isEmpty())
            lasq_xxsgrid->setObjectName(QString::fromUtf8("lasq_xxsgrid"));
        lasq_xxsgrid->setWindowModality(Qt::ApplicationModal);
        lasq_xxsgrid->resize(882, 418);
        verticalLayout = new QVBoxLayout(lasq_xxsgrid);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lasq_xxsgrid_g = new QTableView(lasq_xxsgrid);
        lasq_xxsgrid_g->setObjectName(QString::fromUtf8("lasq_xxsgrid_g"));
        lasq_xxsgrid_g->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(lasq_xxsgrid_g);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lasq_xxsgrid_exit_c = new QPushButton(lasq_xxsgrid);
        lasq_xxsgrid_exit_c->setObjectName(QString::fromUtf8("lasq_xxsgrid_exit_c"));

        horizontalLayout->addWidget(lasq_xxsgrid_exit_c);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(lasq_xxsgrid_exit_c, lasq_xxsgrid_g);

        retranslateUi(lasq_xxsgrid);

        QMetaObject::connectSlotsByName(lasq_xxsgrid);
    } // setupUi

    void retranslateUi(QDialog *lasq_xxsgrid)
    {
        lasq_xxsgrid->setWindowTitle(QCoreApplication::translate("lasq_xxsgrid", "lasq_xxsgrid", nullptr));
        lasq_xxsgrid_exit_c->setText(QCoreApplication::translate("lasq_xxsgrid", "\320\222\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lasq_xxsgrid: public Ui_lasq_xxsgrid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASQ_XXSGRID_H
