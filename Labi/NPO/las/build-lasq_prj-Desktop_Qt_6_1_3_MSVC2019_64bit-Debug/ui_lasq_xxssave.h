/********************************************************************************
** Form generated from reading UI file 'lasq_xxssave.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASQ_XXSSAVE_H
#define UI_LASQ_XXSSAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_lasq_xxssave
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lasq_xxssave_xxlas_l;
    QSpacerItem *horizontalSpacer;
    QLabel *lasq_xxssave_xxprg_l;
    QSpacerItem *verticalSpacer;
    QLabel *lasq_xxssave_xxtitle_l;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lasq_xxssave_exit_c;

    void setupUi(QDialog *lasq_xxssave)
    {
        if (lasq_xxssave->objectName().isEmpty())
            lasq_xxssave->setObjectName(QString::fromUtf8("lasq_xxssave"));
        lasq_xxssave->setWindowModality(Qt::ApplicationModal);
        lasq_xxssave->resize(400, 300);
        verticalLayout = new QVBoxLayout(lasq_xxssave);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lasq_xxssave_xxlas_l = new QLabel(lasq_xxssave);
        lasq_xxssave_xxlas_l->setObjectName(QString::fromUtf8("lasq_xxssave_xxlas_l"));

        horizontalLayout->addWidget(lasq_xxssave_xxlas_l);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lasq_xxssave_xxprg_l = new QLabel(lasq_xxssave);
        lasq_xxssave_xxprg_l->setObjectName(QString::fromUtf8("lasq_xxssave_xxprg_l"));

        horizontalLayout->addWidget(lasq_xxssave_xxprg_l);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 96, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lasq_xxssave_xxtitle_l = new QLabel(lasq_xxssave);
        lasq_xxssave_xxtitle_l->setObjectName(QString::fromUtf8("lasq_xxssave_xxtitle_l"));
        lasq_xxssave_xxtitle_l->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lasq_xxssave_xxtitle_l);

        verticalSpacer_2 = new QSpacerItem(20, 96, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lasq_xxssave_exit_c = new QPushButton(lasq_xxssave);
        lasq_xxssave_exit_c->setObjectName(QString::fromUtf8("lasq_xxssave_exit_c"));

        horizontalLayout_2->addWidget(lasq_xxssave_exit_c);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(lasq_xxssave);

        QMetaObject::connectSlotsByName(lasq_xxssave);
    } // setupUi

    void retranslateUi(QDialog *lasq_xxssave)
    {
        lasq_xxssave->setWindowTitle(QCoreApplication::translate("lasq_xxssave", "lasq_xxssave", nullptr));
        lasq_xxssave_xxlas_l->setText(QCoreApplication::translate("lasq_xxssave", "=\320\233\321\203\320\264 \320\220.\320\241.=", nullptr));
        lasq_xxssave_xxprg_l->setText(QCoreApplication::translate("lasq_xxssave", "=lasq_xxssave=", nullptr));
        lasq_xxssave_xxtitle_l->setText(QCoreApplication::translate("lasq_xxssave", "lasq_ \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \321\201\320\270\321\201\321\202\320\265\320\274\321\213 \320\267\320\260\320\263\320\273\321\203\321\210\320\272\320\260", nullptr));
        lasq_xxssave_exit_c->setText(QCoreApplication::translate("lasq_xxssave", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lasq_xxssave: public Ui_lasq_xxssave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASQ_XXSSAVE_H
