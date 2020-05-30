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
#include<Windows.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;   //想想元组，配对，就把他简化一点吧
const int inf = 0x3f3f3f3f;     //设置一个超大值预存
const int maxn = 50;
const int maxm = 5e3;
bool init_done, floyd_done;     //初始化是否完成，弗洛伊德是否进行完成
bool  vis[maxn], adj[maxn][maxn];
int ecnt, head[maxn], dis[maxn], pre[maxn], sta[maxn], g[maxn][maxn];   //g为带权邻接矩阵
struct edge { int v, w, nxt; } e[maxm];     //定义节点

vector<vector<int>> res;    //二维容器
unordered_map<string, int> id; //有点类似哈希表
string city[maxn];
ifstream in_adj("wether.txt");
ifstream in_dis("distance.txt");
ofstream out("output.txt");
ofstream zhongzhuan("zhongzhuan.txt");

void addEdge(int u, int v, int w)
{
    e[ecnt].v = v;
    e[ecnt].w = w;
    e[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

//初始化
void init()
{
    //先进行初始化判断，防止二次初始化
    if (init_done)
    {
        cout << "无需重复初始化" << endl << endl;
        return;
    }
    memset(head, -1, sizeof(head));
    memset(g, 0x3f, sizeof(g));
    //录入城市及其编号
    for (int i = 1; i <= 30; i++)
    {
        in_adj >> city[i];
        id[city[i]] = i;
    }
    for (int i = 1; i <= 30; i++)
    {
        string city_now;
        in_adj >> city_now;             //获取城市名
        int id_now = id[city_now];  //获取城市编号
        for (int j = 1; j <= 30; j++)
        {
            //录入1,0，构造对称
            in_adj >> adj[id_now][j];
            adj[j][id_now] = adj[id_now][j];
        }
    }
    string tmp;
    for (int i = 1; i <= 29; i++) 
    { 
        in_dis >> tmp; 
    }
    for (int i = 1; i <= 30; i++)
    {
        string city_now;
        in_dis >> city_now;
        int id_now = id[city_now];
        for (int j = 1; j <= i - 1; j++)    //斜着的
        {
            int w;
            in_dis >> w;    //w是距离
            if (!adj[id_now][j]) continue;  // 如果为空就continue
            g[id_now][j] = g[j][id_now] = w;    //对称处理
            addEdge(id_now, j, w);
            addEdge(j, id_now, w);  //添加
        }
    }
    cout << "初始化成功" << endl << endl;
    init_done = true;
}

int bfs(int src, int des)
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

void print_wuhan()
{
    bool flag;

    for (int i = 1; i <= 30; i++)
    {
        if (city[i] != "武汉" )
        {
            string str = "到武汉至少中转";
            string ci = "次";
            string value = to_string(bfs(i, id["武汉"]));
            string final = city[i] + str + value + ci;
            //cout << final << endl << endl;
            zhongzhuan << final << endl;
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
        cout << "全国其他省会城市（不包括海口）到武汉中间不超过2个省（省会城市）成立" << endl;
    }
    else {
        cout << "全国其他省会城市（不包括海口）到武汉中间不超过2个省（省会城市）不成立" << endl;
        cout << "具体可查看文件  zhongzhuan.txt" << endl;
    }
}

void dfs(int now, int des, int step, int sum, vector<int> storage)
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
bool compare(const vector<int>& va, const vector<int>& vb)
{
    return va[va.size() - 1] < vb[vb.size() - 1];
}

void getPath()
{
    res.clear();    //res二维容器，清除错误状态
    memset(vis, false, sizeof(vis));    //设置为FALSE
    string begin, end;
    cout << "请输入出发城市：" << endl;
    cin >> begin;
    cout << "请输入终点城市：" << endl;
    cin >> end;

    //判断输入
    if (id.find(begin) == id.end() || id.find(end) == id.end())
    {
        cout << "地点不存在" << endl << endl;
        return;
    }
    int a = id[begin];  //获取编号
    int b = id[end];
    dfs(a, b, 0, 0, {});    //深度遍历
    sort(res.begin(), res.end(), compare);      //用总长度对res中的所有遍历结果排序
    int cnt = 0;

    for (auto vec : res)    // for each 类型的loop
    {
        out << "第 " << ++cnt << " 条路径" << endl;
        for (int i = 0; i < vec.size() - 2; i++)
            out << "从 " << city[vec[i]] << " 到 " << city[vec[i + 1]] << endl;
        out << "总路程为 " << vec[vec.size() - 1] << endl << endl;
    }
    cout << "路径已保存到文件" << endl ;
    cout << "限制步数：10，调整函数内部参数可以修改" << endl;
    cout << endl;
}

void dijkstra(bool flag)
{
    string begin;
    string end;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    cout << "请输入出发城市：" << endl;
    cin >> begin;
    cout << "请输入终点城市：" << endl;
    cin >> end;
    if (id.find(begin) == id.end() || id.find(end) == id.end())
    {
        cout << "地点不存在" << endl << endl;
        return;
    }
    int id_site = 0;
    if (flag)   //做绕开处理
    {
        string out;
        cout << "请请输入需要绕开的名称: ";
        
        cin >> out;
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
    cout << endl << begin<< " 到 " << end<< " 的最短路径如下: " << endl;
    int top = 0;
    for (int i = b; i != a; i = pre[i]) sta[top++] = i;
    for (int i = top - 1, last = a; i >= 0; i--)
    {
        int u = last, v = sta[i];
        cout << "从 " << city[u] << " 到 " << city[v] << endl;
        last = v;
    }
    cout << "总路程为 " << dis[b] << endl << endl;
}

void floyd(int n)
{
    string begin;   //出发城市
    string end;      //终点城市
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
    cout << "请输入出发城市：" << endl;
    cin >> begin;
    cout << "请输入终点城市：" << endl;
    cin >> end; 
    if (id.find(begin) == id.end() || id.find(end) == id.end())
    {
        cout << "地点不存在" << endl << endl;
        return;
    }
    int a = id[begin];
    int b = id[end];     //获取矩阵中的行列坐标
    cout << endl << begin<< " 到 " << end<< " 的最短路径为: " << g[a][b] << endl << endl;
}



bool chooseFunc()
{
    bool flag;
    int num=0;
    cout << "请输入希望信息停留的事件（单位：秒）" << endl;
    cin >> num;
    while (true) {
        cout << "请选择功能" << endl;
        cout << "1.获取各城市到武汉中转次数" << endl;
        cout << "2.获取指定起点到终点的所有路径" << endl;
        cout << "3.Dijkstra算法求解最短路径" << endl;
        cout << "4.Floyd算法求解最短路径" << endl;
        cout << "5.绕开特定城市求解最短路径" << endl;
        cout << "6.退出程序" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1: print_wuhan(); break;
        case 2: getPath(); break;
        case 3: dijkstra(false); break;
        case 4: floyd(30); break;
        case 5: dijkstra(true); break;
        case 6: cout << "退出程序"; return 0;
        default: cout << "指令无效，请重新输入" << endl;
        }
        cout << endl << "信息将会显示"<<num<<"s" << endl;
        Sleep(num*1000);
        system("cls");
    }
    _getch();
}


int main()
{
    init();
    chooseFunc();
    return 0;
}