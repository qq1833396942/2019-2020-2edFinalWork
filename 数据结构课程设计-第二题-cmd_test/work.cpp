#include <cstdio>
#include <cstring>
long long value[100001],last[100001],to[100001],bz[100001],jd[100001],h[100001],d[100001];
long long g[100001][21],f[100001][21];
struct node{ long long v,w; } b[100001],c[100001];
long long len=0,n=0,m=0,l=0,r=0;
void ins(long long x,long long y,long long c)
{
    len++;
    to[len]=y;
    value[len]=c;
    last[len]=h[x];
    h[x]=len;
}


void dfs(long long x,long long y)
{
    for(long long i=h[x];i>0;i=last[i])
    {
        if(y!=to[i])
        {
            d[to[i]]=d[x]+1;
            g[to[i]][0]=x;
            f[to[i]][0]=value[i];
            dfs(to[i],x);
        }
    }
}


void color(long long x)
{
    long long a=1,b=0;
    for(long long i=h[x];i>0;i=last[i])
    {
        if(to[i]!=g[x][0])
        {
            color(to[i]);
            a=a&bz[to[i]];
            b=1;
        }
    }
    if(a==1 && b==1 && x!=1)
    {
        bz[x]=1;
    }
}


void px1(long long l,long long r)
{
    long long x=l,y=r,mid=b[(l+r)/2].v;
    while(x<=y)
    {
        while(b[x].v<mid)
        {
            x++;
        }
        while(b[y].v>mid)
        {
            y--;
        }
        if(x<=y)
        {
            node dq=b[x];
            b[x]=b[y];
            b[y]=dq;
            x++;
            y--;
        }
    }
    if(l<y)
    {
        px1(l,y);
    }
    if(x<r)
    {
        px1(x,r);
    }
}


void px2(long long l,long long r)
{
    long long x=l,y=r,mid=c[(l+r)/2].v;
    while(x<=y)
    {
        while(c[x].v<mid)
        {
            x++;
        }
        while(c[y].v>mid)
        {
            y--;
        }
        if(x<=y)
        {
            node dq=c[x];
            c[x]=c[y];
            c[y]=dq;
            x++;
            y--;
        }
    }
    if(l<y)
    {
        px2(l,y);
    }
    if(x<r)
    {
        px2(x,r);
    }
}


bool check(long long ti)
{
    memset(bz,0,sizeof(bz));
    long long tot=0,top=0;
    for(long long i=1;i<=m;i++)
    {
        long long y=jd[i],z=0;
        for(long long j=20;j>=0;j--)
        {
            if(g[y][j]!=0 && z+f[y][j]<=ti)
            {
                z+=f[y][j];
                y=g[y][j];
            }
        }
        if(y!=1)
        {
            bz[y]=1;
        }
        else
        {
            tot++;
            b[tot].v=ti-z;
            y=jd[i];
            for(long long j=20;j>=0;j--)
            {
                if(g[y][j]>1)
                {
                    y=g[y][j];
                }
            }
            b[tot].w=y;
        }
    }
    color(1);
    for(long long i=h[1];i>0;i=last[i])
    {
        if(bz[to[i]]==0)
        {
            top++;
            c[top].v=value[i];
            c[top].w=to[i];
        }
    }
    px1(1,tot);
    px2(1,top);
    long long j=1;
    c[top+1].v=2147483647;
    for(long long i=1;i<=tot;i++)
    {
        if(bz[b[i].w]==false)
        {
            bz[b[i].w]=true;
        }
        else if(b[i].v>=c[j].v)
        {
            bz[c[j].w]=true;
        }
        while(bz[c[j].w]==true)
        {
            j++;
        }
    }
    if(j>top)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    scanf("%lld",&n);
    for(long long i=1;i<=n-1;i++)
    {
        long long x=0,y=0,c=0;
        scanf("%lld %lld %lld",&x,&y,&c);
        ins(x,y,c),ins(y,x,c);
        r+=c;
    }
    scanf("%lld",&m);
    for(long long i=1;i<=m;i++)
    {
        scanf("%lld",&jd[i]);
    }
    d[1]=1;
    dfs(1,0);
    for(long long j=1;j<=20;j++)
    {
        for(long long i=1;i<=n;i++)
        {
            g[i][j]=g[g[i][j-1]][j-1];
            f[i][j]=f[g[i][j-1]][j-1]+f[i][j-1];
        }
    }
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(check(mid)==false)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    if(check(l)==true)
    {
        printf("%lld",l);
    }
    else
    {
        printf("-1");
    }
    return 0;
}