#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define ElemType int
ElemType e;
//单链表结点数据结构
typedef struct LNode
{
    ElemType data;//数据域
    struct LNode* next;//指针域
}LNode, * LinkList;
//**************************基本操作函数***************************//
//初始化函数
Status InitList(LinkList& L,LinkList& T)
{
    L = new LNode;//生成头结点 这样删除等操作就不必分第一个结点和其他了
    L->next = NULL;
    T = new LNode;
    T->next = NULL;
    return 1;
}
//获取单链表长度 头结点无数据，不算
int ListLength(LinkList L)
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
bool ListInsert(LinkList& L, int i, ElemType e)
{
    LNode* s; LinkList p = L; int j = 0;
    while (p && (j < i - 1))//j指到i-1位置或者p已经到最后时跳出
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)//i<1或者i>ListLength(L)+1时,插入位置无效 不调用ListLength,提高效率
    {
        cout << "插入位置无效！！" << endl;
        return false;
    }
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//删除函数 删除位置i的结点 即删除i-1之后的结点
bool ListDelete(LinkList& L, int i)
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
        cout << "删除位置无效！！" << endl;
        return false;
    }
    q = p->next;
    p->next = q->next;
    free(q);//释放空间
    return true;
}
//查找函数 按值查找 查找第一个等于e的结点 成功返回该结点指针，否则返回NULL
LNode* LocateElem(LinkList L, ElemType e)
{
    LNode* p = L;
    int m = 0;
    while (p && (p->data != e))
    {
        p = p->next;
        m++;
    }
    cout << "目标在："<<m << endl;
    return p;
}
//**************************功能实现函数**************************//
//遍历输出函数
void PrintList(LinkList L)
{
    LinkList p = L->next;//跳过头结点
    if (ListLength(L))
    {
        printf("当前单链表所有元素:");
        while (p)
        {
            cout << p->data<<" "<<&p->data<<" ";
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "当前链表为空" << endl;
    }
}
//插入功能函数 调用ListInsert后插
void Insert(LinkList& L, ElemType e)
{
    int place;  bool flag;
    //cout << "请输入要插入的值" << endl;
    place = ListLength(L) + 1;
    //cin >> e;
    flag = ListInsert(L, place, e);
    if (flag)
    {
        cout << "插入成功" << endl;
        PrintList(L);
    }
}
//删除功能函数 调用ListDelete删除
void Delete(LinkList L)
{
    int place; bool flag;
    cout<<"请输入要删除的位置(从1开始)"<<endl;
    cin >> place;
    flag = ListDelete(L, place);
    if (flag)
    {
        printf("删除成功！！！\n");
        PrintList(L);
    }
}
//查找功能函数 调用LocateElem查找
void Search(LinkList L)
{
    ElemType e; LNode* q;
    cout << "请输入要查找的值" << endl;
    cin >> e;
    q = LocateElem(L, e);
    if (q)
    {
        cout << "找到该元素！" << endl;
    }
    else
    {
        cout << "未找到该元素" << endl;
    }
}

void reBuild(LinkList L,LinkList T)
{
    int m=0;
    int n=0;
    
    cout << "请输入m" ;
    cin >> m;
    cout << "请输入n" ;
    cin >> n;

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

    /*cout << p->data << endl;
    cout << q->next->data << endl;
    cout << r->data << endl;
    cout << T->data << endl;
    cout << T->next->data << endl;*/
   
    cout << "length" << ListLength(L) << endl;

    r->next = p;
    q->next = p;
    
    /*cout << p->data << endl;
    cout << q->next->data << endl;
    cout << r->data << endl;
    cout << r->next->data << endl;
    cout << T->data << endl;
    cout << T->next->data << endl;*/
}

void isExitsLoop(LinkList L)
{
    LNode* walker = L; LNode* runner = L;
    while (runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner)
        {
            cout << "----存在环----" << endl;
            //free(walker); 
            //free(runner);
            break;
        }
    }
}


void EntryNodeOfLoop(LinkList h)
{
    LNode* walker = h->next;
    LNode* runner = h->next;
    while (runner != nullptr && runner->next != nullptr)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner)
        {
            cout << "----存在环----" << endl;
            LNode* p = h->next;
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
                cout << "m为：" << q->data << endl;
                cout << "n为：" << p->data << endl;
                break;
            }
        }
    }
}


LNode* EntryNode(LinkList h)
{
    LNode* walker = h->next;
    LNode* runner = h->next;
    while (runner != nullptr && runner->next != nullptr)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner)
        {
            cout << "----存在环----" << endl;
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


void lift(LinkList L)
{
    LNode* p = EntryNode(L);
    while (p->next != EntryNode(L))
    {
        p = p->next;
    }
    p->next = nullptr;
}


LNode* IsIntersect(LinkList L, LinkList T)
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
            cout << "相交了" << endl;
            return p;
        }
    }
    return nullptr;
}



//菜单
void menu()
{
    printf("********1.插入    2.删除*********\n");
    printf("********3.查找    4.输出*********\n");
    printf("********5.退出    6.检索*********\n");
    printf("********7.查环    8.稍后*********\n");
}
//主函数
int main()
{
    LinkList L; LinkList T; int choice;
    InitList(L,T);
    while (1)
    {
        menu();
        printf("请输入菜单序号：\n");
        cin >> choice;
        if (choice == 5) break;
        switch (choice)
        {
        case 1:
            cout << "请输入要插入的值" << endl;
            cin >> e;
            Insert(L,e); break;
        case 2:Delete(L); break;
        case 3:Search(L); break;
        case 4:PrintList(L); break;
        case 6:reBuild(L,T);break;
        case 7:isExitsLoop(L); break;
        case 8:
            //EntryNodeOfLoop(L);
            cout << EntryNode(L)->data<<endl;break;
        case 9: 
            lift(L);
            IsIntersect(L, T) ;
            break;
        default:printf("输入错误！！！\n");
        }
    }
    return 0;
}