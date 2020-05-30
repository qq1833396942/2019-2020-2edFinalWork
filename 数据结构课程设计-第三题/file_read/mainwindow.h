#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QVector>
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

private slots:
    void getPath();

    void floyd(int n);

    void print_wuhan();

    void dijkstra(bool flag);

    int bfs(int src, int des);

    void addEdge(int u, int v, int w);

    void dfs(int now, int des, int step, int sum, QVector<int> storage);

    static bool compare(const QVector<int>& va, const QVector<int>& vb);

    void on_toWuhan_clicked();

    void on_getpath_clicked();

    void on_floyd_clicked();

    void on_dijkstra_clicked();

    void on_pass_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;

    void init();
};
#endif // MAINWINDOW_H
