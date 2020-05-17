#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitList(L,T);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::cutm(int m)
{
    //对m前的数据进行剪切
    LinkList p = L->next;//跳过头结点
    QString string_1;

    //剪切头结点到m
    while (p->data!=m)
    {
        QString element; //转化为字符串
        element = QString::number(p->data);
        string_1 = string_1 + element + " ";

        p = p->next;
    }
    ui->textBrowser_2->setText(string_1);
}


void MainWindow::cutmn(int m,int n)
{
    LNode* p;
    QString string;
    QString element;
    QString tail;
    p=LocateElem(L,m);  //定位到m节点

    //剪切从m到n
    while(p->data!=n){
        element = QString::number(p->data);
        string = string + element + " ";
        p=p->next;
    }
    element = QString::number(p->data);
    string = string + element + " ";
    ui->textBrowser_4->setText(string);

    //剪切从n到结尾
    while(p->next!=nullptr){
        element = QString::number(p->next->data);
        tail = tail + element + " ";
        p=p->next;
    }
    ui->textBrowser_3->setText(tail);
}


void MainWindow::EntryNodeOfLoop(LinkList L)
{
    LNode* walker = L->next;
    LNode* runner = L->next;
    QString msg="从原始链表头L检查：发现存在环";
    QString prompt="环路出现的位置在";
    while (runner != nullptr && runner->next != nullptr)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner)
        {
            LNode* p = L->next;
            LNode* q = walker;
            while (p != q)
            {
                p = p->next;
                q = q->next;
            }
            if (p == q)
            {
                while (p->next != q)
                {
                    p = p->next;
                }
                qDebug() << "从原始链表头L开始发现存在环" << endl;
                qDebug() << "m为：" << q->data << endl;
                qDebug() << "n为：" << p->data << endl;
                QString p_data = QString::number(p->data);
                QString q_data = QString::number(q->data);
                QMessageBox msgbox;
                msgbox.setText(msg+"\n"+prompt+q_data+" "+p_data);
                msgbox.addButton("确定",QMessageBox::AcceptRole);
                msgbox.exec();
                break;
            }
        }
    }
}


void MainWindow::EntryNodeOfToop(LinkList L)
{
    LNode* walker = L->next;
    LNode* runner = L->next;
    QString msg="从第二链表头T检查：发现存在环";
    QString prompt="环路出现的位置在";
    while (runner != nullptr && runner->next != nullptr)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner)
        {
            LNode* p = L->next;
            LNode* q = walker;
            while (p != q)
            {
                p = p->next;
                q = q->next;
            }
            if (p == q)
            {
                while (p->next != q)
                {
                    p = p->next;
                }
                qDebug() << "从第二链表头T开始发现存在环" << endl;
                qDebug() << "m为：" << q->data << endl;
                qDebug() << "n为：" << p->data << endl;
                QString p_data = QString::number(p->data);
                QString q_data = QString::number(q->data);
                QMessageBox msgbox;
                msgbox.setText(msg+"\n"+prompt+q_data+" "+p_data);
                msgbox.addButton("确定",QMessageBox::AcceptRole);
                msgbox.exec();
                break;
            }
        }
        else
        {
            qDebug()<<"不存在环"<<endl;
        }
    }
}


void MainWindow::reBuild(LinkList L,LinkList T,int m,int n)
{
    //定位m
    LNode* p = LocateElem(L, m);
    LNode* q = p;
    while (q->data != n)
    {
        q = q->next;
    }

    //定位n
    LNode* r = q;
    T->next = q->next;
    while (r->next != nullptr)
    {
        r = r->next;    //定位尾节点r
    }

    qDebug() <<"p节点为"<< p->data << endl;
    qDebug() <<"q连接"<< q->next->data << endl;
    qDebug() <<"r节点为"<< r->data << endl;
    qDebug() <<"T节点为"<< T->data << endl;
    qDebug() <<"T连接"<< T->next->data << endl;

    qDebug() << "length" << ListLength(L) << endl;

    r->next = p;//尾巴指向p
    q->next = p;//

    qDebug() <<"p节点为"<< p->data << endl;
    qDebug() <<"q连接"<< q->next->data << endl;
    qDebug() <<"r节点为"<< r->data << endl;
    qDebug() <<"r连接"<< r->next->data << endl;
    qDebug() <<"T节点为"<< T->data << endl;
    qDebug() <<"T连接"<< T->next->data << endl;
}


