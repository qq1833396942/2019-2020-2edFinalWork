#ifndef RINCTRL_H
#define RINCTRL_H

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
class RINctrl;
}

class RINctrl : public QDialog
{
    Q_OBJECT

public:
    explicit RINctrl(QWidget *parent = nullptr);
    ~RINctrl();
    void addInfo();
    void search();
    void change();
    void deleteInfo();
    void judge();
    bool judgeFK();

private slots:
    void on_add_clicked();

    void on_delete_2_clicked();

    void on_change_clicked();

    void on_search_clicked();

private:
    Ui::RINctrl *ui;
};

#endif // RINCTRL_H
