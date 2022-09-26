/********************************************************************************
** Form generated from reading UI file 'lasq_cdsnn.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASQ_CDSNN_H
#define UI_LASQ_CDSNN_H

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

class Ui_lasq_cdsnn
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lasq_cdsnn_xxlas_l;
    QSpacerItem *horizontalSpacer;
    QLabel *lasq_cdsnn_xxprg_l;
    QLabel *lasq_cdsnn_xxtitle_l;
    QFrame *lasq_cdsnn_1_b;
    QFormLayout *formLayout;
    QLabel *lasq_cdsnn_firma_l;
    QLineEdit *lasq_cdsnn_firma_e;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lasq_cdsnn_exit_c;

    void setupUi(QDialog *lasq_cdsnn)
    {
        if (lasq_cdsnn->objectName().isEmpty())
            lasq_cdsnn->setObjectName(QString::fromUtf8("lasq_cdsnn"));
        lasq_cdsnn->setWindowModality(Qt::ApplicationModal);
        lasq_cdsnn->resize(400, 300);
        verticalLayout = new QVBoxLayout(lasq_cdsnn);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lasq_cdsnn_xxlas_l = new QLabel(lasq_cdsnn);
        lasq_cdsnn_xxlas_l->setObjectName(QString::fromUtf8("lasq_cdsnn_xxlas_l"));

        horizontalLayout->addWidget(lasq_cdsnn_xxlas_l);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lasq_cdsnn_xxprg_l = new QLabel(lasq_cdsnn);
        lasq_cdsnn_xxprg_l->setObjectName(QString::fromUtf8("lasq_cdsnn_xxprg_l"));

        horizontalLayout->addWidget(lasq_cdsnn_xxprg_l);


        verticalLayout->addLayout(horizontalLayout);

        lasq_cdsnn_xxtitle_l = new QLabel(lasq_cdsnn);
        lasq_cdsnn_xxtitle_l->setObjectName(QString::fromUtf8("lasq_cdsnn_xxtitle_l"));
        lasq_cdsnn_xxtitle_l->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lasq_cdsnn_xxtitle_l);

        lasq_cdsnn_1_b = new QFrame(lasq_cdsnn);
        lasq_cdsnn_1_b->setObjectName(QString::fromUtf8("lasq_cdsnn_1_b"));
        lasq_cdsnn_1_b->setFrameShape(QFrame::Panel);
        lasq_cdsnn_1_b->setFrameShadow(QFrame::Sunken);
        lasq_cdsnn_1_b->setLineWidth(1);
        lasq_cdsnn_1_b->setMidLineWidth(1);
        formLayout = new QFormLayout(lasq_cdsnn_1_b);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lasq_cdsnn_firma_l = new QLabel(lasq_cdsnn_1_b);
        lasq_cdsnn_firma_l->setObjectName(QString::fromUtf8("lasq_cdsnn_firma_l"));
        lasq_cdsnn_firma_l->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, lasq_cdsnn_firma_l);

        lasq_cdsnn_firma_e = new QLineEdit(lasq_cdsnn_1_b);
        lasq_cdsnn_firma_e->setObjectName(QString::fromUtf8("lasq_cdsnn_firma_e"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lasq_cdsnn_firma_e);


        verticalLayout->addWidget(lasq_cdsnn_1_b);

        verticalSpacer_2 = new QSpacerItem(20, 155, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lasq_cdsnn_exit_c = new QPushButton(lasq_cdsnn);
        lasq_cdsnn_exit_c->setObjectName(QString::fromUtf8("lasq_cdsnn_exit_c"));

        horizontalLayout_2->addWidget(lasq_cdsnn_exit_c);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(lasq_cdsnn);

        QMetaObject::connectSlotsByName(lasq_cdsnn);
    } // setupUi

    void retranslateUi(QDialog *lasq_cdsnn)
    {
        lasq_cdsnn->setWindowTitle(QCoreApplication::translate("lasq_cdsnn", "lasq_cdsnn", nullptr));
        lasq_cdsnn_xxlas_l->setText(QCoreApplication::translate("lasq_cdsnn", "=\320\233\321\203\320\264 \320\220.\320\241.=", nullptr));
        lasq_cdsnn_xxprg_l->setText(QCoreApplication::translate("lasq_cdsnn", "=lasq_cdsnn=", nullptr));
        lasq_cdsnn_xxtitle_l->setText(QCoreApplication::translate("lasq_cdsnn", "lasq_\320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\260\321\200\320\274\320\260", nullptr));
        lasq_cdsnn_firma_l->setText(QCoreApplication::translate("lasq_cdsnn", "lasq_\320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\270\321\200\320\274\321\213", nullptr));
        lasq_cdsnn_exit_c->setText(QCoreApplication::translate("lasq_cdsnn", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lasq_cdsnn: public Ui_lasq_cdsnn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASQ_CDSNN_H
