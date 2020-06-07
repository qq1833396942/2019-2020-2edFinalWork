/********************************************************************************
** Form generated from reading UI file 'mainfunction.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFUNCTION_H
#define UI_MAINFUNCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_MainFunction
{
public:
    QTableView *tableView;
    QPushButton *search;
    QLabel *label;
    QComboBox *tableName;
    QPushButton *HK;
    QPushButton *RIN;
    QPushButton *RK;
    QPushButton *GL;

    void setupUi(QDialog *MainFunction)
    {
        if (MainFunction->objectName().isEmpty())
            MainFunction->setObjectName(QString::fromUtf8("MainFunction"));
        MainFunction->resize(688, 292);
        tableView = new QTableView(MainFunction);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 30, 431, 231));
        search = new QPushButton(MainFunction);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(580, 141, 91, 31));
        label = new QLabel(MainFunction);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 71, 16));
        tableName = new QComboBox(MainFunction);
        tableName->addItem(QString());
        tableName->addItem(QString());
        tableName->addItem(QString());
        tableName->addItem(QString());
        tableName->setObjectName(QString::fromUtf8("tableName"));
        tableName->setGeometry(QRect(470, 140, 101, 31));
        HK = new QPushButton(MainFunction);
        HK->setObjectName(QString::fromUtf8("HK"));
        HK->setGeometry(QRect(474, 62, 91, 31));
        RIN = new QPushButton(MainFunction);
        RIN->setObjectName(QString::fromUtf8("RIN"));
        RIN->setGeometry(QRect(474, 100, 91, 31));
        RK = new QPushButton(MainFunction);
        RK->setObjectName(QString::fromUtf8("RK"));
        RK->setGeometry(QRect(580, 62, 91, 31));
        GL = new QPushButton(MainFunction);
        GL->setObjectName(QString::fromUtf8("GL"));
        GL->setGeometry(QRect(580, 100, 91, 31));

        retranslateUi(MainFunction);

        tableName->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainFunction);
    } // setupUi

    void retranslateUi(QDialog *MainFunction)
    {
        MainFunction->setWindowTitle(QCoreApplication::translate("MainFunction", "Dialog", nullptr));
        search->setText(QCoreApplication::translate("MainFunction", "\351\242\204\350\247\210", nullptr));
        label->setText(QCoreApplication::translate("MainFunction", "\347\231\273\351\231\206\346\210\220\345\212\237", nullptr));
        tableName->setItemText(0, QCoreApplication::translate("MainFunction", "\346\210\267\347\261\215\344\277\241\346\201\257", nullptr));
        tableName->setItemText(1, QCoreApplication::translate("MainFunction", "\344\272\272\345\217\243\344\277\241\346\201\257", nullptr));
        tableName->setItemText(2, QCoreApplication::translate("MainFunction", "\347\256\241\347\220\206\345\221\230\344\277\241\346\201\257", nullptr));
        tableName->setItemText(3, QCoreApplication::translate("MainFunction", "\350\277\201\345\205\245\344\272\272\345\217\243\344\277\241\346\201\257", nullptr));

        HK->setText(QCoreApplication::translate("MainFunction", "\346\210\267\345\217\243\344\277\241\346\201\257\346\223\215\344\275\234", nullptr));
        RIN->setText(QCoreApplication::translate("MainFunction", "\350\277\201\345\205\245\344\272\272\345\217\243\344\277\241\346\201\257", nullptr));
        RK->setText(QCoreApplication::translate("MainFunction", "\344\272\272\345\217\243\344\277\241\346\201\257\346\223\215\344\275\234", nullptr));
        GL->setText(QCoreApplication::translate("MainFunction", "\347\256\241\347\220\206\345\221\230\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainFunction: public Ui_MainFunction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFUNCTION_H
