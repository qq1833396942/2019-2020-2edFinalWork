/********************************************************************************
** Form generated from reading UI file 'rkctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RKCTRL_H
#define UI_RKCTRL_H

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

class Ui_RKctrl
{
public:
    QTableView *tableView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *name;
    QLineEdit *sex;
    QLineEdit *id;
    QLineEdit *nation;
    QLineEdit *province;
    QLineEdit *birdate;
    QLineEdit *birplace;
    QLineEdit *ads;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *add;
    QPushButton *delete_2;
    QPushButton *change;
    QPushButton *search;

    void setupUi(QDialog *RKctrl)
    {
        if (RKctrl->objectName().isEmpty())
            RKctrl->setObjectName(QString::fromUtf8("RKctrl"));
        RKctrl->resize(604, 287);
        tableView = new QTableView(RKctrl);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 20, 321, 191));
        label = new QLabel(RKctrl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 20, 81, 21));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(RKctrl);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 50, 71, 21));
        label_2->setFont(font);
        label_3 = new QLabel(RKctrl);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 80, 61, 21));
        label_3->setFont(font);
        label_4 = new QLabel(RKctrl);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(380, 110, 71, 21));
        label_4->setFont(font);
        label_5 = new QLabel(RKctrl);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(380, 140, 71, 21));
        label_5->setFont(font);
        label_6 = new QLabel(RKctrl);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(380, 170, 71, 21));
        label_6->setFont(font);
        label_7 = new QLabel(RKctrl);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(380, 200, 71, 21));
        label_7->setFont(font);
        label_8 = new QLabel(RKctrl);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(380, 230, 71, 21));
        label_8->setFont(font);
        name = new QLineEdit(RKctrl);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(460, 20, 113, 20));
        sex = new QLineEdit(RKctrl);
        sex->setObjectName(QString::fromUtf8("sex"));
        sex->setGeometry(QRect(460, 50, 113, 20));
        id = new QLineEdit(RKctrl);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(460, 80, 113, 20));
        nation = new QLineEdit(RKctrl);
        nation->setObjectName(QString::fromUtf8("nation"));
        nation->setGeometry(QRect(460, 110, 113, 20));
        province = new QLineEdit(RKctrl);
        province->setObjectName(QString::fromUtf8("province"));
        province->setGeometry(QRect(460, 140, 113, 20));
        birdate = new QLineEdit(RKctrl);
        birdate->setObjectName(QString::fromUtf8("birdate"));
        birdate->setGeometry(QRect(460, 170, 113, 20));
        birplace = new QLineEdit(RKctrl);
        birplace->setObjectName(QString::fromUtf8("birplace"));
        birplace->setGeometry(QRect(460, 200, 113, 20));
        ads = new QLineEdit(RKctrl);
        ads->setObjectName(QString::fromUtf8("ads"));
        ads->setGeometry(QRect(460, 230, 113, 20));
        widget = new QWidget(RKctrl);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 220, 320, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        add = new QPushButton(widget);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout->addWidget(add);

        delete_2 = new QPushButton(widget);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));

        horizontalLayout->addWidget(delete_2);

        change = new QPushButton(widget);
        change->setObjectName(QString::fromUtf8("change"));

        horizontalLayout->addWidget(change);

        search = new QPushButton(widget);
        search->setObjectName(QString::fromUtf8("search"));

        horizontalLayout->addWidget(search);


        retranslateUi(RKctrl);

        QMetaObject::connectSlotsByName(RKctrl);
    } // setupUi

    void retranslateUi(QDialog *RKctrl)
    {
        RKctrl->setWindowTitle(QCoreApplication::translate("RKctrl", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RKctrl", "\345\247\223    \345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("RKctrl", "\346\200\247    \345\210\253", nullptr));
        label_3->setText(QCoreApplication::translate("RKctrl", "\350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("RKctrl", "\346\260\221    \346\227\217", nullptr));
        label_5->setText(QCoreApplication::translate("RKctrl", "\347\245\226    \347\261\215", nullptr));
        label_6->setText(QCoreApplication::translate("RKctrl", "\347\224\237    \346\227\245", nullptr));
        label_7->setText(QCoreApplication::translate("RKctrl", "\345\207\272 \347\224\237 \345\234\260", nullptr));
        label_8->setText(QCoreApplication::translate("RKctrl", "\347\216\260 \345\261\205 \345\234\260", nullptr));
        add->setText(QCoreApplication::translate("RKctrl", "\346\267\273\345\212\240", nullptr));
        delete_2->setText(QCoreApplication::translate("RKctrl", "\345\210\240\351\231\244", nullptr));
        change->setText(QCoreApplication::translate("RKctrl", "\344\277\256\346\224\271", nullptr));
        search->setText(QCoreApplication::translate("RKctrl", "\346\243\200\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RKctrl: public Ui_RKctrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RKCTRL_H
