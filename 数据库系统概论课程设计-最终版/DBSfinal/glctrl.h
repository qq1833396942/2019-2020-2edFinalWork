#ifndef GLCTRL_H
#define GLCTRL_H

#include <QDialog>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QStandardItem>
#include <cstring>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <conio.h>
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class GLctrl;
}

class GLctrl : public QDialog
{
    Q_OBJECT

public:
    explicit GLctrl(QWidget *parent = nullptr);
    ~GLctrl();

    void search();      //检索显示所有信息
    void addInfo();     //添加信息
    void judge();       //判断是否加入
    void deleteInfo();  //删除信息
    void change();      //修改信息


private slots:
    void on_add_clicked();

    void on_delete_2_clicked();

    void on_change_clicked();

    void on_search_clicked();

private:
    Ui::GLctrl *ui;
};

#endif // GLCTRL_H
