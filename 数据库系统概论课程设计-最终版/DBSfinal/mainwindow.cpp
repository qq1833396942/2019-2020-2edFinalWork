#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <cstring>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <conio.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::login()
{
    //获取账户和密码
    QString account = this->ui->lineEdit->text();
    QString password = this->ui->lineEdit_2->text();
    qDebug()<<"名字="<<account;
    qDebug()<<"密码="<<password;
    QSqlTableModel model;   //实例化model
    model.setTable("GL");   //设置所需要操作的表格
    model.setFilter(tr("Gname = '%1' and paswd = '%2'").arg(account).arg(password));
    model.select();
    if(model.rowCount()==1){
        mainfunc.exec();   //如果存在则跳转至操作界面
        this->hide();
    }
    else{
        QMessageBox::warning(this, tr("warn"), tr("登陆失败"));
    }
}


void MainWindow::on_login_clicked()
{
    login();
}


void MainWindow::on_exit_clicked()
{
    this->close();
}
