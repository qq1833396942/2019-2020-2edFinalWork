/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *value;
    QLineEdit *mp;
    QLineEdit *np;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *add;
    QPushButton *cut;
    QPushButton *check;
    QPushButton *LoopA;
    QPushButton *LoopB;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *lift;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(517, 442);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 251, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(130, 60, 331, 21));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(60, 140, 191, 31));
        textBrowser_3 = new QTextBrowser(centralwidget);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(60, 200, 191, 31));
        textBrowser_4 = new QTextBrowser(centralwidget);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(270, 170, 181, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(93, 260, 51, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 260, 21, 20));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(393, 260, 41, 20));
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 60, 51, 21));
        QFont font1;
        font1.setPointSize(11);
        label_5->setFont(font1);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 140, 31, 21));
        label_6->setFont(font1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(60, 110, 61, 21));
        label_7->setFont(font1);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 180, 61, 20));
        label_8->setFont(font1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 290, 413, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        value = new QLineEdit(layoutWidget);
        value->setObjectName(QString::fromUtf8("value"));

        horizontalLayout->addWidget(value);

        mp = new QLineEdit(layoutWidget);
        mp->setObjectName(QString::fromUtf8("mp"));

        horizontalLayout->addWidget(mp);

        np = new QLineEdit(layoutWidget);
        np->setObjectName(QString::fromUtf8("np"));

        horizontalLayout->addWidget(np);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 330, 401, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        add = new QPushButton(layoutWidget1);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_2->addWidget(add);

        cut = new QPushButton(layoutWidget1);
        cut->setObjectName(QString::fromUtf8("cut"));

        horizontalLayout_2->addWidget(cut);

        check = new QPushButton(layoutWidget1);
        check->setObjectName(QString::fromUtf8("check"));

        horizontalLayout_2->addWidget(check);

        LoopA = new QPushButton(layoutWidget1);
        LoopA->setObjectName(QString::fromUtf8("LoopA"));

        horizontalLayout_2->addWidget(LoopA);

        LoopB = new QPushButton(layoutWidget1);
        LoopB->setObjectName(QString::fromUtf8("LoopB"));

        horizontalLayout_2->addWidget(LoopB);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(170, 360, 161, 25));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lift = new QPushButton(widget);
        lift->setObjectName(QString::fromUtf8("lift"));

        horizontalLayout_3->addWidget(lift);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 517, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\257\267\344\270\200\344\270\252\344\270\200\344\270\252\350\276\223\345\205\245\351\223\276\350\241\250\345\215\225\344\270\252\350\212\202\347\202\271\346\225\260\345\200\274", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\205\203\347\264\240", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "n", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\216\237\351\223\276\350\241\250", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "m\350\207\263n", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "m\345\211\215\345\205\203\347\264\240", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "n\345\220\216\345\205\203\347\264\240", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\205\245", nullptr));
        cut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
        check->setText(QCoreApplication::translate("MainWindow", "\346\243\200\347\264\242", nullptr));
        LoopA->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\216\257A", nullptr));
        LoopB->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\216\257B", nullptr));
        lift->setText(QCoreApplication::translate("MainWindow", "\350\247\243\351\231\244", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\233\270\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
