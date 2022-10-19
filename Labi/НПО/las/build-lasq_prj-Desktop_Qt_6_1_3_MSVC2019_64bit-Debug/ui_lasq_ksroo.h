/********************************************************************************
** Form generated from reading UI file 'lasq_ksroo.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASQ_KSROO_H
#define UI_LASQ_KSROO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_lasq_ksroo
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *lasq_ksroo_qr;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *lasq_ksroo_print_c;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *lasq_ksroo_exit_c;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *lasq_ksroo)
    {
        if (lasq_ksroo->objectName().isEmpty())
            lasq_ksroo->setObjectName(QString::fromUtf8("lasq_ksroo"));
        lasq_ksroo->setWindowModality(Qt::ApplicationModal);
        lasq_ksroo->resize(748, 488);
        verticalLayout = new QVBoxLayout(lasq_ksroo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lasq_ksroo_qr = new QTextBrowser(lasq_ksroo);
        lasq_ksroo_qr->setObjectName(QString::fromUtf8("lasq_ksroo_qr"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier")});
        font.setPointSize(10);
        lasq_ksroo_qr->setFont(font);

        verticalLayout->addWidget(lasq_ksroo_qr);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lasq_ksroo_print_c = new QPushButton(lasq_ksroo);
        lasq_ksroo_print_c->setObjectName(QString::fromUtf8("lasq_ksroo_print_c"));

        horizontalLayout->addWidget(lasq_ksroo_print_c);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        lasq_ksroo_exit_c = new QPushButton(lasq_ksroo);
        lasq_ksroo_exit_c->setObjectName(QString::fromUtf8("lasq_ksroo_exit_c"));

        horizontalLayout->addWidget(lasq_ksroo_exit_c);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(lasq_ksroo);

        QMetaObject::connectSlotsByName(lasq_ksroo);
    } // setupUi

    void retranslateUi(QDialog *lasq_ksroo)
    {
        lasq_ksroo->setWindowTitle(QCoreApplication::translate("lasq_ksroo", "lasq_ksroo", nullptr));
        lasq_ksroo_print_c->setText(QCoreApplication::translate("lasq_ksroo", "\320\237\320\265\321\207\320\260\321\202\321\214", nullptr));
        lasq_ksroo_exit_c->setText(QCoreApplication::translate("lasq_ksroo", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lasq_ksroo: public Ui_lasq_ksroo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASQ_KSROO_H
