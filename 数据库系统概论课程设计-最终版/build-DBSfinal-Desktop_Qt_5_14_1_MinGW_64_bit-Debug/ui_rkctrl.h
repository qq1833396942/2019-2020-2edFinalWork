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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *add;
    QPushButton *delete_2;
    QPushButton *change;
    QPushButton *search;
    QLabel *label_9;
    QLineEdit *number;
    QLabel *label_10;
    QLineEdit *indate;
    QLabel *label_11;
    QLineEdit *wherein;
    QLabel *label_12;
    QLineEdit *relation;
    QLabel *label_13;
    QLineEdit *boolout;

    void setupUi(QDialog *RKctrl)
    {
        if (RKctrl->objectName().isEmpty())
            RKctrl->setObjectName(QString::fromUtf8("RKctrl"));
        RKctrl->resize(593, 403);
        tableView = new QTableView(RKctrl);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 20, 341, 331));
        label = new QLabel(RKctrl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 40, 81, 21));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(RKctrl);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 70, 71, 21));
        label_2->setFont(font);
        label_3 = new QLabel(RKctrl);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 100, 71, 21));
        label_3->setFont(font);
        label_4 = new QLabel(RKctrl);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(380, 130, 71, 21));
        label_4->setFont(font);
        label_5 = new QLabel(RKctrl);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(380, 160, 71, 21));
        label_5->setFont(font);
        label_6 = new QLabel(RKctrl);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(380, 190, 71, 21));
        label_6->setFont(font);
        label_7 = new QLabel(RKctrl);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(380, 220, 71, 21));
        label_7->setFont(font);
        label_8 = new QLabel(RKctrl);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(380, 250, 71, 21));
        label_8->setFont(font);
        name = new QLineEdit(RKctrl);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(460, 40, 113, 20));
        sex = new QLineEdit(RKctrl);
        sex->setObjectName(QString::fromUtf8("sex"));
        sex->setGeometry(QRect(460, 70, 113, 20));
        id = new QLineEdit(RKctrl);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(460, 100, 113, 20));
        nation = new QLineEdit(RKctrl);
        nation->setObjectName(QString::fromUtf8("nation"));
        nation->setGeometry(QRect(460, 130, 113, 20));
        province = new QLineEdit(RKctrl);
        province->setObjectName(QString::fromUtf8("province"));
        province->setGeometry(QRect(460, 160, 113, 20));
        birdate = new QLineEdit(RKctrl);
        birdate->setObjectName(QString::fromUtf8("birdate"));
        birdate->setGeometry(QRect(460, 190, 113, 20));
        birplace = new QLineEdit(RKctrl);
        birplace->setObjectName(QString::fromUtf8("birplace"));
        birplace->setGeometry(QRect(460, 220, 113, 20));
        ads = new QLineEdit(RKctrl);
        ads->setObjectName(QString::fromUtf8("ads"));
        ads->setGeometry(QRect(460, 250, 113, 20));
        layoutWidget = new QWidget(RKctrl);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 360, 351, 30));
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

        label_9 = new QLabel(RKctrl);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(380, 10, 81, 21));
        label_9->setFont(font);
        number = new QLineEdit(RKctrl);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(460, 10, 113, 21));
        label_10 = new QLabel(RKctrl);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(380, 280, 71, 21));
        label_10->setFont(font);
        indate = new QLineEdit(RKctrl);
        indate->setObjectName(QString::fromUtf8("indate"));
        indate->setGeometry(QRect(460, 280, 113, 20));
        label_11 = new QLabel(RKctrl);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(380, 310, 71, 21));
        label_11->setFont(font);
        wherein = new QLineEdit(RKctrl);
        wherein->setObjectName(QString::fromUtf8("wherein"));
        wherein->setGeometry(QRect(460, 310, 113, 20));
        label_12 = new QLabel(RKctrl);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(380, 340, 81, 21));
        label_12->setFont(font);
        relation = new QLineEdit(RKctrl);
        relation->setObjectName(QString::fromUtf8("relation"));
        relation->setGeometry(QRect(460, 340, 113, 20));
        label_13 = new QLabel(RKctrl);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(380, 370, 71, 21));
        label_13->setFont(font);
        boolout = new QLineEdit(RKctrl);
        boolout->setObjectName(QString::fromUtf8("boolout"));
        boolout->setGeometry(QRect(460, 370, 113, 20));

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
        label_9->setText(QCoreApplication::translate("RKctrl", "\346\210\267 \347\261\215 \345\217\267", nullptr));
        label_10->setText(QCoreApplication::translate("RKctrl", "\350\277\201\345\205\245\346\227\245\346\234\237", nullptr));
        label_11->setText(QCoreApplication::translate("RKctrl", "\350\277\201 \345\205\245 \345\234\260", nullptr));
        label_12->setText(QCoreApplication::translate("RKctrl", "\345\205\263    \347\263\273", nullptr));
        label_13->setText(QCoreApplication::translate("RKctrl", "\346\230\257\345\220\246\350\277\201\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RKctrl: public Ui_RKctrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RKCTRL_H
