#include "glctrl.h"
#include "ui_glctrl.h"

GLctrl::GLctrl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GLctrl)
{
    ui->setupUi(this);
    search();
}

GLctrl::~GLctrl()
{
    delete ui;
}

void GLctrl::search(){

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from GL");
    ui->tableView->setModel(model);
    //设置效果
    ui->tableView->setAlternatingRowColors(true);
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView->setRowHeight(i, 20);
    }
}

void GLctrl::addInfo(){
    QSqlQuery q;
    q.prepare("insert into GL values (?,?,?,?)");
    q.addBindValue(this->ui->name->text());
    q.addBindValue(this->ui->id->text());
    q.addBindValue(this->ui->sex->text());
    q.addBindValue(this->ui->password->text());
    q.exec();
    search();
}

void GLctrl::judge(){
    //先判断是否输入了姓名与编号
    if(ui->id->text().length()>0 && ui->name->text().length()>0){
        QSqlTableModel model;   //实例化model
        model.setTable("GL");   //设置所需要操作的表格
        model.setFilter(tr("Number= '%1'").arg(ui->id->text()));
        model.select();
        //判断是否重复添加编号
        if(model.rowCount()==1){
            QMessageBox::warning(this,tr("警告"),tr("当前管理员编号重复，请重新设置"),QMessageBox::Yes);   //如果存在则跳转至操作界面
        }
        else{
            addInfo();
        }
    }
    else{
        QMessageBox::warning(this,tr("警告"),tr("姓名或管理员编号为空，请检查后重新添加"),QMessageBox::Yes);
    }
    search();
}


void GLctrl::deleteInfo(){
    int curRow = ui->tableView->currentIndex().row();   //设置行号，准备数据
    QModelIndex index = ui->tableView->currentIndex();
    QString id = index.sibling(curRow,1).data().toString();    //删除data
    QSqlQuery q;
    int ok = QMessageBox::warning(this,tr("删除该户主信息!"),tr("你确定删除当前行吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::Yes){
        q.prepare("delete from GL where Number = (?)");
        q.addBindValue(id);
        q.exec();
    }
    search();
}


void GLctrl::change(){
    QSqlQuery q;
    QModelIndex index = ui->tableView->currentIndex();
    int curRow = ui->tableView->currentIndex().row();
    int curColume = ui->tableView->currentIndex().column();
    if(curColume==0){
        q.prepare("UPDATE GL SET Gname = (?) where Gname = (?) and Number = ?");
        q.addBindValue(ui->name->text());
        q.addBindValue(index.sibling(curRow,0).data().toString());
        q.addBindValue(index.sibling(curRow,1).data().toString());
        q.exec();
    }
    else if(curColume==1){
        QMessageBox::warning(this,tr("警告"),tr("管理员号禁止修改"),QMessageBox::Yes);
    }
    else if(curColume==2){
        q.prepare("UPDATE GL SET Sex = (?) where Number = ?");
        q.addBindValue(ui->sex->text());
        q.addBindValue(index.sibling(curRow,1).data().toString());
        q.exec();
    }
    else if(curColume==3){
        q.prepare("UPADTE GL SET Paswd = ? where Number = ?");
        q.addBindValue(ui->password->text());
        q.addBindValue(index.sibling(curRow,1).data().toString());
        q.exec();
    }

    search();
}


void GLctrl::on_add_clicked()
{
    judge();
}

void GLctrl::on_delete_2_clicked()
{
    deleteInfo();
}

void GLctrl::on_change_clicked()
{
    change();
}

void GLctrl::on_search_clicked()
{
    search();
}
