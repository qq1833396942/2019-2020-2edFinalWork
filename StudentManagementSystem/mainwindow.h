#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QStandardItemModel>
#include "detailed.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addInfo(); //添加信息
    void deleteInfo(); //删除信息
    void searchInfo(); //查询信息
    void showInfo(); //展示信息
    int readFile(); //读取信息
    void writeToFile(QString cnt); //写入信息
    void clearUserInterface();//清空信息

private slots:
    void on_addInfo_clicked();

    void on_deleteInfo_clicked();

    void on_search_clicked();

    void on_detailed_clicked();

private:
    Ui::MainWindow *ui;
    QList<QString> student;
    QStandardItemModel*model;
    detailed d;
};
#endif // MAINWINDOW_H
