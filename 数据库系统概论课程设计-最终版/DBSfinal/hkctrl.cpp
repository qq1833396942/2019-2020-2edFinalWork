#include "hkctrl.h"
#include "ui_hkctrl.h"
#include<QDebug>

HKctrl::HKctrl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HKctrl)
{
    ui->setupUi(this);
    search();
}

HKctrl::~HKctrl()
{
    delete ui;
}

void HKctrl::search()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from HK");
    ui->tableView->setModel(model);
    //设置效果
    ui->tableView->setAlternatingRowColors(true);
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView->setRowHeight(i, 20);
    }
}


void HKctrl::addInfo()
{
    QSqlQuery q;
    q.prepare("insert into HK values (?,?,?,?,?,?,?,?,?)");
    q.addBindValue(this->ui->number->text());
    q.addBindValue(this->ui->name->text());
    q.addBindValue(this->ui->id->text());
    q.addBindValue(this->ui->nation->text());
    q.addBindValue(this->ui->ads->text());
    q.addBindValue(this->ui->indate->text());
    q.addBindValue(this->ui->wherein->text());
    q.addBindValue(this->ui->outdate->text());
    q.addBindValue(this->ui->whereout->text());
    q.exec();
}


void HKctrl::clearData(){
    QSqlQuery q;
    q.prepare("update HK set Outdata = null where id = ?");
    q.addBindValue(ui->id->text());
    q.exec();
}


void HKctrl::judged()
{
    QSqlTableModel model;   //实例化model
    model.setTable("RK");   //设置所需要操作的表格
    model.setFilter(tr("ID = '%1'").arg(ui->id->text()));
    model.select();
    if(model.rowCount()==1){
        if(ui->outdate->text().length()>0){
            addInfo();
        }
        else if (ui->outdate->text().length()==0) {
            addInfo();
            clearData();
        }
    }
    else{
        QMessageBox::warning(this,tr("警告"),tr("当前ID使用者不存在人口信息表，故不许立户"),QMessageBox::Yes);   //如果存在则跳转至操作界面
    }
    search();
}


void HKctrl::remove()
{
    int curRow = ui->tableView->currentIndex().row();   //设置行号，准备数据
    QModelIndex index = ui->tableView->currentIndex();
    QString id = index.sibling(curRow,2).data().toString();    //删除data
    QSqlQuery q;
    int ok = QMessageBox::warning(this,tr("删除该户主信息!"),tr("你确定删除当前行吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::Yes){
        q.prepare("delete from HK where id = (?)");
        q.addBindValue(id);
        q.exec();
    }
    search();
}


void HKctrl::change()
{
    QSqlQuery q;
    QModelIndex index = ui->tableView->currentIndex();
    int curRow = ui->tableView->currentIndex().row();
    int curColume = ui->tableView->currentIndex().column();
    qDebug()<<curRow<<curColume<<endl;
    if(curColume==0){
        QMessageBox::warning(this,tr("警告"),tr("户籍号禁止修改"),QMessageBox::Yes);
    }
    else if (curColume==1) {
        q.prepare("UPDATE HK SET Hname = (?) where Hname = (?) and ID = ?");
        q.addBindValue(ui->name->text());
        q.addBindValue(index.sibling(curRow,1).data().toString());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==4) {
        q.prepare("UPDATE HK SET Ads = ? where ID = ?");
        q.addBindValue(ui->ads->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==5) {
        q.prepare("UPDATE HK SET Indate = (?) where ID = ?");
        q.addBindValue(ui->indate->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==6) {
        q.prepare("UPDATE HK SET wherein = ? where ID = ?");
        q.addBindValue(ui->wherein->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==7) {
        q.prepare("UPDATE HK SET Outdata = ? where ID = ?");
        q.addBindValue(ui->outdate->text());
        q.addBindValue(index.sibling(curRow,2).data().toString());
        q.exec();
    }
    else if (curColume==8) {
        q.prepare("UPDATE HK SET Whereout = ? where ID = ?");
        q.addBindValue(ui->whereout->text());
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
}


void HKctrl::on_search_clicked()
{
    search();
}

void HKctrl::on_add_clicked()
{
    judged();
}

void HKctrl::on_delete_2_clicked()
{
    remove();
}

void HKctrl::on_change_clicked()
{
    change();
}
