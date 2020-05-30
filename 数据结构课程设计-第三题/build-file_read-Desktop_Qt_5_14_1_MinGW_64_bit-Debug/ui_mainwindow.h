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
    QPushButton *floyd;
    QPushButton *toWuhan;
    QLabel *label_2;
    QLineEdit *end;
    QLineEdit *begin;
    QPushButton *getpath;
    QPushButton *exit;
    QPushButton *dijkstra;
    QPushButton *pass;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QLabel *label;
    QLineEdit *dont;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(602, 308);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        floyd = new QPushButton(centralwidget);
        floyd->setObjectName(QString::fromUtf8("floyd"));
        floyd->setGeometry(QRect(370, 190, 75, 23));
        toWuhan = new QPushButton(centralwidget);
        toWuhan->setObjectName(QString::fromUtf8("toWuhan"));
        toWuhan->setGeometry(QRect(370, 150, 75, 23));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 80, 41, 21));
        end = new QLineEdit(centralwidget);
        end->setObjectName(QString::fromUtf8("end"));
        end->setGeometry(QRect(420, 80, 113, 20));
        begin = new QLineEdit(centralwidget);
        begin->setObjectName(QString::fromUtf8("begin"));
        begin->setGeometry(QRect(420, 40, 113, 20));
        getpath = new QPushButton(centralwidget);
        getpath->setObjectName(QString::fromUtf8("getpath"));
        getpath->setGeometry(QRect(460, 150, 75, 23));
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(460, 230, 75, 23));
        dijkstra = new QPushButton(centralwidget);
        dijkstra->setObjectName(QString::fromUtf8("dijkstra"));
        dijkstra->setGeometry(QRect(460, 190, 75, 23));
        pass = new QPushButton(centralwidget);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(370, 230, 75, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 120, 54, 16));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 40, 291, 221));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 40, 41, 21));
        dont = new QLineEdit(centralwidget);
        dont->setObjectName(QString::fromUtf8("dont"));
        dont->setGeometry(QRect(420, 120, 113, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 602, 22));
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
        floyd->setText(QCoreApplication::translate("MainWindow", "Floyd", nullptr));
        toWuhan->setText(QCoreApplication::translate("MainWindow", "\346\255\246\346\261\211\344\270\255\350\275\254", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\273\210  \347\202\271", nullptr));
        getpath->setText(QCoreApplication::translate("MainWindow", "\350\216\267\345\217\226\350\267\257\345\276\204", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        dijkstra->setText(QCoreApplication::translate("MainWindow", "Dijkstra", nullptr));
        pass->setText(QCoreApplication::translate("MainWindow", "\347\273\225\345\274\200", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\273\225  \345\274\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\247\213\345\217\221\345\234\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
