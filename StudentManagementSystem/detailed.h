#ifndef DETAILED_H
#define DETAILED_H

#include <QDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QAbstractItemModel>
#include <QStandardItem>
#include <QStandardItemModel>


namespace Ui {
class detailed;
}

class detailed : public QDialog
{
    Q_OBJECT

public:
    explicit detailed(QWidget *parent = nullptr);
    ~detailed();
    int readFile(); //读取信息
    void searchSection();//搜索区间内成绩
    void core(int n,int high,int low);
    void showInfo();
    void average();
    void average_core(int n,QString str);
    void average_core(QString str);
    void analyze(int n);
    void clearHead(); //清理表头
    float calculate(QStringList s); //计算标准差
    void writeToFile(QString cnt); //写入信息

private slots:
    void on_searchSection_clicked();

    void on_Analyze_clicked();

    void on_totalAnalyz_clicked();

    void on_dataAnalyze_clicked();

    void on_sortScore_clicked();

    void on_write_clicked();

private:
    Ui::detailed *ui;
    QStandardItemModel*model;
    QStandardItemModel*model2; // 专门用于排序，这样表头不会残留
    QList<QString> Info;
    QList<QString> section;
    QList<QString> subject={"","","","数学成绩","物理成绩","化学成绩"};
};

#endif // DETAILED_H
