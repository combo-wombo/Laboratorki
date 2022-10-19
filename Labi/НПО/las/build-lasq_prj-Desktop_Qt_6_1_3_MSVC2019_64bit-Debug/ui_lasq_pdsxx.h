/********************************************************************************
** Form generated from reading UI file 'lasq_pdsxx.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASQ_PDSXX_H
#define UI_LASQ_PDSXX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_lasq_pdsxx
{
public:
    QGridLayout *gridLayout_3;
    QLabel *lasq_pdsxx_xxprg_l;
    QPushButton *lasq_pdsxx_del_c;
    QHBoxLayout *horizontalLayout;
    QLabel *lasq_pdsxx_xxlas_l;
    QSpacerItem *horizontalSpacer;
    QFrame *lasq_pdsxx_b1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lasq_pdsxx_dokk_l;
    QLineEdit *lasq_pdsxx_dokk_e;
    QLineEdit *lasq_pdsxx_dokn_e;
    QLabel *lasq_pdsxx_dokd_l;
    QLineEdit *lasq_pdsxx_dokd_e;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *lasq_pdsxx_exit_c;
    QLabel *lasq_pdsxx_xxtitle_l;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *lasq_pdsxx_grid_c;
    QPushButton *lasq_pdsxx_back_c;
    QPushButton *lasq_pdsxx_next_c;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lasq_pdsxx_add_c;
    QSpacerItem *horizontalSpacer_3;
    QFrame *lasq_pdsxx_b2;
    QGridLayout *gridLayout_2;
    QLineEdit *lasq_pdsxx_to_e;
    QLineEdit *lasq_pdsxx_rub_e;
    QPushButton *lasq_pdsxx_to_c;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lasq_pdsxx_sae_l;
    QLineEdit *lasq_pdsxx_sae_e;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lasq_pdsxx_kr_l;
    QLineEdit *lasq_pdsxx_kr_e;
    QLineEdit *lasq_pdsxx_krn_e;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lasq_pdsxx_db_l;
    QLineEdit *lasq_pdsxx_db_e;
    QLineEdit *lasq_pdsxx_dbn_e;
    QFrame *lasq_pdsxx_rzd1_l;
    QPushButton *lasq_pdsxx_pdtrj_c;
    QLabel *lasq_pdsxx_rub_l;

    void setupUi(QDialog *lasq_pdsxx)
    {
        if (lasq_pdsxx->objectName().isEmpty())
            lasq_pdsxx->setObjectName(QString::fromUtf8("lasq_pdsxx"));
        lasq_pdsxx->setWindowModality(Qt::ApplicationModal);
        lasq_pdsxx->resize(740, 540);
        gridLayout_3 = new QGridLayout(lasq_pdsxx);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lasq_pdsxx_xxprg_l = new QLabel(lasq_pdsxx);
        lasq_pdsxx_xxprg_l->setObjectName(QString::fromUtf8("lasq_pdsxx_xxprg_l"));

        gridLayout_3->addWidget(lasq_pdsxx_xxprg_l, 2, 1, 1, 1);

        lasq_pdsxx_del_c = new QPushButton(lasq_pdsxx);
        lasq_pdsxx_del_c->setObjectName(QString::fromUtf8("lasq_pdsxx_del_c"));

        gridLayout_3->addWidget(lasq_pdsxx_del_c, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lasq_pdsxx_xxlas_l = new QLabel(lasq_pdsxx);
        lasq_pdsxx_xxlas_l->setObjectName(QString::fromUtf8("lasq_pdsxx_xxlas_l"));

        horizontalLayout->addWidget(lasq_pdsxx_xxlas_l);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 1);

        lasq_pdsxx_b1 = new QFrame(lasq_pdsxx);
        lasq_pdsxx_b1->setObjectName(QString::fromUtf8("lasq_pdsxx_b1"));
        lasq_pdsxx_b1->setFrameShape(QFrame::Panel);
        lasq_pdsxx_b1->setFrameShadow(QFrame::Sunken);
        lasq_pdsxx_b1->setLineWidth(1);
        lasq_pdsxx_b1->setMidLineWidth(1);
        horizontalLayout_6 = new QHBoxLayout(lasq_pdsxx_b1);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lasq_pdsxx_dokk_l = new QLabel(lasq_pdsxx_b1);
        lasq_pdsxx_dokk_l->setObjectName(QString::fromUtf8("lasq_pdsxx_dokk_l"));
        lasq_pdsxx_dokk_l->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(lasq_pdsxx_dokk_l);

        lasq_pdsxx_dokk_e = new QLineEdit(lasq_pdsxx_b1);
        lasq_pdsxx_dokk_e->setObjectName(QString::fromUtf8("lasq_pdsxx_dokk_e"));

        horizontalLayout_6->addWidget(lasq_pdsxx_dokk_e);

        lasq_pdsxx_dokn_e = new QLineEdit(lasq_pdsxx_b1);
        lasq_pdsxx_dokn_e->setObjectName(QString::fromUtf8("lasq_pdsxx_dokn_e"));

        horizontalLayout_6->addWidget(lasq_pdsxx_dokn_e);

        lasq_pdsxx_dokd_l = new QLabel(lasq_pdsxx_b1);
        lasq_pdsxx_dokd_l->setObjectName(QString::fromUtf8("lasq_pdsxx_dokd_l"));
        lasq_pdsxx_dokd_l->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(lasq_pdsxx_dokd_l);

        lasq_pdsxx_dokd_e = new QLineEdit(lasq_pdsxx_b1);
        lasq_pdsxx_dokd_e->setObjectName(QString::fromUtf8("lasq_pdsxx_dokd_e"));

        horizontalLayout_6->addWidget(lasq_pdsxx_dokd_e);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);


        gridLayout_3->addWidget(lasq_pdsxx_b1, 5, 0, 1, 1);

        lasq_pdsxx_exit_c = new QPushButton(lasq_pdsxx);
        lasq_pdsxx_exit_c->setObjectName(QString::fromUtf8("lasq_pdsxx_exit_c"));

        gridLayout_3->addWidget(lasq_pdsxx_exit_c, 8, 1, 1, 1);

        lasq_pdsxx_xxtitle_l = new QLabel(lasq_pdsxx);
        lasq_pdsxx_xxtitle_l->setObjectName(QString::fromUtf8("lasq_pdsxx_xxtitle_l"));
        lasq_pdsxx_xxtitle_l->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lasq_pdsxx_xxtitle_l, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lasq_pdsxx_grid_c = new QPushButton(lasq_pdsxx);
        lasq_pdsxx_grid_c->setObjectName(QString::fromUtf8("lasq_pdsxx_grid_c"));

        horizontalLayout_5->addWidget(lasq_pdsxx_grid_c);

        lasq_pdsxx_back_c = new QPushButton(lasq_pdsxx);
        lasq_pdsxx_back_c->setObjectName(QString::fromUtf8("lasq_pdsxx_back_c"));

        horizontalLayout_5->addWidget(lasq_pdsxx_back_c);

        lasq_pdsxx_next_c = new QPushButton(lasq_pdsxx);
        lasq_pdsxx_next_c->setObjectName(QString::fromUtf8("lasq_pdsxx_next_c"));

        horizontalLayout_5->addWidget(lasq_pdsxx_next_c);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        lasq_pdsxx_add_c = new QPushButton(lasq_pdsxx);
        lasq_pdsxx_add_c->setObjectName(QString::fromUtf8("lasq_pdsxx_add_c"));

        horizontalLayout_5->addWidget(lasq_pdsxx_add_c);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        gridLayout_3->addLayout(horizontalLayout_5, 8, 0, 1, 1);

        lasq_pdsxx_b2 = new QFrame(lasq_pdsxx);
        lasq_pdsxx_b2->setObjectName(QString::fromUtf8("lasq_pdsxx_b2"));
        lasq_pdsxx_b2->setFrameShape(QFrame::Panel);
        lasq_pdsxx_b2->setFrameShadow(QFrame::Sunken);
        lasq_pdsxx_b2->setLineWidth(1);
        lasq_pdsxx_b2->setMidLineWidth(1);
        gridLayout_2 = new QGridLayout(lasq_pdsxx_b2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(20);
        gridLayout_2->setContentsMargins(-1, 20, -1, 20);
        lasq_pdsxx_to_e = new QLineEdit(lasq_pdsxx_b2);
        lasq_pdsxx_to_e->setObjectName(QString::fromUtf8("lasq_pdsxx_to_e"));
        lasq_pdsxx_to_e->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(lasq_pdsxx_to_e, 3, 1, 1, 1);

        lasq_pdsxx_rub_e = new QLineEdit(lasq_pdsxx_b2);
        lasq_pdsxx_rub_e->setObjectName(QString::fromUtf8("lasq_pdsxx_rub_e"));

        gridLayout_2->addWidget(lasq_pdsxx_rub_e, 1, 1, 1, 1);

        lasq_pdsxx_to_c = new QPushButton(lasq_pdsxx_b2);
        lasq_pdsxx_to_c->setObjectName(QString::fromUtf8("lasq_pdsxx_to_c"));

        gridLayout_2->addWidget(lasq_pdsxx_to_c, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(12);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lasq_pdsxx_sae_l = new QLabel(lasq_pdsxx_b2);
        lasq_pdsxx_sae_l->setObjectName(QString::fromUtf8("lasq_pdsxx_sae_l"));
        lasq_pdsxx_sae_l->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lasq_pdsxx_sae_l);

        lasq_pdsxx_sae_e = new QLineEdit(lasq_pdsxx_b2);
        lasq_pdsxx_sae_e->setObjectName(QString::fromUtf8("lasq_pdsxx_sae_e"));

        horizontalLayout_4->addWidget(lasq_pdsxx_sae_e);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout_4, 5, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(12);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lasq_pdsxx_kr_l = new QLabel(lasq_pdsxx_b2);
        lasq_pdsxx_kr_l->setObjectName(QString::fromUtf8("lasq_pdsxx_kr_l"));
        lasq_pdsxx_kr_l->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lasq_pdsxx_kr_l);

        lasq_pdsxx_kr_e = new QLineEdit(lasq_pdsxx_b2);
        lasq_pdsxx_kr_e->setObjectName(QString::fromUtf8("lasq_pdsxx_kr_e"));

        horizontalLayout_2->addWidget(lasq_pdsxx_kr_e);

        lasq_pdsxx_krn_e = new QLineEdit(lasq_pdsxx_b2);
        lasq_pdsxx_krn_e->setObjectName(QString::fromUtf8("lasq_pdsxx_krn_e"));

        horizontalLayout_2->addWidget(lasq_pdsxx_krn_e);


        gridLayout_2->addLayout(horizontalLayout_2, 4, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(12);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lasq_pdsxx_db_l = new QLabel(lasq_pdsxx_b2);
        lasq_pdsxx_db_l->setObjectName(QString::fromUtf8("lasq_pdsxx_db_l"));
        lasq_pdsxx_db_l->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lasq_pdsxx_db_l);

        lasq_pdsxx_db_e = new QLineEdit(lasq_pdsxx_b2);
        lasq_pdsxx_db_e->setObjectName(QString::fromUtf8("lasq_pdsxx_db_e"));

        horizontalLayout_3->addWidget(lasq_pdsxx_db_e);

        lasq_pdsxx_dbn_e = new QLineEdit(lasq_pdsxx_b2);
        lasq_pdsxx_dbn_e->setObjectName(QString::fromUtf8("lasq_pdsxx_dbn_e"));

        horizontalLayout_3->addWidget(lasq_pdsxx_dbn_e);


        gridLayout_2->addLayout(horizontalLayout_3, 4, 1, 1, 1);

        lasq_pdsxx_rzd1_l = new QFrame(lasq_pdsxx_b2);
        lasq_pdsxx_rzd1_l->setObjectName(QString::fromUtf8("lasq_pdsxx_rzd1_l"));
        lasq_pdsxx_rzd1_l->setFrameShape(QFrame::HLine);
        lasq_pdsxx_rzd1_l->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(lasq_pdsxx_rzd1_l, 2, 0, 1, 3);

        lasq_pdsxx_pdtrj_c = new QPushButton(lasq_pdsxx_b2);
        lasq_pdsxx_pdtrj_c->setObjectName(QString::fromUtf8("lasq_pdsxx_pdtrj_c"));

        gridLayout_2->addWidget(lasq_pdsxx_pdtrj_c, 6, 0, 1, 3);

        lasq_pdsxx_rub_l = new QLabel(lasq_pdsxx_b2);
        lasq_pdsxx_rub_l->setObjectName(QString::fromUtf8("lasq_pdsxx_rub_l"));
        lasq_pdsxx_rub_l->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(lasq_pdsxx_rub_l, 1, 0, 1, 1);


        gridLayout_3->addWidget(lasq_pdsxx_b2, 7, 0, 1, 1);

        QWidget::setTabOrder(lasq_pdsxx_dokk_e, lasq_pdsxx_dokn_e);
        QWidget::setTabOrder(lasq_pdsxx_dokn_e, lasq_pdsxx_dokd_e);
        QWidget::setTabOrder(lasq_pdsxx_dokd_e, lasq_pdsxx_rub_e);
        QWidget::setTabOrder(lasq_pdsxx_rub_e, lasq_pdsxx_to_c);
        QWidget::setTabOrder(lasq_pdsxx_to_c, lasq_pdsxx_to_e);
        QWidget::setTabOrder(lasq_pdsxx_to_e, lasq_pdsxx_db_e);
        QWidget::setTabOrder(lasq_pdsxx_db_e, lasq_pdsxx_dbn_e);
        QWidget::setTabOrder(lasq_pdsxx_dbn_e, lasq_pdsxx_kr_e);
        QWidget::setTabOrder(lasq_pdsxx_kr_e, lasq_pdsxx_krn_e);
        QWidget::setTabOrder(lasq_pdsxx_krn_e, lasq_pdsxx_sae_e);
        QWidget::setTabOrder(lasq_pdsxx_sae_e, lasq_pdsxx_pdtrj_c);
        QWidget::setTabOrder(lasq_pdsxx_pdtrj_c, lasq_pdsxx_grid_c);
        QWidget::setTabOrder(lasq_pdsxx_grid_c, lasq_pdsxx_back_c);
        QWidget::setTabOrder(lasq_pdsxx_back_c, lasq_pdsxx_next_c);
        QWidget::setTabOrder(lasq_pdsxx_next_c, lasq_pdsxx_add_c);
        QWidget::setTabOrder(lasq_pdsxx_add_c, lasq_pdsxx_del_c);
        QWidget::setTabOrder(lasq_pdsxx_del_c, lasq_pdsxx_exit_c);

        retranslateUi(lasq_pdsxx);

        QMetaObject::connectSlotsByName(lasq_pdsxx);
    } // setupUi

    void retranslateUi(QDialog *lasq_pdsxx)
    {
        lasq_pdsxx->setWindowTitle(QCoreApplication::translate("lasq_pdsxx", "lasq_pdsxx", nullptr));
        lasq_pdsxx_xxprg_l->setText(QCoreApplication::translate("lasq_pdsxx", "=lasq_pdsxx=", nullptr));
        lasq_pdsxx_del_c->setText(QCoreApplication::translate("lasq_pdsxx", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        lasq_pdsxx_xxlas_l->setText(QCoreApplication::translate("lasq_pdsxx", "=\320\233\321\203\320\264 \320\220.\320\241.=", nullptr));
        lasq_pdsxx_dokk_l->setText(QCoreApplication::translate("lasq_pdsxx", "lasq_\320\272\320\276\320\264 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", nullptr));
        lasq_pdsxx_dokd_l->setText(QCoreApplication::translate("lasq_pdsxx", "\320\276\321\202", nullptr));
        lasq_pdsxx_exit_c->setText(QCoreApplication::translate("lasq_pdsxx", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        lasq_pdsxx_xxtitle_l->setText(QCoreApplication::translate("lasq_pdsxx", "lasq_\320\262\320\262\320\276\320\264 \320\270 \321\200\320\260\320\267\320\275\320\276\321\201\320\272\320\260 \320\277\320\265\321\200\320\262\320\270\321\207\320\275\321\213\321\205 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\276\320\262", nullptr));
        lasq_pdsxx_grid_c->setText(QCoreApplication::translate("lasq_pdsxx", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        lasq_pdsxx_back_c->setText(QCoreApplication::translate("lasq_pdsxx", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        lasq_pdsxx_next_c->setText(QCoreApplication::translate("lasq_pdsxx", "\320\222\320\277\320\265\321\200\320\265\320\264", nullptr));
        lasq_pdsxx_add_c->setText(QCoreApplication::translate("lasq_pdsxx", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        lasq_pdsxx_to_c->setText(QCoreApplication::translate("lasq_pdsxx", "lasq_\320\276\320\277\320\265\321\200\320\260\321\206\320\270\321\217", nullptr));
        lasq_pdsxx_sae_l->setText(QCoreApplication::translate("lasq_pdsxx", "lasq_\320\241\320\260\320\265", nullptr));
        lasq_pdsxx_kr_l->setText(QCoreApplication::translate("lasq_pdsxx", "lasq_\320\232\321\200", nullptr));
        lasq_pdsxx_db_l->setText(QCoreApplication::translate("lasq_pdsxx", "lasq_\320\224\320\261", nullptr));
        lasq_pdsxx_pdtrj_c->setText(QCoreApplication::translate("lasq_pdsxx", "lasq_\321\200\320\260\320\267\320\275\320\276\321\201\320\272\320\260 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260 (\320\267\320\260\320\275\320\265\321\201\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\320\262\320\276\320\264\320\276\320\272 \320\262 \321\200\320\265\320\263 \320\266\321\203\321\200\320\275\320\260\320\273)", nullptr));
        lasq_pdsxx_rub_l->setText(QCoreApplication::translate("lasq_pdsxx", "lasq_\321\201\321\203\320\274\320\274\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lasq_pdsxx: public Ui_lasq_pdsxx {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASQ_PDSXX_H
