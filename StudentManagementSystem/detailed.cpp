#include "detailed.h"
#include "ui_detailed.h"
#include <math.h>
using namespace std;

#define foo(arr) sizeof(arr)/sizeof(arr[0])

detailed::detailed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailed)
{
    ui->setupUi(this);
    this->model=new QStandardItemModel;   //第一个配置在tableView控件的model
    this->model2=new QStandardItemModel;  //第一个配置在tableView控件的model，这样设置不会存在残留的表头
    //不许删掉，否则就崩溃了
    this->ui->tableView->setSortingEnabled(true);   //打开控件的点击表头排序功能，很方便
}

detailed::~detailed()
{
    delete ui;
}

int detailed::readFile(){
    Info.clear();
    QFile file("学生成绩数据.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return -1;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
       QString line=in.readLine();
       Info.append(line);
    }
    file.close();

    //遍历读取的信息，在控制台区域展示，方便你检查
    int i=0;
    for(i=0;i<Info.length();i++)
    {
        qDebug()<<Info.at(i);
    }
    return 0;
}

void detailed::writeToFile(QString cnt)
{
    QFile file("排序结果.txt");
    if(! file.open(QIODevice::Append | QIODevice::Text))    //判断是否打开了文件
    {
        return;
    }

    QTextStream out(&file);
    out<<cnt;   //写入信息，注意是一条一条写
}

//把信息打印在tableView
void detailed::showInfo(){
    int row=0;
    for (int i=0;i<section.length();i++)
    {
        QString line=section.at(i);
        line=line.trimmed();//去掉开头结尾的空白,预处理
        QStringList  subs=line.split(" ");  //以空白为分割录入新的QStringList
        subs.at(0);
        for (int j=0;j<subs.length();j++) {
            model->setItem(row,j,new QStandardItem(subs.at(j)));    //row是行，j是列，先固定行再把分割后的列表subs中的信息打印在tableView中
        }
        row++; //下一行
    }
}

//查询区间的核心
void detailed::core(int n,int high,int low){
    //先设置个表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("班级"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem(subject[n]));
    this->ui->tableView->setModel(model);
    for (int k=0;k<Info.length();k++) {
        QString line=Info.at(k);
        line=line.trimmed();    //去掉开头结尾的空白
        QStringList linesplit=line.split(" ");
        //判断元素是否在区间内
        if(linesplit[n].toInt()>=low && linesplit[n].toInt()<=high){
            QString msg = linesplit[0]+" "+linesplit[1]+" "+linesplit[2]+" "+linesplit[n];
            section.append(msg);
        }
    }
}

//查询区间函数的外壳
void detailed::searchSection(){
    section.clear();    //每次先把section清理空，这样是为了防止信息保存太多次全乱套了，上次的在，这次的也在。
    int high = ui->high->text().toInt();
    int low = ui->low->text().toInt();
    if(ui->comboBox->currentIndex()==0){
        core(3,high,low);
    }
    else if(ui->comboBox->currentIndex()==1){
        core(4,high,low);
    }
    else{
        core(5,high,low);
    }
}

