#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<linkedlist.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    LinkList L;
    LinkList T;

private slots:
    void on_add_clicked();

    void on_cut_clicked();

    void on_check_clicked();

    void on_LoopA_clicked();

    void on_LoopB_clicked();

    void cutm(int m);

    void cutmn(int m,int n);

    void EntryNodeOfLoop(LinkList L);

    void EntryNodeOfToop(LinkList L);

    void reBuild(LinkList L,LinkList T,int m,int n);

    void on_lift_clicked();

    LNode* IsIntersect(LinkList L,LinkList T);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
