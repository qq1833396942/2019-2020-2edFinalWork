/********************************************************************************
** Form generated from reading UI file 'glctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLCTRL_H
#define UI_GLCTRL_H

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

class Ui_GLctrl
{
public:
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QTableView *tableView;
    QLabel *label_3;
    QLineEdit *sex;
    QLineEdit *name;
    QLabel *label_4;
    QLineEdit *password;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *add;
    QPushButton *delete_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *change;
    QPushButton *search;

    void setupUi(QDialog *GLctrl)
    {
        if (GLctrl->objectName().isEmpty())
            GLctrl->setObjectName(QString::fromUtf8("GLctrl"));
        GLctrl->resize(700, 251);
        label = new QLabel(GLctrl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(480, 30, 81, 21));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        id = new QLineEdit(GLctrl);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(560, 60, 113, 20));
        label_2 = new QLabel(GLctrl);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(480, 90, 91, 21));
        label_2->setFont(font);
        tableView = new QTableView(GLctrl);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 30, 421, 191));
        label_3 = new QLabel(GLctrl);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 60, 71, 21));
        label_3->setFont(font);
        sex = new QLineEdit(GLctrl);
        sex->setObjectName(QString::fromUtf8("sex"));
        sex->setGeometry(QRect(560, 90, 113, 20));
        name = new QLineEdit(GLctrl);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(560, 30, 113, 20));
        label_4 = new QLabel(GLctrl);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 120, 81, 21));
        label_4->setFont(font);
        password = new QLineEdit(GLctrl);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(560, 120, 113, 20));
        layoutWidget = new QWidget(GLctrl);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(470, 150, 194, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        add = new QPushButton(layoutWidget);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_2->addWidget(add);

        delete_2 = new QPushButton(layoutWidget);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));

        horizontalLayout_2->addWidget(delete_2);

        layoutWidget1 = new QWidget(GLctrl);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(470, 190, 194, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        change = new QPushButton(layoutWidget1);
        change->setObjectName(QString::fromUtf8("change"));

        horizontalLayout->addWidget(change);

        search = new QPushButton(layoutWidget1);
        search->setObjectName(QString::fromUtf8("search"));

        horizontalLayout->addWidget(search);


        retranslateUi(GLctrl);

        QMetaObject::connectSlotsByName(GLctrl);
    } // setupUi

    void retranslateUi(QDialog *GLctrl)
    {
        GLctrl->setWindowTitle(QCoreApplication::translate("GLctrl", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("GLctrl", "\345\247\223    \345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("GLctrl", "\346\200\247    \345\210\253", nullptr));
        label_3->setText(QCoreApplication::translate("GLctrl", "\347\274\226    \345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("GLctrl", "\345\257\206    \347\240\201", nullptr));
        add->setText(QCoreApplication::translate("GLctrl", "\346\267\273\345\212\240", nullptr));
        delete_2->setText(QCoreApplication::translate("GLctrl", "\345\210\240\351\231\244", nullptr));
        change->setText(QCoreApplication::translate("GLctrl", "\344\277\256\346\224\271", nullptr));
        search->setText(QCoreApplication::translate("GLctrl", "\346\243\200\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GLctrl: public Ui_GLctrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLCTRL_H
