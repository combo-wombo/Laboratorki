/********************************************************************************
** Form generated from reading UI file 'lasq_rjtks.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASQ_RJTKS_H
#define UI_LASQ_RJTKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_lasq_rjtks
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lasq_rjtks_xxlas_l;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lasq_rjtks_xxprg_l;
    QLabel *lasq_rjtks_xxtitle_l;
    QFrame *lasq_rjtks_b1;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *lasq_rjtks_gridrj_c;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lasq_rjtks_wk_c;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *lasq_rjtks_gridks_c;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *lasq_rjtks_exit_c;

    void setupUi(QDialog *lasq_rjtks)
    {
        if (lasq_rjtks->objectName().isEmpty())
            lasq_rjtks->setObjectName(QString::fromUtf8("lasq_rjtks"));
        lasq_rjtks->setWindowModality(Qt::ApplicationModal);
        lasq_rjtks->resize(618, 392);
        verticalLayout = new QVBoxLayout(lasq_rjtks);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lasq_rjtks_xxlas_l = new QLabel(lasq_rjtks);
        lasq_rjtks_xxlas_l->setObjectName(QString::fromUtf8("lasq_rjtks_xxlas_l"));

        horizontalLayout->addWidget(lasq_rjtks_xxlas_l);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        lasq_rjtks_xxprg_l = new QLabel(lasq_rjtks);
        lasq_rjtks_xxprg_l->setObjectName(QString::fromUtf8("lasq_rjtks_xxprg_l"));

        horizontalLayout->addWidget(lasq_rjtks_xxprg_l);


        verticalLayout->addLayout(horizontalLayout);

        lasq_rjtks_xxtitle_l = new QLabel(lasq_rjtks);
        lasq_rjtks_xxtitle_l->setObjectName(QString::fromUtf8("lasq_rjtks_xxtitle_l"));
        lasq_rjtks_xxtitle_l->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lasq_rjtks_xxtitle_l);

        lasq_rjtks_b1 = new QFrame(lasq_rjtks);
        lasq_rjtks_b1->setObjectName(QString::fromUtf8("lasq_rjtks_b1"));
        lasq_rjtks_b1->setFrameShape(QFrame::Panel);
        lasq_rjtks_b1->setFrameShadow(QFrame::Sunken);
        lasq_rjtks_b1->setLineWidth(1);
        lasq_rjtks_b1->setMidLineWidth(1);
        gridLayout_2 = new QGridLayout(lasq_rjtks_b1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 50, -1, 50);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        lasq_rjtks_gridrj_c = new QPushButton(lasq_rjtks_b1);
        lasq_rjtks_gridrj_c->setObjectName(QString::fromUtf8("lasq_rjtks_gridrj_c"));

        horizontalLayout_5->addWidget(lasq_rjtks_gridrj_c);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        lasq_rjtks_wk_c = new QPushButton(lasq_rjtks_b1);
        lasq_rjtks_wk_c->setObjectName(QString::fromUtf8("lasq_rjtks_wk_c"));

        horizontalLayout_5->addWidget(lasq_rjtks_wk_c);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        lasq_rjtks_gridks_c = new QPushButton(lasq_rjtks_b1);
        lasq_rjtks_gridks_c->setObjectName(QString::fromUtf8("lasq_rjtks_gridks_c"));

        horizontalLayout_5->addWidget(lasq_rjtks_gridks_c);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        verticalLayout->addWidget(lasq_rjtks_b1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        lasq_rjtks_exit_c = new QPushButton(lasq_rjtks);
        lasq_rjtks_exit_c->setObjectName(QString::fromUtf8("lasq_rjtks_exit_c"));

        horizontalLayout_2->addWidget(lasq_rjtks_exit_c);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(lasq_rjtks);

        QMetaObject::connectSlotsByName(lasq_rjtks);
    } // setupUi

    void retranslateUi(QDialog *lasq_rjtks)
    {
        lasq_rjtks->setWindowTitle(QCoreApplication::translate("lasq_rjtks", "lasq_rjtks", nullptr));
        lasq_rjtks_xxlas_l->setText(QCoreApplication::translate("lasq_rjtks", "=\320\233\321\203\320\264 \320\220.\320\241.=", nullptr));
        lasq_rjtks_xxprg_l->setText(QCoreApplication::translate("lasq_rjtks", "=lasq_tosxx=", nullptr));
        lasq_rjtks_xxtitle_l->setText(QCoreApplication::translate("lasq_rjtks", "lasq_\321\202\320\270\320\277\320\276\320\262\321\213\320\265 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", nullptr));
        lasq_rjtks_gridrj_c->setText(QCoreApplication::translate("lasq_rjtks", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\240\320\226", nullptr));
        lasq_rjtks_wk_c->setText(QCoreApplication::translate("lasq_rjtks", "\320\244\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\232\320\241 \320\270\320\267 \320\240\320\226", nullptr));
        lasq_rjtks_gridks_c->setText(QCoreApplication::translate("lasq_rjtks", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\232\320\241", nullptr));
        lasq_rjtks_exit_c->setText(QCoreApplication::translate("lasq_rjtks", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lasq_rjtks: public Ui_lasq_rjtks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASQ_RJTKS_H
