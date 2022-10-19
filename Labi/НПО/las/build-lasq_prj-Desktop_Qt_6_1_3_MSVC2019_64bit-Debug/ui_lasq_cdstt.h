/********************************************************************************
** Form generated from reading UI file 'lasq_cdstt.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASQ_CDSTT_H
#define UI_LASQ_CDSTT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_lasq_cdstt
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lasq_cdstt_xxlas_l;
    QSpacerItem *horizontalSpacer;
    QLabel *lasq_cdstt_xxprg_l;
    QLabel *lasq_cdstt_xxtitle_l;
    QFrame *lasq_cdstt_1_b;
    QFormLayout *formLayout;
    QLabel *lasq_cdstt_datat_l;
    QLineEdit *lasq_cdstt_datat_e;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lasq_cdstt_exit_c;

    void setupUi(QDialog *lasq_cdstt)
    {
        if (lasq_cdstt->objectName().isEmpty())
            lasq_cdstt->setObjectName(QString::fromUtf8("lasq_cdstt"));
        lasq_cdstt->setWindowModality(Qt::ApplicationModal);
        lasq_cdstt->resize(400, 300);
        verticalLayout = new QVBoxLayout(lasq_cdstt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, -1, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lasq_cdstt_xxlas_l = new QLabel(lasq_cdstt);
        lasq_cdstt_xxlas_l->setObjectName(QString::fromUtf8("lasq_cdstt_xxlas_l"));

        horizontalLayout->addWidget(lasq_cdstt_xxlas_l);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lasq_cdstt_xxprg_l = new QLabel(lasq_cdstt);
        lasq_cdstt_xxprg_l->setObjectName(QString::fromUtf8("lasq_cdstt_xxprg_l"));

        horizontalLayout->addWidget(lasq_cdstt_xxprg_l);


        verticalLayout->addLayout(horizontalLayout);

        lasq_cdstt_xxtitle_l = new QLabel(lasq_cdstt);
        lasq_cdstt_xxtitle_l->setObjectName(QString::fromUtf8("lasq_cdstt_xxtitle_l"));
        lasq_cdstt_xxtitle_l->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lasq_cdstt_xxtitle_l);

        lasq_cdstt_1_b = new QFrame(lasq_cdstt);
        lasq_cdstt_1_b->setObjectName(QString::fromUtf8("lasq_cdstt_1_b"));
        lasq_cdstt_1_b->setFrameShape(QFrame::Panel);
        lasq_cdstt_1_b->setFrameShadow(QFrame::Sunken);
        lasq_cdstt_1_b->setLineWidth(1);
        lasq_cdstt_1_b->setMidLineWidth(1);
        formLayout = new QFormLayout(lasq_cdstt_1_b);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lasq_cdstt_datat_l = new QLabel(lasq_cdstt_1_b);
        lasq_cdstt_datat_l->setObjectName(QString::fromUtf8("lasq_cdstt_datat_l"));
        lasq_cdstt_datat_l->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, lasq_cdstt_datat_l);

        lasq_cdstt_datat_e = new QLineEdit(lasq_cdstt_1_b);
        lasq_cdstt_datat_e->setObjectName(QString::fromUtf8("lasq_cdstt_datat_e"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lasq_cdstt_datat_e);


        verticalLayout->addWidget(lasq_cdstt_1_b);

        verticalSpacer_2 = new QSpacerItem(20, 155, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lasq_cdstt_exit_c = new QPushButton(lasq_cdstt);
        lasq_cdstt_exit_c->setObjectName(QString::fromUtf8("lasq_cdstt_exit_c"));

        horizontalLayout_2->addWidget(lasq_cdstt_exit_c);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(lasq_cdstt);

        QMetaObject::connectSlotsByName(lasq_cdstt);
    } // setupUi

    void retranslateUi(QDialog *lasq_cdstt)
    {
        lasq_cdstt->setWindowTitle(QCoreApplication::translate("lasq_cdstt", "lasq_cdstt", nullptr));
        lasq_cdstt_xxlas_l->setText(QCoreApplication::translate("lasq_cdstt", "=\320\233\321\203\320\264 \320\220.\320\241.=", nullptr));
        lasq_cdstt_xxprg_l->setText(QCoreApplication::translate("lasq_cdstt", "=lasq_cdsnn=", nullptr));
        lasq_cdstt_xxtitle_l->setText(QCoreApplication::translate("lasq_cdstt", "lasq_\320\262\320\262\320\276\320\264 \321\202\320\265\320\272\321\203\321\211\320\265\320\271 \320\264\320\260\321\202\321\213", nullptr));
        lasq_cdstt_datat_l->setText(QCoreApplication::translate("lasq_cdstt", "lasq_\321\202\320\265\320\272\321\203\321\211\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        lasq_cdstt_exit_c->setText(QCoreApplication::translate("lasq_cdstt", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lasq_cdstt: public Ui_lasq_cdstt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASQ_CDSTT_H
