/********************************************************************************
** Form generated from reading UI file 'lasq_togxx.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASQ_TOGXX_H
#define UI_LASQ_TOGXX_H

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

class Ui_lasq_togxx
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *lasq_togxx_g;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lasq_togxx_exit_c;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *lasq_togxx)
    {
        if (lasq_togxx->objectName().isEmpty())
            lasq_togxx->setObjectName(QString::fromUtf8("lasq_togxx"));
        lasq_togxx->setWindowModality(Qt::ApplicationModal);
        lasq_togxx->resize(400, 300);
        verticalLayout = new QVBoxLayout(lasq_togxx);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lasq_togxx_g = new QTableView(lasq_togxx);
        lasq_togxx_g->setObjectName(QString::fromUtf8("lasq_togxx_g"));
        lasq_togxx_g->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(lasq_togxx_g);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lasq_togxx_exit_c = new QPushButton(lasq_togxx);
        lasq_togxx_exit_c->setObjectName(QString::fromUtf8("lasq_togxx_exit_c"));

        horizontalLayout->addWidget(lasq_togxx_exit_c);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(lasq_togxx_exit_c, lasq_togxx_g);

        retranslateUi(lasq_togxx);

        QMetaObject::connectSlotsByName(lasq_togxx);
    } // setupUi

    void retranslateUi(QDialog *lasq_togxx)
    {
        lasq_togxx->setWindowTitle(QCoreApplication::translate("lasq_togxx", "lasq_togxx", nullptr));
        lasq_togxx_exit_c->setText(QCoreApplication::translate("lasq_togxx", "\320\222\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lasq_togxx: public Ui_lasq_togxx {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASQ_TOGXX_H
