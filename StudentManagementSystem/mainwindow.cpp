#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QAbstractItemModel>
#include <QStandardItem>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化阶段就读取文件，比较快捷方便，当读取失败返回的就是-1
    if(readFile()==-1){
        QMessageBox::critical(this,"wrong","信息读取失败");
    }
    else{
        qDebug()<<"读取成功";
    }
    this->model=new QStandardItemModel;
        //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("班级"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("数学成绩"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("物理成绩"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("化学成绩"));
    this->ui->tableView->setModel(model);
    qDebug()<<student.length();
    showInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//清空编辑框
void MainWindow::clearUserInterface(){
    ui->name->clear();
    ui->id->clear();
    ui->clas->clear();
    ui->math->clear();
    ui->physics->clear();
    ui->chemistry->clear();
}

//读取数据
int MainWindow::readFile(){
    student.clear();
    QFile file("学生成绩数据.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return -1;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
       QString line=in.readLine();
       student.append(line);
    }
    file.close();
    return 0;
}

//写入数据
void MainWindow::writeToFile(QString cnt)
{
    QFile file("学生成绩数据.txt");
    if(! file.open(QIODevice::Append | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&file);
    out<<cnt;
}

//添加信息的函数
void MainWindow::addInfo(){
    //获取键入的信息
    QString name = ui->name->text();
    QString id = ui->id->text();
    QString clas = ui->clas->text();
    QString math = ui->math->text();
    QString physics = ui->physics->text();
    QString chemistry = ui->chemistry->text();

    //信息判断
    if(name.length()<2||id.length()==0){
        //确保姓名和学号存在，学号未设置长度，方便测试
        QMessageBox::critical(this,"wrong","Wrong Information");
    }
    else {
        //将信息整合为一个串
        QString info = name+" "+id+" "+clas+" "+math+" "+physics+" "+chemistry+"\n";
        //设置添加消息提醒
        QMessageBox msg;
        msg.setText("姓名："+name+"\n"+"学号："+id+"\n"+"班级："+clas+"\n"+"数学成绩："+math+"\n"+"物理成绩："+physics+"\n"+"化学成绩："+chemistry);
        msg.addButton("确定",QMessageBox::AcceptRole); //确定键设置
        QPushButton *cancel = msg.addButton("取消",QMessageBox::RejectRole); //取消键设置
        msg.setDefaultButton(cancel);
        int index = msg.exec();
        qDebug()<<index;    //作为测试是否点击
        if(index==0){
            //qDebug()<<"ok";
            clearUserInterface();
            writeToFile(info);
        }
    }
}

//删除信息
void MainWindow::deleteInfo()
{
    QString id=this->ui->id->text();
    readFile(); //按照学号删除，防止有重复姓名的人被删除
    int k;
    for (k=0;k<student.length();k++) {
        QString line=student.at(k);
        line=line.trimmed();    //去掉开头结尾的空白
        QStringList linesplit=line.split(" ");
        if(id!=linesplit.at(1)){
            continue;
        }
        else{
            break;
        }
    }

    //动态显示tableview内容
    if(k==student.length()){
        QMessageBox::critical(this,"wrong","信息不存在","ok");
        return;
    }
    else{
        model->removeRow(k);
    }

    int i=0;
    for (i=0;i<student.length();i++)
    {
        //获取每一条信息
        QString line=student.at(i);
        line=line.trimmed();    //去掉开头结尾的空白
        QStringList linesplit=line.split(" ");

        //思路很简单，把除了要删除的人的信息全部录入到新的txt文件，删掉原来的文件，重新命名新文件
        if(id!=linesplit.at(1))
        {
            QFile file("score.txt");
            if(!file.open(QIODevice::Append|QIODevice::Text))
            {
               QMessageBox::critical(this,"wrong","Can't open the file","ok");
               return;
            }
            //文件流，输出
            QTextStream out(&file);
            out<<line+"\n";
            file.close();
        }
    }
    QFile file_old("学生成绩数据.txt");
    QFile file_new("score.txt");
    if (file_old.exists())
    {
       file_old.remove();
       file_new.rename("学生成绩数据.txt");
    }
    else
    {
       QMessageBox::critical(this,"wrong","文件内无信息因此无法删除","ok");
    }
    QMessageBox::information(this,"notice","删除成功","ok");
}

//搜索信息
void MainWindow::searchInfo(){
    //设置index为combobox的选择方式代表的参数，姓名是0，学号是1
    int index = ui->comboBox->currentIndex();
    int i=0;
    int row=0;
    for (i=0;i<student.length();i++)
    {
        QString line=student.at(i);
        line=line.trimmed();//去掉开头结尾的空白,预处理
        QStringList subs=line.split(" ");  //以空白为分割录入新的QStringList

        qDebug()<<subs;

        subs.at(0);
        switch(index)
        {
        case(0):
            if(ui->name->text()==subs[0]){
                for (int j=0;j<subs.length();j++) {
                    model->setItem(row,j,new QStandardItem(subs.at(j)));
                }
                return;
            }
        case(1):
            if(ui->id->text()==subs[1]){
                for (int j=0;j<subs.length();j++) {
                    model->setItem(row,j,new QStandardItem(subs.at(j)));
                }
                return;
            }
        }
    }
}

//直接显示信息
void MainWindow::showInfo(){
    readFile();
    int row=0;
    for (int i=0;i<student.length();i++)
    {
        QString line=student.at(i);
        line=line.trimmed();//去掉开头结尾的空白,预处理
        QStringList  subs=line.split(" ");  //以空白为分割录入新的QStringList
        subs.at(0);
        for (int j=0;j<subs.length();j++) {
            model->setItem(row,j,new QStandardItem(subs.at(j)));
        }
        row++;
    }

}

//添加信息按钮
void MainWindow::on_addInfo_clicked()
{
    addInfo();  //修改完原来的信息，要把student列表清空重新读取信息，作为刷新的效果。以此类推
    student.clear();
    readFile();
    showInfo();
}

//删除信息按钮
void MainWindow::on_deleteInfo_clicked()
{
    //设置添加消息提醒
    QMessageBox msg;
    msg.setText("确定删除该信息？");
    msg.addButton("确定",QMessageBox::AcceptRole); //确定键设置
    QPushButton *cancel = msg.addButton("取消",QMessageBox::RejectRole); //取消键设置
    msg.setDefaultButton(cancel);
    int index = msg.exec();
    qDebug()<<index;    //作为测试是否点击
    if(index==0){
        if(ui->id->text().length()!=0){
            deleteInfo();
            readFile();
        }
        else{
            QMessageBox::critical(this,"wrong","学号栏没有信息","ok");
        }
    }
    //按照学号删除

}

//搜索信息按钮
void MainWindow::on_search_clicked()
{
    student.clear();
    readFile();
    qDebug()<<student;
    for (int i=student.length();i>=0;i--) {
        model->removeRow(i);
    }
    if(ui->name->text().length()!=0||ui->id->text().length()!=0){
        searchInfo();
    }
    else {
        showInfo();
    }
}

void MainWindow::on_detailed_clicked()
{
    d.exec();
}
