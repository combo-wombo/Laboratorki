/********************************************************************************
** Form generated from reading UI file 'lasq_xxsrest.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASQ_XXSREST_H
#define UI_LASQ_XXSREST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_lasq_xxsrest
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lasq_xxsrest_xxlas_l;
    QSpacerItem *horizontalSpacer;
    QLabel *lasq_xxsrest_xxprg_l;
    QSpacerItem *verticalSpacer;
    QLabel *lasq_xxsrest_xxtitle_l;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lasq_xxsrest_exit_c;

    void setupUi(QDialog *lasq_xxsrest)
    {
        if (lasq_xxsrest->objectName().isEmpty())
            lasq_xxsrest->setObjectName(QString::fromUtf8("lasq_xxsrest"));
        lasq_xxsrest->setWindowModality(Qt::ApplicationModal);
        lasq_xxsrest->resize(400, 300);
        verticalLayout = new QVBoxLayout(lasq_xxsrest);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lasq_xxsrest_xxlas_l = new QLabel(lasq_xxsrest);
        lasq_xxsrest_xxlas_l->setObjectName(QString::fromUtf8("lasq_xxsrest_xxlas_l"));

        horizontalLayout->addWidget(lasq_xxsrest_xxlas_l);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lasq_xxsrest_xxprg_l = new QLabel(lasq_xxsrest);
        lasq_xxsrest_xxprg_l->setObjectName(QString::fromUtf8("lasq_xxsrest_xxprg_l"));

        horizontalLayout->addWidget(lasq_xxsrest_xxprg_l);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lasq_xxsrest_xxtitle_l = new QLabel(lasq_xxsrest);
        lasq_xxsrest_xxtitle_l->setObjectName(QString::fromUtf8("lasq_xxsrest_xxtitle_l"));
        lasq_xxsrest_xxtitle_l->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lasq_xxsrest_xxtitle_l);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lasq_xxsrest_exit_c = new QPushButton(lasq_xxsrest);
        lasq_xxsrest_exit_c->setObjectName(QString::fromUtf8("lasq_xxsrest_exit_c"));

        horizontalLayout_2->addWidget(lasq_xxsrest_exit_c);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(lasq_xxsrest);

        QMetaObject::connectSlotsByName(lasq_xxsrest);
    } // setupUi

    void retranslateUi(QDialog *lasq_xxsrest)
    {
        lasq_xxsrest->setWindowTitle(QCoreApplication::translate("lasq_xxsrest", "lasq_xxsrest", nullptr));
        lasq_xxsrest_xxlas_l->setText(QCoreApplication::translate("lasq_xxsrest", "=\320\233\321\203\320\264 \320\220.\320\241.=", nullptr));
        lasq_xxsrest_xxprg_l->setText(QCoreApplication::translate("lasq_xxsrest", "=lasq_xxsrest=", nullptr));
        lasq_xxsrest_xxtitle_l->setText(QCoreApplication::translate("lasq_xxsrest", "lasq_ \320\262\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\320\270\321\201\321\202\320\265\320\274\321\213 \320\267\320\260\320\263\320\273\321\203\321\210\320\272\320\260", nullptr));
        lasq_xxsrest_exit_c->setText(QCoreApplication::translate("lasq_xxsrest", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lasq_xxsrest: public Ui_lasq_xxsrest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASQ_XXSREST_H
