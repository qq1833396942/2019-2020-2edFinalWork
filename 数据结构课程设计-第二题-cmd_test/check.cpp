/*
 * @Author: your name
 * @Date: 2020-05-17 13:36:49
 * @LastEditTime: 2020-05-23 14:22:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 */ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int N=6e4;
int n,m,t,tot=0,atot=0,btot=0,ctot=0;

int d[N],query[N],f[N][20]; //d深度，query队列，f编号
queue<int> q;

int ver[2*N],edge[2*N],Next[2*N],head[N]; //定义邻接表

bool ok,sta[N],need[N];

ll ans,tim[N],ned[N],dist[N][20];
pair<ll,int> h[N];

//1、输入
void add(int x,int y,int z)
{
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}


//2、树上倍增预处理
void bfs()
{
	q.push(1);
	d[1]=1;
	while(q.size())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=Next[i])	//遍历x的出边
		{
			int y=ver[i];
			if(d[y])
				continue;	//若深度小于当前节点，说明是当前节点的父节点
			d[y]=d[x]+1;	//深度加一
			f[y][0]=x,dist[y][0]=edge[i];	//递推初值
			for(int j=1;j<=t;j++)
			{
				f[y][j]=f[f[y][j-1]][j-1];
				dist[y][j]=dist[y][j-1]+dist[f[y][j-1]][j-1];
			}//递推
			q.push(y);
		}
	}
}

//5、dfs寻找路径未被驻扎的叶子节点
bool dfs(int x)
{
	bool pson=0;	//判断是否为叶子节点
	if(sta[x])
		return 1;	//若当前节点已被驻扎，则返回1
	for(int i=head[x];i;i=Next[i])	//遍历x的出边
	{
		int y=ver[i];
		if(d[y]<d[x])
			continue;	//遇到父节点
		pson=1;		//若有一条不是连接着父节点的边，说明不是叶子节点
		if(!dfs(y))	//若某个子节点搜索时遇到路径未被驻扎的叶子节点，直接返回0
			return 0;
	}
	if(!pson)	//当前节点是叶子节点且未被驻扎
		return 0;
	return 1;	//没有遇到路径未被驻扎的叶子节点，返回1
}

bool check(ll lim)
{
	//4、上移军队并处理闲置军队
	memset(sta,0,sizeof(sta));
	memset(tim,0,sizeof(tim));
	memset(ned,0,sizeof(ned));
	memset(h,0,sizeof(h));
	memset(need,0,sizeof(need));
	atot=0,btot=0,ctot=0;//初始化
	for(int i=1;i<=m;i++)
	{
		ll x=query[i],cnt=0;	//cnt统计时间花费
		for(int j=t;j>=0;j--)	//从logn到0枚举
			if(f[x][j]>1 && cnt+dist[x][j]<=lim)	//若终点在根节点之前且不会超过时限
			{
				cnt+=dist[x][j];
				x=f[x][j];
			}
		if(f[x][0]==1 && cnt+dist[x][0]<=lim)	//若当前节点为根节点的子节点且该军队可以在时限内到达根节点
			h[++ctot]=make_pair(lim-cnt-dist[x][0],x);	//存储闲置军队
		else
			sta[x]=1;	//已驻扎标记
	}

	for(int i=head[1];i;i=Next[i])	//遍历根节点的子节点
		if(!dfs(ver[i]))	//若需要被驻扎
			need[ver[i]]=1;//5、dfs寻找路径未被驻扎的叶子节点

	//对于任意一个需要被驻扎的节点，若它上面停留着一支军队不能到达根节点并返回该节点，
	//则令其驻扎在该节点；另外的，因为一个节点只需要一支军队驻扎，
	//因此我们在这里选择剩余时间最小的节点。所以在处理前要先将hh数组按照剩余时间从小到大排序。

	sort(h+1,h+ctot+1);		//排序，二元组按照第一维大小排序
	for(int i=1;i<=ctot;i++)	//遍历所有闲置的军队
		if(need[h[i].second] && h[i].first<dist[h[i].second][0])	//若该军队所处的节点需要被驻扎且该军队无法到达根节点并返回
			need[h[i].second]=0;	//去除标记
		else
			tim[++atot]=h[i].first;//6、对根节点的需要被驻扎的子节点进行初步处理

	for(int i=head[1];i;i=Next[i])
		if(need[ver[i]])
			ned[++btot]=dist[ver[i]][0];//7、找到仍需要被驻扎的节点并存储

	//这里有一个贪心策略：对于现在闲置的军队和需要被驻扎的节点，
	//让剩余时间小的军队优先驻扎在距离根节点近的节点,保证决策最优
	//匹配过后，若所有需要被驻扎的节点都已有军队驻扎，则说明当前的时限可行；反之则不可行。
	if(atot<btot)
		return 0;
	sort(tim+1,tim+atot+1),sort(ned+1,ned+btot+1);
	int i=1,j=1;
	while(i<=btot && j<=atot)
		if(tim[j]>=ned[i])
		{
			i++,j++;
		}
		else
			j++;
	if(i>btot)
		return 1;
	return 0;//8、利用贪心策略完成最后的匹配
}


int main()
{
	ll l=0,r=0,mid;
	cin>>n;
	t=log2(n)+1;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
		r+=z;
	}//1、输入
	bfs();//2、树上倍增预处理
	cin>>m;
	for(int i=1;i<=m;i++)
		scanf("%d",&query[i]);
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid-1;
			ans=mid;
			ok=1;
		}
		else
			l=mid+1;//1、输入
	}//3、二分答案
	if(!ok)
		cout<<-1;
	else
		cout<<ans;//9、特判并输出
	return 0;
}