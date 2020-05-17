#include<linkedlist.h>
#include<QMessageBox>

void isExitsLoop(LinkList L)
{
    LNode* walker = L; LNode* runner = L;
    while (runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner)
        {
            QMessageBox msgbox;
            msgbox.setText("从原始链表头L检查：发现存在环");
            msgbox.addButton("确定",QMessageBox::AcceptRole);
            msgbox.exec();
            qDebug() << "从原始链表头L开始发现存在环" << endl;
            break;
        }
    }
}


void isExitsToop(LinkList T)
{
    LNode* walker = T; LNode* runner = T;
    while (runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner)
        {
            QMessageBox msgbox;
            msgbox.setText("从第二链表头T检查：发现存在环");
            msgbox.addButton("确定",QMessageBox::AcceptRole);
            msgbox.exec();
            qDebug() << "从第二链表头T开始发现存在环" << endl;
            break;
        }
    }
}
