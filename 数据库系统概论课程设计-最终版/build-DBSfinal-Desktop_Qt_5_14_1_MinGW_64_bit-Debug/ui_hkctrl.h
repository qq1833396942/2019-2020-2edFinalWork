/********************************************************************************
** Form generated from reading UI file 'hkctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HKCTRL_H
#define UI_HKCTRL_H

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

class Ui_HKctrl
{
public:
    QLineEdit *wherein;
    QLabel *label_5;
    QTableView *tableView;
    QLabel *label_8;
    QLineEdit *id;
    QLineEdit *number;
    QLabel *label_7;
    QLabel *label_3;
    QLineEdit *indate;
    QLineEdit *ads;
    QLabel *label;
    QLabel *label_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *add;
    QPushButton *delete_2;
    QPushButton *change;
    QPushButton *search;
    QLabel *label_6;
    QLineEdit *nation;
    QLineEdit *name;
    QLabel *label_2;
    QLineEdit *outdate;
    QLabel *label_9;
    QLineEdit *whereout;

    void setupUi(QDialog *HKctrl)
    {
        if (HKctrl->objectName().isEmpty())
            HKctrl->setObjectName(QString::fromUtf8("HKctrl"));
        HKctrl->resize(607, 317);
        wherein = new QLineEdit(HKctrl);
        wherein->setObjectName(QString::fromUtf8("wherein"));
        wherein->setGeometry(QRect(460, 210, 113, 20));
        label_5 = new QLabel(HKctrl);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(380, 150, 71, 21));
        QFont font;
        font.setPointSize(11);
        label_5->setFont(font);
        tableView = new QTableView(HKctrl);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 30, 321, 211));
        label_8 = new QLabel(HKctrl);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(380, 30, 71, 21));
        label_8->setFont(font);
        id = new QLineEdit(HKctrl);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(460, 90, 113, 20));
        number = new QLineEdit(HKctrl);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(460, 30, 113, 20));
        label_7 = new QLabel(HKctrl);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(380, 210, 71, 21));
        label_7->setFont(font);
        label_3 = new QLabel(HKctrl);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 90, 71, 21));
        label_3->setFont(font);
        indate = new QLineEdit(HKctrl);
        indate->setObjectName(QString::fromUtf8("indate"));
        indate->setGeometry(QRect(460, 180, 113, 20));
        ads = new QLineEdit(HKctrl);
        ads->setObjectName(QString::fromUtf8("ads"));
        ads->setGeometry(QRect(460, 150, 113, 20));
        label = new QLabel(HKctrl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 60, 81, 21));
        label->setFont(font);
        label_4 = new QLabel(HKctrl);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(380, 120, 71, 21));
        label_4->setFont(font);
        layoutWidget = new QWidget(HKctrl);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 260, 351, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        add = new QPushButton(layoutWidget);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout->addWidget(add);

        delete_2 = new QPushButton(layoutWidget);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));

        horizontalLayout->addWidget(delete_2);

        change = new QPushButton(layoutWidget);
        change->setObjectName(QString::fromUtf8("change"));

        horizontalLayout->addWidget(change);

        search = new QPushButton(layoutWidget);
        search->setObjectName(QString::fromUtf8("search"));

        horizontalLayout->addWidget(search);

        label_6 = new QLabel(HKctrl);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(380, 180, 71, 21));
        label_6->setFont(font);
        nation = new QLineEdit(HKctrl);
        nation->setObjectName(QString::fromUtf8("nation"));
        nation->setGeometry(QRect(460, 120, 113, 20));
        name = new QLineEdit(HKctrl);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(460, 60, 113, 20));
        label_2 = new QLabel(HKctrl);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 240, 71, 21));
        label_2->setFont(font);
        outdate = new QLineEdit(HKctrl);
        outdate->setObjectName(QString::fromUtf8("outdate"));
        outdate->setGeometry(QRect(460, 240, 113, 20));
        label_9 = new QLabel(HKctrl);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(380, 270, 71, 21));
        label_9->setFont(font);
        whereout = new QLineEdit(HKctrl);
        whereout->setObjectName(QString::fromUtf8("whereout"));
        whereout->setGeometry(QRect(460, 270, 113, 20));

        retranslateUi(HKctrl);

        QMetaObject::connectSlotsByName(HKctrl);
    } // setupUi

    void retranslateUi(QDialog *HKctrl)
    {
        HKctrl->setWindowTitle(QCoreApplication::translate("HKctrl", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("HKctrl", "\347\216\260 \345\261\205 \345\234\260", nullptr));
        label_8->setText(QCoreApplication::translate("HKctrl", "\346\210\267 \347\261\215 \345\217\267", nullptr));
        label_7->setText(QCoreApplication::translate("HKctrl", "\350\277\201 \345\205\245 \345\234\260", nullptr));
        label_3->setText(QCoreApplication::translate("HKctrl", "\350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        label->setText(QCoreApplication::translate("HKctrl", "\345\247\223    \345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("HKctrl", "\346\260\221    \346\227\217", nullptr));
        add->setText(QCoreApplication::translate("HKctrl", "\346\267\273\345\212\240", nullptr));
        delete_2->setText(QCoreApplication::translate("HKctrl", "\345\210\240\351\231\244", nullptr));
        change->setText(QCoreApplication::translate("HKctrl", "\344\277\256\346\224\271", nullptr));
        search->setText(QCoreApplication::translate("HKctrl", "\346\243\200\347\264\242", nullptr));
        label_6->setText(QCoreApplication::translate("HKctrl", "\350\277\201\345\205\245\346\227\245\346\234\237", nullptr));
        label_2->setText(QCoreApplication::translate("HKctrl", "\350\277\201\345\207\272\346\227\245\346\234\237", nullptr));
        label_9->setText(QCoreApplication::translate("HKctrl", "\350\277\201 \345\207\272 \345\234\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HKctrl: public Ui_HKctrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HKCTRL_H
