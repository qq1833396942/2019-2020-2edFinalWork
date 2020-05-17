#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QDebug>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
//#define Status int
#define ElemType int

//单链表结点数据结构
typedef struct LNode
{
    ElemType data;//数据域
    struct LNode* next;//指针域
}LNode, * LinkList;


//**************************基本操作函数***************************//
//初始化函数
static int InitList(LinkList& L,LinkList& T)
{
    L = new LNode;//生成头结点 这样删除等操作就不必分第一个结点和其他了
    L->next = NULL;
    T = new LNode;//生成第二头结点
    T->next = NULL;
    qDebug()<<"初始化成功"<<endl;
    return 1;
}


//获取单链表长度 头结点无数据，不算
static int ListLength(LinkList L)
{
    LinkList p = L; int sum = 0;
    while (p)
    {
        sum++;
        p = p->next;
    }
    return sum - 1;//去除头结点
}


//插入函数--后插法 插入到第i(1<=i<=length+1)个位置 即i-1之后 不必区分i的位置
static bool ListInsert(LinkList& L, int i, ElemType e)
{
    LNode* s; LinkList p = L; int j = 0;
    while (p && (j < i - 1))//j指到i-1位置或者p已经到最后时跳出
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)//i<1或者i>ListLength(L)+1时,插入位置无效 不调用ListLength,提高效率
    {
        qDebug() << "插入位置无效！！" << endl;
        return false;
    }
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


//删除函数 删除位置i的结点 即删除i-1之后的结点
static bool ListDelete(LinkList& L, int i)
{
    LinkList p = L; int j = 0;
    LinkList q;
    while (p && (j < i - 1))//j指到i-1位置
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)//i<1或者i>ListLength(L)时,删除位置无效
    {
        qDebug() << "删除位置无效！！" << endl;
        return false;
    }
    q = p->next;
    p->next = q->next;
    free(q);//释放空间
    return true;
}


//查找函数 按值查找 查找第一个等于e的结点 成功返回该结点指针，否则返回NULL
static LNode* LocateElem(LinkList L, ElemType e)
{
    LNode* p = L;
    int m = 0;
    while (p && (p->data != e))
    {
        p = p->next;
        m++;
    }
    qDebug()<<"目标元素位置在"<<m<<endl;
    return p;
}

//**************************功能实现函数**************************//
//遍历输出函数
static void PrintList(LinkList L)
{
    LinkList p = L->next;//跳过头结点
    if (ListLength(L))
    {
        qDebug()<<"链表中的元素为"<<endl;
        while (p)
        {
            qDebug()<<p->data<<" ";
            p = p->next;
        }
        qDebug() << endl;
    }
    else
    {
        qDebug() << "当前链表为空" << endl;
    }
}


//插入功能函数 调用ListInsert后插
static void Insert(LinkList& L,ElemType e)
{
    int place; bool flag;
    qDebug() << "插入的值:" <<e<< endl;
    place = ListLength(L) + 1;

    flag = ListInsert(L, place, e);
    if (flag)
    {
        qDebug() << "插入成功" << endl;
        PrintList(L);
    }
}


//删除功能函数 调用ListDelete删除
static void Delete(LinkList L)
{
    int place; bool flag;
    qDebug()<<"请输入要删除的位置(从1开始)"<<endl;
    cin >> place;
    flag = ListDelete(L, place);
    if (flag)
    {
        printf("删除成功！！！\n");
        PrintList(L);
    }
}


//查找功能函数 调用LocateElem查找
static void Search(LinkList L,ElemType e)
{
    LNode* q;
    qDebug() << "请输入要查找的值" << endl;

    q = LocateElem(L, e);
    if (q)
    {
        qDebug() << "找到该元素！" << endl;
    }
    else
    {
        qDebug() << "未找到该元素" << endl;
    }
}


static LNode* EntryNode(LinkList h)
{
    LNode* walker = h->next;
    LNode* runner = h->next;
    while (runner != nullptr && runner->next != nullptr)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner)
        {
            qDebug() << "发现环！！" << endl;
            LNode* p = h->next;
            LNode* q = walker;
            while (p != q)
            {
                p = p->next;
                q = q->next;
            }
            return q;
        }
    }
}


#endif // LINKEDLIST_H
