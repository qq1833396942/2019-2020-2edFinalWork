#include "mainfunction.h"
#include "ui_mainfunction.h"
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

MainFunction::MainFunction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainFunction)
{
    ui->setupUi(this);
}

MainFunction::~MainFunction()
{
    delete ui;
}

void MainFunction::search(){

    QSqlQueryModel *model = new QSqlQueryModel;

    if(this->ui->tableName->currentIndex()==0){
        model->setQuery("select * from HK");//这里直接设置SQL语句，忽略最后一个参数
        ui->tableView->setModel(model);
    }
    else if (this->ui->tableName->currentIndex()==1) {
        model->setQuery("select * from RK");
        ui->tableView->setModel(model);
    }
    else if (this->ui->tableName->currentIndex()==2) {
        model->setQuery("select * from GL");
        ui->tableView->setModel(model);
    }
    else if (this->ui->tableName->currentIndex()==3) {
        model->setQuery("select * from RIN");
        ui->tableView->setModel(model);
    }

    //以下是视觉方面的效果，不加也没影响
    //隔行变色
    ui->tableView->setAlternatingRowColors(true);
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView->setRowHeight(i, 20);
    }
}

void MainFunction::on_search_clicked()
{
    search();
}

void MainFunction::on_HK_clicked()
{
    hkctrl.exec();
}

void MainFunction::on_RK_clicked()
{
    rkctrl.exec();
}

void MainFunction::on_RIN_clicked()
{
    rinctrl.exec();
}

void MainFunction::on_GL_clicked()
{
    glctrl.exec();
}
