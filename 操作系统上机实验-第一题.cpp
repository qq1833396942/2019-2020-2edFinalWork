#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class   PCB
{
public:
    string  name;
    int need;//须运行的时间
    int turn;//周转时间
    PCB* next;
    PCB(string n, int a, int b, PCB* next) :name(n), need(a), turn(b), next(next) {}
};

void RR()
{
    PCB* RQ1, * RQ2, * Finish = NULL;
    int clock = 0,max=1000;  //时钟
    //定义各进程的运行时间及等待时间
    PCB* p, * q, * s = NULL;
    int piecetime = 7;
    string name1[5] = { "p1","p2","p3","p4","p5" };
    string name2[5] = { "p6","p7","p8","p9","p10" };
    int need1[5] = { 16,11,14,13,15 };
    int wait1[5] = { 6,5,4,3,2 };
    int need2[5] = { 21,18,10,7,14 };
    int wait2[5] = { 1,2,3,4,5 };
    RQ1 = new PCB(name1[0], need1[0], wait1[0], NULL);
    p = RQ1;
    for (int i = 1; i < 5; i++) {
        q = new PCB(name1[i], need1[i], wait1[i], NULL);
        p->next = q;
        p = p->next;
    }
    RQ2 = new PCB(name2[0], need2[0], wait2[0], NULL);
    p = RQ2;
    for (int i = 1; i < 5; i++) {
        q = new PCB(name2[i], need2[i], wait2[i], NULL);
        p->next = q;
        p = p->next;
    }

    p = RQ1;
    while (p)
    {
        bool flag = false;
        if (p->need)
        {
            q = p;
            while (q->next)q = q->next;//q指针指向最后一个结点
            if (p->need > piecetime) //如果该节点表示的进程还需的时间大于一个时间片
            {
                clock += piecetime;
                p->need -= piecetime;
                //把刚运行了一个时间片的结点放到队列尾部
                q->next = p;
                p = p->next;
                q->next->next = NULL;
            }
            else
            {
                clock += p->need;
                p->turn += clock;
                p->need = 0;
                if (s == NULL)
                {
                    s = p;
                    Finish = s; //Finish指针指向最后运行后的链表的第一个节点
                    flag = true;
                }
                else s->next = p;
                if (flag == false)s = s->next;
            }
        }
        else p = p->next;
    }
    RQ1 = Finish;

    for (int i = 0; i < 5; i++)
    {
        p = RQ2;
        q = RQ2;
        while (q) //找到所需时间最短的进程
        {
            if (q->need < p->need)p = q;
            q = q->next;
        }
        clock += p->need;
        p->turn += clock;
        p->need = max;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << RQ1->name << ":" << RQ1->turn << endl;
        RQ1 = RQ1->next;
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << RQ2->name << ":" << RQ2->turn << endl;
        RQ2 = RQ2->next;
    }


}

void main() {
    RR();
}