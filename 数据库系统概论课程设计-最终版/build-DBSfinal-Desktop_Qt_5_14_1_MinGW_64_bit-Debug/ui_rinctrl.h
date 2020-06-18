/********************************************************************************
** Form generated from reading UI file 'rinctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RINCTRL_H
#define UI_RINCTRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RINctrl
{
public:
    QLineEdit *wherein;
    QLabel *label_6;
    QLineEdit *relation;
    QLabel *label;
    QLineEdit *indate;
    QLabel *label_7;
    QLabel *label_3;
    QLineEdit *id;
    QLabel *label_8;
    QTableView *tableView;
    QLineEdit *number;
    QLabel *label_2;
    QLineEdit *boolout;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *add;
    QPushButton *delete_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *change;
    QPushButton *search;

    void setupUi(QDialog *RINctrl)
    {
        if (RINctrl->objectName().isEmpty())
            RINctrl->setObjectName(QString::fromUtf8("RINctrl"));
        RINctrl->resize(587, 300);
        wherein = new QLineEdit(RINctrl);
        wherein->setObjectName(QString::fromUtf8("wherein"));
        wherein->setGeometry(QRect(450, 140, 113, 20));
        label_6 = new QLabel(RINctrl);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(370, 110, 71, 21));
        QFont font;
        font.setPointSize(11);
        label_6->setFont(font);
        relation = new QLineEdit(RINctrl);
        relation->setObjectName(QString::fromUtf8("relation"));
        relation->setGeometry(QRect(450, 50, 113, 20));
        label = new QLabel(RINctrl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 50, 81, 21));
        label->setFont(font);
        indate = new QLineEdit(RINctrl);
        indate->setObjectName(QString::fromUtf8("indate"));
        indate->setGeometry(QRect(450, 110, 113, 20));
        label_7 = new QLabel(RINctrl);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(370, 140, 71, 21));
        label_7->setFont(font);
        label_3 = new QLabel(RINctrl);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 80, 71, 21));
        label_3->setFont(font);
        id = new QLineEdit(RINctrl);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(450, 80, 113, 20));
        label_8 = new QLabel(RINctrl);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(370, 20, 71, 21));
        label_8->setFont(font);
        tableView = new QTableView(RINctrl);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 20, 321, 251));
        number = new QLineEdit(RINctrl);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(450, 20, 113, 20));
        label_2 = new QLabel(RINctrl);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 170, 71, 21));
        label_2->setFont(font);
        boolout = new QLineEdit(RINctrl);
        boolout->setObjectName(QString::fromUtf8("boolout"));
        boolout->setGeometry(QRect(450, 170, 113, 20));
        layoutWidget = new QWidget(RINctrl);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(380, 210, 194, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        add = new QPushButton(layoutWidget);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_2->addWidget(add);

        delete_2 = new QPushButton(layoutWidget);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));

        horizontalLayout_2->addWidget(delete_2);

        layoutWidget1 = new QWidget(RINctrl);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(380, 240, 194, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        change = new QPushButton(layoutWidget1);
        change->setObjectName(QString::fromUtf8("change"));

        horizontalLayout->addWidget(change);

        search = new QPushButton(layoutWidget1);
        search->setObjectName(QString::fromUtf8("search"));

        horizontalLayout->addWidget(search);


        retranslateUi(RINctrl);

        QMetaObject::connectSlotsByName(RINctrl);
    } // setupUi

    void retranslateUi(QDialog *RINctrl)
    {
        RINctrl->setWindowTitle(QCoreApplication::translate("RINctrl", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("RINctrl", "\350\277\201\345\205\245\346\227\245\346\234\237", nullptr));
        label->setText(QCoreApplication::translate("RINctrl", "\345\205\263    \347\263\273", nullptr));
        label_7->setText(QCoreApplication::translate("RINctrl", "\350\277\201 \345\205\245 \345\234\260", nullptr));
        label_3->setText(QCoreApplication::translate("RINctrl", "\350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        label_8->setText(QCoreApplication::translate("RINctrl", "\346\210\267 \347\261\215 \345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("RINctrl", "\346\230\257\345\220\246\350\277\201\345\207\272", nullptr));
        add->setText(QCoreApplication::translate("RINctrl", "\346\267\273\345\212\240", nullptr));
        delete_2->setText(QCoreApplication::translate("RINctrl", "\345\210\240\351\231\244", nullptr));
        change->setText(QCoreApplication::translate("RINctrl", "\344\277\256\346\224\271", nullptr));
        search->setText(QCoreApplication::translate("RINctrl", "\346\243\200\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RINctrl: public Ui_RINctrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RINCTRL_H
