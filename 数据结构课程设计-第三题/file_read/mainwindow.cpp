#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include <typeinfo>
#include <Windows.h>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    init();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

typedef long long ll;
typedef std::pair<int, int> p;   //想想元组，配对，就把他简化一点吧
const int inf = 0x3f3f3f3f;     //设置一个超大值预存
const int maxn = 50;
const int maxm = 5e3;
bool init_done=false, floyd_done;     //初始化是否完成，弗洛伊德是否进行完成
bool  vis[maxn], adj[maxn][maxn];
int num[maxn][maxn];
int ecnt, head[maxn], dis[maxn], pre[maxn], sta[maxn], g[maxn][maxn];   //g为带权邻接矩阵
struct edge { int v, w, nxt; } e[maxm];     //定义节点

QVector<QVector<int>> res;    //二维容器
std::unordered_map<QString, int> id; //有点类似哈希表
QString city[maxn];


void MainWindow::addEdge(int u, int v, int w)
{
    e[ecnt].v = v;
    e[ecnt].w = w;
    e[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void MainWindow::init()
{
    //先进行初始化判断，防止二次初始化
    if (init_done)
    {
        qDebug() << "无需重复初始化" << endl << endl;
        return;
    }
    memset(head, -1, sizeof(head));
    memset(g, 0x3f, sizeof(g));


    QFile in_adj("D:/file_read/boo.txt");    //读取文件
    qDebug()<<in_adj.exists();
    QFile in_dis("D:/file_read/dis.txt");    //读取文件
    qDebug()<<in_dis.exists();

    if(!in_dis.open(QIODevice::ReadOnly)){
        qDebug()<<"fail";
        return;
    }

    if(!in_adj.open(QIODevice::ReadOnly)){
        qDebug()<<"afail";
        return;
    }
    QTextStream adjfile(&in_adj);
    QTextStream disfile(&in_dis);


    //录入城市及其编号
    for (int i = 1; i <= 30; i++)
    {
        adjfile >> city[i];
        id[city[i]] = i;
    }
    for (int i = 1; i <= 30; i++)
    {
        QString city_now;
        adjfile >> city_now;             //获取城市名
        int id_now = id[city_now];  //获取城市编号
        for (int j = 1; j <= 30; j++)
        {
            //录入1,0，构造对称
            //adjfile >> adj[id_now][j];
            adjfile >> num[id_now][j];
            adj[id_now][j]=num[id_now][j];
            adj[j][id_now] = adj[id_now][j];
        }
    }

    QString tmp;
    for (int i = 1; i <= 29; i++)
    {
        disfile >> tmp;
        qDebug()<<tmp;
    }

    for (int i = 1; i <= 30; i++)
    {
        QString city_now;
        disfile >> city_now;
        int id_now = id[city_now];
        for (int j = 1; j <= i - 1; j++)    //斜着的
        {
            int w;
            disfile >> w;    //w是距离
            qDebug()<<w;
            if (!adj[id_now][j]) continue;  // 如果为空就continue
            g[id_now][j] = g[j][id_now] = w;    //对称处理
            qDebug()<<"hello"<<g[id_now][j];
            addEdge(id_now, j, w);
            addEdge(j, id_now, w);  //添加
        }
    }
    qDebug() << "初始化成功" << endl << endl;
    init_done = true;

}

//疯狂遍历
int MainWindow::bfs(int src, int des)
{
    memset(vis, false, sizeof(vis));    //全部设为FALSE
    queue<p> q;     //定义队列q
    vis[src] = true;    //起始城市设置为true
    q.push(p(src, 0));  //入队
    while (!q.empty())
    {
        int u = q.front().first, s = q.front().second;
        if (u == des) return s - 1;     //相同跳出
        q.pop();

        for (int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (!vis[v])    //没进来过继续
            {
                vis[v] = true;
                q.push(p(v, s + 1));
            }
        }
    }
    return inf;
}

//去武汉的函数
void MainWindow::print_wuhan()
{
    bool flag;

    for (int i = 1; i <= 30; i++)
    {
        if (city[i] != "武汉" )
        {
            QString str = "到武汉至少中转";
            QString ci = "次";
            QString value = QString::number(bfs(i, id["武汉"]));
            QString final = city[i] + str + value + ci;
            string conl = final.toStdString();
            //cout << final << endl << endl;
            //zhongzhuan << conl << endl;
        }
    }
    for (int i = 1; i <= 30; i++)
    {
        if (city[i] != "武汉")
        {
            int a = bfs(i, id["武汉"]);
            if (a <= 2) {
                flag = true;
            }
            else {
                flag = false;
            }
        }
    }
    if (flag) {
        this->ui->textBrowser->append("全国其他省会城市（不包括海口）到武汉中间不超过2个省（省会城市）成立");
    }
    else {
        this->ui->textBrowser->append("全国其他省会城市（不包括海口）到武汉中间不超过2个省（省会城市）不成立");
        this->ui->textBrowser->append("具体可查看文件  zhongzhuan.txt");
    }
}

//遍历
void MainWindow::dfs(int now, int des, int step, int sum, QVector<int> storage)
{
    if (step > 10) {
        return;        //可以修改步数
    }
    vis[now] = true;
    storage.push_back(now);     //将路径加入vactor
    if (now == des)
    {
        storage.push_back(sum);     //结束，结算总长度
        res.push_back(storage);       //整个遍历的顺序vector存入res
        return;     //当遍历到了自己说明一圈都遍历了，直接返回就好，把自己这个容器加进res
    }
    for (int i = head[now]; ~i; i = e[i].nxt)
    {
        int nxt = e[i].v;
        if (vis[nxt])
        {
            continue;
        }
        //采用递归的方法去遍历
        dfs(nxt, des, step + 1, sum + e[i].w, storage);
        vis[nxt] = false;
    }
}

//用于比较最后总长度大小
bool MainWindow::compare(const QVector<int>& va, const QVector<int>& vb)
{
    return va[va.size() - 1] < vb[vb.size() - 1];
}

void MainWindow::getPath()
{
    res.clear();    //res二维容器，清除错误状态
    memset(vis, false, sizeof(vis));    //设置为FALSE
    QString begin = this->ui->begin->text();
    QString end = this->ui->end->text();

    this->ui->textBrowser->append("请等待，正在计算中");

    //判断输入
    if (id.find(begin) == id.end() || id.find(end) == id.end())
    {
        qDebug() << "地点不存在" << endl << endl;
        this->ui->textBrowser->append("地点不存在");
        return;
    }
    int a = id[begin];  //获取编号
    int b = id[end];
    dfs(a, b, 0, 0, {});    //深度遍历
    sort(res.begin(), res.end(), compare);      //用总长度对res中的所有遍历结果排序
    int cnt = 0;

    string cong="从",dao="到",zong="总路程为 ",str1,str2;
    QString total = QString::fromStdString(zong),key1;
    int count;
    for (auto vec : res)    // for each 类型的loop
    {
        QString number = QString::number(++cnt);
        this->ui->textBrowser->append("第"+number+" 条路径");
        for (int i = 0; i < vec.size() - 2; i++){
            count = vec[vec.size() - 1];
            str1 = city[vec[i]].toStdString(),str2 = city[vec[i+1]].toStdString();
            key1 = QString::fromStdString(cong+str1+dao+str2);
            this->ui->textBrowser->append(key1);

        }
        QString index = QString::number(count);
        this->ui->textBrowser->append(total+index+"\n");
    }
    this->ui->textBrowser->append("限制步数：10，调整函数内部参数可以修改");
}

void MainWindow::dijkstra(bool flag)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    QString begin = this->ui->begin->text();
    QString end = this->ui->end->text();

    if (id.find(begin) == id.end() || id.find(end) == id.end())
    {
        cout << "地点不存在" << endl << endl;
        return;
    }
    int id_site = 0;
    if (flag)   //做绕开处理
    {
        QString out = this->ui->dont->text();
        if (id.find(out) == id.end())
        {
            cout << "地点不存在" << endl << endl;
            return;
        }
        id_site = id[out];
    }
    priority_queue<p, vector<p>, greater<p> > q;
    /*
        使用优先队列，数据类型pair(理解为元组不知是否恰当)
        Container 容器类型，Container必须是用数组实现的容器，比如vector,deque等等
        容器类型选择的vector，vector类型选择了pair
        greater表示了升序队列
        优先队列与队列操作基本相同，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的
    */
    int a = id[begin];
    int b = id[end];
    q.push(p(dis[a] = 0, a));     //入队
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].v, w = e[i].w;
            if (v != id_site && dis[v] > dis[u] + w)
            {
                pre[v] = u;
                dis[v] = dis[u] + w;
                q.push(p(dis[v], v));
            }
        }
    }

    QString dao = "到",path = "的最短路径如下:",cong="从";
    this->ui->textBrowser->append(begin+dao+end+path+" ");
    int top = 0;
    for (int i = b; i != a; i = pre[i]) sta[top++] = i;
    for (int i = top - 1, last = a; i >= 0; i--)
    {
        int u = last, v = sta[i];
        string chufa2=city[u].toStdString(),zhongdian2 = city[v].toStdString();
        this->ui->textBrowser->append(cong+city[u]+dao+city[v]);
        qDebug()<<"从"<<city[u]<<"到"<<city[v];
        last = v;
    }
    QString mindis = QString::number(dis[b]);
    this->ui->textBrowser->append("总路程为："+mindis+"\n");
}

void MainWindow::floyd(int n)
{
    QString begin = this->ui->begin->text();
    QString end = this->ui->end->text();

    if (!floyd_done)    //查找最小距离并修改矩阵对应值
    {
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }
    floyd_done = true;      //修改判别，只运算一次最短路径

    if (id.find(begin) == id.end() || id.find(end) == id.end())
    {
        cout << "地点不存在" << endl << endl;
        return;
    }
    int a = id[begin];
    int b = id[end];     //获取矩阵中的行列坐标
    QString dis = QString::number(g[a][b]);
    this->ui->textBrowser->append(begin+"到"+end+"的最短路径为："+dis+"\n");
    qDebug() << endl << begin<< " 到 " << end<< " 的最短路径为: " << dis << endl << endl;
}

void MainWindow::on_toWuhan_clicked()
{
    print_wuhan();
}

void MainWindow::on_getpath_clicked()
{
    getPath();
}

void MainWindow::on_floyd_clicked()
{
    floyd(30);
}

void MainWindow::on_dijkstra_clicked()
{
    dijkstra(false);
}

void MainWindow::on_pass_clicked()
{
    dijkstra(true);
}

void MainWindow::on_exit_clicked()
{
    this->close();
}

