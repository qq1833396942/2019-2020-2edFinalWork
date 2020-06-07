#include "rinctrl.h"
#include "ui_rinctrl.h"

RINctrl::RINctrl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RINctrl)
{
    ui->setupUi(this);
    search();
}

RINctrl::~RINctrl()
{
    delete ui;
}

//查看所有信息
void RINctrl::search(){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from RIN");
    ui->tableView->setModel(model);
    //设置效果
    ui->tableView->setAlternatingRowColors(true);
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView->setRowHeight(i, 20);
    }
}

//判断是否符合外码条件
bool RINctrl::judgeFK(){
    QSqlTableModel HKmodel,RKmodel;   //实例化model
    HKmodel.setTable("HK");   //设置所需要操作的表格
    RKmodel.setTable("RK");
    HKmodel.setFilter(tr("Hno = '%1'").arg(ui->number->text()));
    RKmodel.setFilter(tr("ID = '%1'").arg(ui->id->text()));
    HKmodel.select();
    RKmodel.select();
    if(HKmodel.rowCount()==1 && RKmodel.rowCount()==1){
        return true;
    }
    else {
        return false;
    }
}

void RINctrl::judge(){
    if(judgeFK()==true){
        addInfo();
    }
    else {
        QMessageBox::warning(this,tr("警告"),tr("户籍号或身份证号不存在，经返回预览页查询"),QMessageBox::Yes);   //如果存在则跳转至操作界面
    }
}

void RINctrl::addInfo(){
    QSqlQuery q;
    q.prepare("insert into RIN values (?,?,?,?,?,?)");
    q.addBindValue(this->ui->number->text());
    q.addBindValue(this->ui->relation->text());
    q.addBindValue(this->ui->id->text());
    q.addBindValue(this->ui->indate->text());
    q.addBindValue(this->ui->wherein->text());
    q.addBindValue(this->ui->boolout->text());
    q.exec();
    search();
}


void RINctrl::deleteInfo(){
    int curRow = ui->tableView->currentIndex().row();   //设置行号，准备数据
    QModelIndex index = ui->tableView->currentIndex();
    QString id = index.sibling(curRow,2).data().toString();    //删除data
    QSqlQuery q;
    int ok = QMessageBox::warning(this,tr("删除该人信息!"),tr("你确定删除当前行吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::Yes){
        q.prepare("delete from RIN where id = (?)");
        q.addBindValue(id);
        q.exec();
    }
    search();
}


void RINctrl::change(){
    QSqlQuery q;
    QModelIndex index = ui->tableView->currentIndex();
    int curRow = ui->tableView->currentIndex().row();
    int curColume = ui->tableView->currentIndex().column();
    if(curColume==0){
        QMessageBox::warning(this,tr("警告"),tr("户籍号禁止修改"),QMessageBox::Yes);
    }
    else if (curColume==1) {
        q.prepare("UPDATE RIN SET Relation = (?) where ID = ?");
        q.addBindValue(ui->relation->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==3) {
        q.prepare("UPDATE RIN SET Indate = (?) where ID = ?");
        q.addBindValue(ui->indate->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==4) {
        q.prepare("UPDATE RIN SET wherein = (?) where ID = ?");
        q.addBindValue(ui->wherein->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==5) {
        q.prepare("UPDATE RIN SET bollout = (?) where ID = ?");
        q.addBindValue(ui->boolout->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==2) {
        QMessageBox::warning(this,tr("警告"),tr("身份证号禁止修改"),QMessageBox::Yes);
    }
    search();
}


void RINctrl::on_add_clicked()
{
    judge();
}

void RINctrl::on_delete_2_clicked()
{
    deleteInfo();
}

void RINctrl::on_change_clicked()
{
    change();
}

void RINctrl::on_search_clicked()
{
    search();
}
