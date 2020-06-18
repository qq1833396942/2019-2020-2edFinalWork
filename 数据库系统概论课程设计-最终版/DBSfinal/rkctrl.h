#ifndef RKCTRL_H
#define RKCTRL_H

#include <QDialog>
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
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class RKctrl;
}

class RKctrl : public QDialog
{
    Q_OBJECT

public:
    explicit RKctrl(QWidget *parent = nullptr);
    ~RKctrl();

    void addInfo(); //添加信息
    void search();  //检索遍历
    void judged();  //判断ID是否重复后添加信息
    void remove();  //删除信息
    void change();  //修改信息
    void addInToRin(); //向户籍信息中同步添加信息

private slots:
    void on_add_clicked();

    void on_change_clicked();

    void on_search_clicked();

    void on_delete_2_clicked();

private:
    Ui::RKctrl *ui;
};

#endif // RKCTRL_H
