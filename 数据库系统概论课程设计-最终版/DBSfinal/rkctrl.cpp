#include "rkctrl.h"
#include "ui_rkctrl.h"
#include <QMessageBox>

RKctrl::RKctrl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RKctrl)
{
    ui->setupUi(this);
    search();
}

RKctrl::~RKctrl()
{
    delete ui;
}

void RKctrl::search()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from RK");
    ui->tableView->setModel(model);
    //设置效果
    ui->tableView->setAlternatingRowColors(true);
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView->setRowHeight(i, 20);
    }
}

void RKctrl::addInfo()  //添加信息
{
    QSqlQuery q;
    q.prepare("insert into RK values (?,?,?,?,?,?,?,?)");
    q.addBindValue(this->ui->name->text());
    q.addBindValue(this->ui->sex->text());
    q.addBindValue(this->ui->id->text());
    q.addBindValue(this->ui->nation->text());
    q.addBindValue(this->ui->province->text());
    q.addBindValue(this->ui->birdate->text());
    q.addBindValue(this->ui->birplace->text());
    q.addBindValue(this->ui->ads->text());
    q.exec();
    search();
}

void RKctrl::addInToRin()
{
    QSqlQuery q;
    q.prepare("insert into RIN values (?,?,?,?,?,?)");
    q.addBindValue(this->ui->number->text());
    q.addBindValue(this->ui->relation->text());
    q.addBindValue(this->ui->id->text());
    q.addBindValue(this->ui->indate->text());
    q.addBindValue(this->ui->wherein->text());
    q.addBindValue(this->ui->boolout->text());
    q.exec();
}


void RKctrl::judged()   //完整化，先判断再添加
{
    QSqlTableModel model;   //实例化model
    model.setTable("RK");   //设置所需要操作的表格
    model.setFilter(tr("ID = '%1'").arg(ui->id->text()));
    model.select();
    if(model.rowCount()==1){
        QMessageBox::warning(this,tr("警告"),tr("当前ID使用者已存在"),QMessageBox::Yes);   //如果存在则跳转至操作界面
    }
    else{
        addInfo();
        addInToRin();
    }
}

void RKctrl::remove()
{
    int curRow = ui->tableView->currentIndex().row();   //设置行号，准备数据
    QModelIndex index = ui->tableView->currentIndex();
    QString id = index.sibling(curRow,2).data().toString();    //删除data
    QSqlQuery q;
    int ok = QMessageBox::warning(this,tr("删除该人信息!"),tr("你确定删除当前行吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::Yes){
        q.prepare("delete from RIN where id = (?)");
        q.addBindValue(id);
        q.exec();
        q.prepare("delete from RK where id = (?)");
        q.addBindValue(id);
        q.exec();

    }
    search();
}

void RKctrl::change()
{
    QSqlQuery q;
    QModelIndex index = ui->tableView->currentIndex();
    int curRow = ui->tableView->currentIndex().row();
    int curColume = ui->tableView->currentIndex().column();
    if(curColume==0){
        q.prepare("UPDATE RK SET Rname = (?) where Rname = (?) and ID = ?");
        q.addBindValue(ui->name->text());
        q.addBindValue(index.sibling(curRow,0).data().toString());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==1) {
        q.prepare("UPDATE RK SET Rsex = (?) where ID = ?");
        q.addBindValue(ui->sex->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==4) {
        q.prepare("UPDATE RK SET Province = (?) where ID = ?");
        q.addBindValue(ui->province->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==5) {
        q.prepare("UPDATE RK SET Birdate = (?) where ID = ?");
        q.addBindValue(ui->birdate->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==6) {
        q.prepare("UPDATE RK SET Birpace = ? where ID = ?");
        q.addBindValue(ui->birplace->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==7) {
        q.prepare("UPDATE RK SET Ads = ? where ID = ?");
        q.addBindValue(ui->ads->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==2) {
        QMessageBox::warning(this,tr("警告"),tr("身份证号禁止修改"),QMessageBox::Yes);
    }
    else if (curColume==3) {
        QMessageBox::warning(this,tr("警告"),tr("民族禁止修改"),QMessageBox::Yes);
    }
    search();
    QMessageBox::warning(this,tr("警告"),tr("请确认当前信息是否需要在迁入人员数据库中修改！"),QMessageBox::Yes);
}

void RKctrl::on_add_clicked()
{
    judged();
}

void RKctrl::on_delete_2_clicked()
{
    remove();
}

void RKctrl::on_change_clicked()
{
    change();

}

void RKctrl::on_search_clicked()
{
    search();
}


