/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *sellers;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QTableView *sellers_table_view;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *name_edit;
    QLineEdit *surname_edit;
    QLineEdit *patronymic_edit;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *add_seller;
    QPushButton *remove_seller;
    QWidget *products;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QTableView *products_table_view;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *type_edit;
    QLineEdit *price_edit;
    QLineEdit *quantity_edit;
    QComboBox *seller_id_combobox;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *add_product;
    QPushButton *remove_product;
    QWidget *accounting;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *query_select;
    QComboBox *type_select;
    QPushButton *execute_query_btn;
    QTableWidget *accounting_table;
    QLabel *connection_lbl;
    QHBoxLayout *horizontalLayout;
    QPushButton *connect_btn;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(686, 497);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(false);
        sellers = new QWidget();
        sellers->setObjectName("sellers");
        verticalLayout_6 = new QVBoxLayout(sellers);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        sellers_table_view = new QTableView(sellers);
        sellers_table_view->setObjectName("sellers_table_view");
        sellers_table_view->horizontalHeader()->setVisible(true);
        sellers_table_view->horizontalHeader()->setCascadingSectionResizes(true);
        sellers_table_view->horizontalHeader()->setHighlightSections(true);
        sellers_table_view->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        sellers_table_view->verticalHeader()->setVisible(true);
        sellers_table_view->verticalHeader()->setHighlightSections(true);

        verticalLayout_4->addWidget(sellers_table_view);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        name_edit = new QLineEdit(sellers);
        name_edit->setObjectName("name_edit");

        horizontalLayout_3->addWidget(name_edit);

        surname_edit = new QLineEdit(sellers);
        surname_edit->setObjectName("surname_edit");

        horizontalLayout_3->addWidget(surname_edit);

        patronymic_edit = new QLineEdit(sellers);
        patronymic_edit->setObjectName("patronymic_edit");

        horizontalLayout_3->addWidget(patronymic_edit);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        add_seller = new QPushButton(sellers);
        add_seller->setObjectName("add_seller");

        horizontalLayout_8->addWidget(add_seller);

        remove_seller = new QPushButton(sellers);
        remove_seller->setObjectName("remove_seller");

        horizontalLayout_8->addWidget(remove_seller);


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout_6->addLayout(verticalLayout_5);

        tabWidget->addTab(sellers, QString());
        products = new QWidget();
        products->setObjectName("products");
        horizontalLayout_7 = new QHBoxLayout(products);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        products_table_view = new QTableView(products);
        products_table_view->setObjectName("products_table_view");
        products_table_view->horizontalHeader()->setVisible(true);
        products_table_view->horizontalHeader()->setCascadingSectionResizes(true);
        products_table_view->horizontalHeader()->setHighlightSections(true);
        products_table_view->verticalHeader()->setVisible(true);
        products_table_view->verticalHeader()->setHighlightSections(true);

        verticalLayout_3->addWidget(products_table_view);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        type_edit = new QLineEdit(products);
        type_edit->setObjectName("type_edit");

        horizontalLayout_4->addWidget(type_edit);

        price_edit = new QLineEdit(products);
        price_edit->setObjectName("price_edit");

        horizontalLayout_4->addWidget(price_edit);

        quantity_edit = new QLineEdit(products);
        quantity_edit->setObjectName("quantity_edit");

        horizontalLayout_4->addWidget(quantity_edit);

        seller_id_combobox = new QComboBox(products);
        seller_id_combobox->setObjectName("seller_id_combobox");

        horizontalLayout_4->addWidget(seller_id_combobox);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        add_product = new QPushButton(products);
        add_product->setObjectName("add_product");

        horizontalLayout_6->addWidget(add_product);

        remove_product = new QPushButton(products);
        remove_product->setObjectName("remove_product");

        horizontalLayout_6->addWidget(remove_product);


        verticalLayout_3->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_3);

        tabWidget->addTab(products, QString());
        accounting = new QWidget();
        accounting->setObjectName("accounting");
        verticalLayout_8 = new QVBoxLayout(accounting);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        query_select = new QComboBox(accounting);
        query_select->addItem(QString());
        query_select->addItem(QString());
        query_select->setObjectName("query_select");

        horizontalLayout_5->addWidget(query_select);

        type_select = new QComboBox(accounting);
        type_select->setObjectName("type_select");

        horizontalLayout_5->addWidget(type_select);

        execute_query_btn = new QPushButton(accounting);
        execute_query_btn->setObjectName("execute_query_btn");

        horizontalLayout_5->addWidget(execute_query_btn);


        verticalLayout_7->addLayout(horizontalLayout_5);

        accounting_table = new QTableWidget(accounting);
        accounting_table->setObjectName("accounting_table");

        verticalLayout_7->addWidget(accounting_table);


        verticalLayout_8->addLayout(verticalLayout_7);

        tabWidget->addTab(accounting, QString());

        verticalLayout->addWidget(tabWidget);

        connection_lbl = new QLabel(centralwidget);
        connection_lbl->setObjectName("connection_lbl");

        verticalLayout->addWidget(connection_lbl);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        connect_btn = new QPushButton(centralwidget);
        connect_btn->setObjectName("connect_btn");

        horizontalLayout->addWidget(connect_btn);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 686, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        name_edit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        surname_edit->setText(QString());
        surname_edit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Surname", nullptr));
        patronymic_edit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Patronymic", nullptr));
        add_seller->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        remove_seller->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sellers), QCoreApplication::translate("MainWindow", "Sellers", nullptr));
        type_edit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        price_edit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        quantity_edit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
        seller_id_combobox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Seller Id", nullptr));
        add_product->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        remove_product->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(products), QCoreApplication::translate("MainWindow", "Products", nullptr));
        query_select->setItemText(0, QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236 \320\277\320\276 \321\202\320\270\320\277\321\203 \321\202\320\276\320\262\320\260\321\200\320\260", nullptr));
        query_select->setItemText(1, QCoreApplication::translate("MainWindow", "\320\222\321\213\321\200\321\203\321\207\320\272\320\260", nullptr));

        type_select->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        execute_query_btn->setText(QCoreApplication::translate("MainWindow", "Execute query", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(accounting), QCoreApplication::translate("MainWindow", "Accounting", nullptr));
        connection_lbl->setText(QCoreApplication::translate("MainWindow", "Connection state: disconnected.", nullptr));
        connect_btn->setText(QCoreApplication::translate("MainWindow", "Connect to DB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