//求班级单科核心部分
void detailed::average_core(int n,QString str){
    this->model->setHorizontalHeaderItem(0,new QStandardItem("班级"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem(subject[n]+"平均"));
    int sum=0,count=0;
    for (int i=0;i<Info.length();i++) {
        QString line=Info.at(i);
        line=line.trimmed();//去掉开头结尾的空白,预处理
        QStringList subs=line.split(" ");  //以空白为分割录入新的QStringList
        if(subs[2]==str){
            sum+=subs[n].toInt();
            count++;
        }
    }
    model->setItem(1,0,new QStandardItem(str));
    model->setItem(1,1,new QStandardItem(QString::number(sum/count)));  //简化的写法，我没int新变量，得出的数字可以直接用QString的函数转化成QString类型的变量
    this->ui->tableView->setModel(model);
}

//求班级单科平均分外壳
void detailed::average(){
    Info.clear();
    readFile();
    int index = ui->comboBox->currentIndex();
    if(index==0){
        average_core(index+3,ui->clas->text());
    }
    else if (index==1) {
        average_core(index+3,ui->clas->text());
    }
    else if (index==2) {
        average_core(index+3,ui->clas->text());
    }
}

//求班级总分平均分核心
void detailed::average_core(QString str){
    this->model->setHorizontalHeaderItem(0,new QStandardItem("班级"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("总分平均"));
    int sum=0,count=0,single=0;
    for (int i=0;i<Info.length();i++) {
        QString line=Info.at(i);
        line=line.trimmed();//去掉开头结尾的空白,预处理
        QStringList subs=line.split(" ");  //以空白为分割录入新的QStringList
        if(subs[2]==str){
            //toInt函数就是把QString临时改成int类型
            single = subs[3].toInt()+subs[4].toInt()+subs[5].toInt();
            sum+=single;
            count++;
        }
    }
    model->setItem(1,0,new QStandardItem(str));
    model->setItem(1,1,new QStandardItem(QString::number(sum/count)));
    this->ui->tableView->setModel(model);
}

//计算标准差的函数
float detailed::calculate(QStringList s){

    float sum,standardDeviation=0;
    for (int i=0;i<s.length();i++) {
        sum=sum+s[i].toFloat();
    }
    float mean = sum/s.length();
    for(int i=0; i<s.length(); ++i)
        standardDeviation += pow(s[i].toFloat() - mean, 2);
    return sqrt(standardDeviation/s.length());
}

//计算标准差与合格率
void detailed::analyze(int n){
    Info.clear();
    readFile();
    QStringList list;
    QStringList total; //所有成绩都进来准备计算标准差
    model->setHorizontalHeaderItem(0,new QStandardItem("科目"));
    model->setHorizontalHeaderItem(1,new QStandardItem("通过率"));
    model->setHorizontalHeaderItem(2,new QStandardItem("标准差"));
    qDebug()<<"0213";
    if(n==0){
        for (int i=0;i<Info.length();i++) {
            QString line=Info.at(i);
            line=line.trimmed();//去掉开头结尾的空白,预处理
            QStringList subs=line.split(" ");  //以空白为分割录入新的QStringList
            total.append(subs[3]);
            if(subs[3]>="60"){
                list.append(subs[3]);
            }
        } 
        float a = list.length(),b = Info.length();
        model->setItem(1,0,new QStandardItem("数学"));
        model->setItem(1,1,new QStandardItem(QString::number(a/b,'f',2)));
        model->setItem(1,2,new QStandardItem(QString::number(calculate(total))));
        this->ui->tableView->setModel(model);
    }
    else if(n==1){
        for (int i=0;i<Info.length();i++) {
            QString line=Info.at(i);
            line=line.trimmed();//去掉开头结尾的空白,预处理
            QStringList subs=line.split(" ");  //以空白为分割录入新的QStringList
            total.append(subs[4]);
            if(subs[4]>="60"){
                list.append(subs[4]);
            }
        }
        float a = list.length(),b = Info.length();
        model->setItem(1,0,new QStandardItem("物理"));
        model->setItem(1,1,new QStandardItem(QString::number(a/b, 'f', 2)));
        model->setItem(1,2,new QStandardItem(QString::number(calculate(total))));
        this->ui->tableView->setModel(model);
    }
    else if(n==2){
        for (int i=0;i<Info.length();i++) {
            QString line=Info.at(i);
            line=line.trimmed();//去掉开头结尾的空白,预处理
            QStringList subs=line.split(" ");  //以空白为分割录入新的QStringList
            total.append(subs[5]);
            if(subs[5]>="60"){
                list.append(subs[5]);
            }
        }
        float a = list.length(),b = Info.length();
        model->setItem(1,0,new QStandardItem("化学"));
        model->setItem(1,1,new QStandardItem(QString::number(a/b, 'f', 2)));
        model->setItem(1,2,new QStandardItem(QString::number(calculate(total))));
        this->ui->tableView->setModel(model);
    }
}

//清理区间查询产生的多余的表头
void detailed::clearHead(){
    this->model->setHorizontalHeaderItem(2,new QStandardItem(nullptr));
    this->model->setHorizontalHeaderItem(3,new QStandardItem(nullptr));
    this->ui->tableView->setModel(model);
}

void detailed::on_searchSection_clicked()
{
    model->removeRows(0,model->rowCount());//删除之前操作保留的所有行信息
    for (int i=section.length();i>=0;i--) {
        model->removeRow(i);    //清空tableView
    }
    section.clear();    //清空学生信息记录  容器
    if(ui->low->text()!=nullptr||ui->high->text()!=nullptr){
        readFile();     //读取文件
        searchSection();    //搜索
        showInfo();     //展示信息
    }
    else{
        QMessageBox::critical(this,"wrong","最高分或最低分不能为空");
    }

}

void detailed::on_Analyze_clicked()
{
    clearHead();
    model->removeRows(0,model->rowCount());//删除之前操作保留的所有行信息
    if(ui->clas->text()!=nullptr){
        average();
    }
    else {
        QMessageBox::critical(this,"wrong","班级信息不能为空");
    }
}

void detailed::on_totalAnalyz_clicked()
{
    clearHead();
    model->removeRows(0,model->rowCount());//删除之前操作保留的所有行信息
    if(ui->clas->text()!=nullptr){
        Info.clear();
        readFile();
        average_core(ui->clas->text());
    }
    else{
        QMessageBox::critical(this,"wrong","班级信息不能为空");
    }

}

void detailed::on_dataAnalyze_clicked()
{
    clearHead();
    model->removeRows(0,model->rowCount());//删除之前操作保留的所有行信息
    int index = ui->comboBox->currentIndex();
    analyze(index);
}

void detailed::on_sortScore_clicked()
{
    this->model2->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model2->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model2->setHorizontalHeaderItem(2,new QStandardItem("班级"));
    this->model2->setHorizontalHeaderItem(3,new QStandardItem("数学成绩"));
    this->model2->setHorizontalHeaderItem(4,new QStandardItem("物理成绩"));
    this->model2->setHorizontalHeaderItem(5,new QStandardItem("化学成绩"));
    this->model2->setHorizontalHeaderItem(6,new QStandardItem("总成绩"));
    this->ui->tableView->setModel(model2);
    Info.clear();
    readFile();
    int row=0;
    for (int i=0;i<Info.length();i++)
    {
        QString line=Info.at(i);
        line=line.trimmed();//去掉开头结尾的空白,预处理
        QStringList  subs=line.split(" ");  //以空白为分割录入新的QStringList
        subs.at(0);
        for (int j=0;j<subs.length();j++) {
            float a=subs[3].toFloat(),b = subs[4].toFloat(),c = subs[5].toFloat();
            QString sum = QString::number(a+b+c);
            model2->setItem(row,j,new QStandardItem(subs.at(j)));
            model2->setItem(row,j+1,new QStandardItem(sum));
        }
        row++;
    }
}

void detailed::on_write_clicked()
{
    QFile file_old("排序结果.txt");
    if (file_old.exists())
    {
       file_old.remove();
    }
    QString msg;
    int curRow,curColume;
    for (curRow=0;curRow<Info.length();curRow++) {
        for (curColume=0;curColume<7;curColume++) {
            msg = msg + model2->data(model2->index(curRow,curColume)).toString()+" ";
        }
        writeToFile(msg+"\n");
        msg="";
    }
    QMessageBox::warning(this,"注意","排序文件已写入文档","ok");
}
