#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,fi[100001],ne[100001],w[100001],v[100001];
int cnt,x,y,val,tot,arm[50001],ho[50001],dis[50001];
int ti[50001],gra[50001],na,nc,cal[50001];
bool b[50001];
struct node{
    int x,v;
}arre[50001],coo[50001];  //多出来的，缺少的 
bool cmp(node u,node v)
{
    return u.v>v.v;
}
void addedge(int u,int vv,int z)
{
    w[++cnt]=vv;ne[cnt]=fi[u];fi[u]=cnt;v[cnt]=z;
}
void dfs(int u)
{
    int maxx=-1,now1=0,now2=0;
    for(int i=fi[u];i;i=ne[i])
      if(w[i]!=ho[u])  //保证向下走 
      {
          dfs(w[i]);
          if(ti[w[i]]==-1) now2=1;  //该点需要军队弥补 
          if(ti[w[i]]>=v[i]) now1=1;  //可以走到该点 
          maxx=max(maxx,ti[w[i]]-v[i]);
      }
    if(u!=1 && ne[fi[u]])  //不是根节点且不是独苗（即有多个子节点的非根节点） 
    {
        if(now1) ti[u]=max(ti[u],maxx);  //所有点中走得最长的一个记为该点剩下的长度 
        else if(now2) ti[u]=max(ti[u],-1);  //没有军队到达子节点，最低记为-1 
        else ti[u]=max(ti[u],0);  //每个子节点都有军队，但在该点的子节点与该点之间结束 
    }
}
void maketi(int u)
{
    for(int i=1;i<=m;i++)
      if(dis[arm[i]]>=u) ti[arm[i]]=u;  //军队在时间限制内的已知距离，无法走出根节点则记为时间 
    dfs(1);  //从根节点开始遍历 
}
void makeaa(int u)
{
    for(int i=1;i<=m;i++)
      if(dis[arm[i]]<u) arre[++na].x=gra[arm[i]],arre[na].v=u-dis[arm[i]];  //记录可用来弥补的距离及其现在位置(根节点直系子节点) 
    sort(arre+1,arre+na+1,cmp);  //从大到小排序 
    for(int i=1;i<=na;i++)
    {
        if(!cal[arre[i].x]) cal[arre[i].x]=i;  //每个子节点军队的最小弥补值的序号 
        else if(arre[cal[arre[i].x]].v>arre[i].v) cal[arre[i].x]=i;
    }
}
void makecc()
{
    for(int i=fi[1];i;i=ne[i])  //所有需要弥补的根节点直系子节点 
      if(ti[w[i]]==-1) coo[++nc].x=w[i],coo[nc].v=v[i];
    sort(coo+1,coo+nc+1,cmp);  //距离从大到小排序 
}
bool ans()
{
    if(na<nc) return 0;  //绝对无法弥补 
    memset(b,0,sizeof(b));
    int i=1,j=1;  //用来弥补的军队，须弥补的距离 
    for(;i<=nc;i++)
      if(!b[cal[coo[i].x]] && cal[coo[i].x]) b[cal[coo[i].x]]=1;  //有军队刚好可以弥补，无需经过根节点 
      else
      {
          while(b[j] && j<=na) j++;
          if(j>na || arre[j].v<coo[i].v) return 0;  //无法弥补 
          b[j]=1;j++;
      }
    return 1;
}
bool pan(int u)
{
    memset(cal,0,sizeof(cal));na=nc=0;
    memset(ti,-1,sizeof(ti));
    maketi(u);
    makeaa(u);
    makecc();
    return ans();
}
int erfen()  //二分答案 
{
    int l=-1,r=999999999;
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(pan(mid)) r=mid;
        else l=mid;
    }
    return r;
}
void getho(int u)
{
    for(int i=fi[u];i;i=ne[i])
      if(ho[u]!=w[i])
      {
          if(u==1) gra[w[i]]=w[i];  //记录该点跳转直系祖先（该祖先为1号节点的子节点） 
          else gra[w[i]]=gra[u];
          ho[w[i]]=u;dis[w[i]]=dis[u]+v[i];  //该点父节点，距根节点距离 
          getho(w[i]);
      }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&val);
        addedge(x,y,val);addedge(y,x,val);
        if(x==1 || y==1) tot++;
    }
    scanf("%d",&m);
    getho(1);
    if(m<tot)
    {
        printf("-1\n");return 0;
    }
    for(int i=1;i<=m;i++) scanf("%d",&arm[i]);  //军队位置 
    sort(arm+1,arm+m+1);  //军队位置由近到远排序 
    printf("%d\n",erfen());
    return 0;
}