#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "mainfunction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void login();


private slots:
    void on_login_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
    MainFunction mainfunc;
};
#endif // MAINWINDOW_H
