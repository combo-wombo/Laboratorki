/********************************************************************************
** Form generated from reading UI file 'lasq_ksrjj.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASQ_KSRJJ_H
#define UI_LASQ_KSRJJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_lasq_ksrjj
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lasq_ksrjj_xxlas_l;
    QSpacerItem *horizontalSpacer;
    QLabel *lasq_ksrjj_xxprg_l;
    QSpacerItem *verticalSpacer;
    QLabel *lasq_ksrjj_xxtitle_l;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lasq_ksrjj_exit_c;

    void setupUi(QDialog *lasq_ksrjj)
    {
        if (lasq_ksrjj->objectName().isEmpty())
            lasq_ksrjj->setObjectName(QString::fromUtf8("lasq_ksrjj"));
        lasq_ksrjj->setWindowModality(Qt::ApplicationModal);
        lasq_ksrjj->resize(400, 300);
        verticalLayout = new QVBoxLayout(lasq_ksrjj);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lasq_ksrjj_xxlas_l = new QLabel(lasq_ksrjj);
        lasq_ksrjj_xxlas_l->setObjectName(QString::fromUtf8("lasq_ksrjj_xxlas_l"));

        horizontalLayout->addWidget(lasq_ksrjj_xxlas_l);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lasq_ksrjj_xxprg_l = new QLabel(lasq_ksrjj);
        lasq_ksrjj_xxprg_l->setObjectName(QString::fromUtf8("lasq_ksrjj_xxprg_l"));

        horizontalLayout->addWidget(lasq_ksrjj_xxprg_l);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 96, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lasq_ksrjj_xxtitle_l = new QLabel(lasq_ksrjj);
        lasq_ksrjj_xxtitle_l->setObjectName(QString::fromUtf8("lasq_ksrjj_xxtitle_l"));
        lasq_ksrjj_xxtitle_l->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lasq_ksrjj_xxtitle_l);

        verticalSpacer_2 = new QSpacerItem(20, 96, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lasq_ksrjj_exit_c = new QPushButton(lasq_ksrjj);
        lasq_ksrjj_exit_c->setObjectName(QString::fromUtf8("lasq_ksrjj_exit_c"));

        horizontalLayout_2->addWidget(lasq_ksrjj_exit_c);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(lasq_ksrjj);

        QMetaObject::connectSlotsByName(lasq_ksrjj);
    } // setupUi

    void retranslateUi(QDialog *lasq_ksrjj)
    {
        lasq_ksrjj->setWindowTitle(QCoreApplication::translate("lasq_ksrjj", "lasq_ksrjj", nullptr));
        lasq_ksrjj_xxlas_l->setText(QCoreApplication::translate("lasq_ksrjj", "=\320\233\321\203\320\264 \320\220.\320\241.=", nullptr));
        lasq_ksrjj_xxprg_l->setText(QCoreApplication::translate("lasq_ksrjj", "=lasq_ksrjj=", nullptr));
        lasq_ksrjj_xxtitle_l->setText(QCoreApplication::translate("lasq_ksrjj", "lasq_ \321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\266\321\203\321\200\320\275\320\260\320\273\320\260 \320\276\321\200\320\264\320\265\321\200\320\260 \320\267\320\260\320\263\320\273\321\203\321\210\320\272\320\260", nullptr));
        lasq_ksrjj_exit_c->setText(QCoreApplication::translate("lasq_ksrjj", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lasq_ksrjj: public Ui_lasq_ksrjj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASQ_KSRJJ_H