LNode* MainWindow::IsIntersect(LinkList L, LinkList T)
{
    LNode* p = L; LNode* q = T;
    int lenL = ListLength(L); int lenT = ListLength(T);

    if (lenL > lenT) {
        for (int i = 0; i < lenL - lenT; i++) {
            p = p->next;
            i++;
        }
    }
    else if (lenT > lenL) {
        for (int i = 0; i < lenT - lenL; i++) {
            q = q->next;
            i++;
        }
    }

    while (p->next != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next;
        if (&p->data == &q->data)
        {
            //qDebug() << "相交在" <<p->data<< endl;
            QString msg="相交在：";
            QString p_data = QString::number(p->data);
            QMessageBox msgbox;
            msgbox.setText(msg+" "+p_data);
            msgbox.addButton("确定",QMessageBox::AcceptRole);
            msgbox.exec();
            return p;
        }
    }
    //qDebug()<<"没相交"<<endl;
    QString msg="未发现相交：";
    QMessageBox msgbox;
    msgbox.setText(msg+" ");
    msgbox.addButton("确定",QMessageBox::AcceptRole);
    msgbox.exec();
    return nullptr;
}


//添加节点
void MainWindow::on_add_clicked()
{
    //获取输入的节点值
    QString value = this->ui->value->text();

    if(value.length()>0)
    {
        int m;
        m = value.toInt();  //转化类型为int，使其与原函数类型相符
        Insert(L,m);    //插入
        this->ui->value->clear();
    }
    else
    {
        QMessageBox::critical(this,"wrong","Wrong Information");
    }
}

//剪切链表
void MainWindow::on_cut_clicked()
{
    QString mp = this->ui->mp->text();
    QString np = this->ui->np->text();
    if(mp.length()==0||np.length()==0)
    {
        QMessageBox::critical(this,"wrong","M or n is NULL, cannot run this function");
    }
    int m=mp.toInt();
    int n=np.toInt();
    if(ListLength(L)<2)
    {
        QMessageBox::critical(this,"wrong","The length of the linked list is less than 2, so this function cannot be run");
    }
    else
    {
        cutm(m);
        cutmn(m,n);
        reBuild(L,T,m,n);
    }
}

//检索完整链表
void MainWindow::on_check_clicked()
{
    LinkList p = L->next;//跳过头结点
    if (ListLength(L))
    {
        QString string;
        qDebug()<<"链表中的元素为"<<endl;
        while (p)
        {
            qDebug()<<p->data<<" "; //打印数据

            QString element; //转化为字符串
            element = QString::number(p->data);
            string = string + element + " ";

            p = p->next;
        }
        qDebug() << endl;
        ui->textBrowser->setText(string);
    }
    else
    {
        QMessageBox::critical(this,"wrong","Linked List Is Null!");
    }
}

void MainWindow::on_LoopA_clicked()
{
    EntryNodeOfLoop(L);
}

void MainWindow::on_LoopB_clicked()
{
    EntryNodeOfToop(T);
}

void MainWindow::on_lift_clicked()
{
    LNode* p=EntryNode(L);
    LNode* q=L;
    QString msg="查询到中间节点值为：";
    int index=0;
    while(p->next!=EntryNode(L))
    {
        p=p->next;
    }
    p->next=nullptr;
    while(index!=(ListLength(L)/2)+1)
    {
        q=q->next;
        index++;
    }

    QString q_data = QString::number(q->data);
    QMessageBox msgbox;
    msgbox.setText(msg+q_data);
    msgbox.addButton("确定",QMessageBox::AcceptRole);
    msgbox.exec();
}


void MainWindow::on_pushButton_clicked()
{
    qDebug()<<IsIntersect(L,T)->data;
}

