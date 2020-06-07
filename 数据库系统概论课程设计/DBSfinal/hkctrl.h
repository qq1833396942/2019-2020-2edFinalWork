#ifndef HKCTRL_H
#define HKCTRL_H

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
class HKctrl;
}

class HKctrl : public QDialog
{
    Q_OBJECT

public:
    explicit HKctrl(QWidget *parent = nullptr);
    ~HKctrl();
    void search();      //检索显示所有信息
    void clearData();   //处理SQL自动修改空日期为1900年的情况
    void addInfo();     //添加人员
    void judged();      //判断删除
    void remove();      //删除函数
    void change();      //修改功能

private slots:
    void on_search_clicked();

    void on_add_clicked();

    void on_delete_2_clicked();

    void on_change_clicked();

private:
    Ui::HKctrl *ui;
};

#endif // HKCTRL_H
