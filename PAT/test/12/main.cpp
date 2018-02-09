#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>PII;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;

const int N=5e2+10;

int ma[N][N];
LL ways[N];
int ww[N],pre[N],ans[N],num;
PII dis[N];
bool vis[N];
int n,m,s,t;

queue<int>q;
void SPFA()
{
    for(int i=0;i<n;i++)
    {
        ways[i]=0;
        vis[i]=0;
        dis[i].second=0;
        dis[i].first=INF;
    }
    pre[s]=-1;
    dis[s].first=0;
    dis[s].second=ww[s];
    vis[s]=1;
    ways[s]=1;

    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=0;i<n;i++)
        {
            if(ma[u][i]!=INF&&i!=u)
            {
                if(dis[i].first>dis[u].first+ma[u][i])
                {
                    pre[i]=u;
                    ways[i]=ways[u];
                    dis[i].first=dis[u].first+ma[u][i];
                    dis[i].second=dis[u].second+ww[i];
                    if(!vis[i])
                    {
                        q.push(i);
                        vis[i]=1;
                    }
                }
                else if(dis[i].first==dis[u].first+ma[u][i])
                {
                    if(dis[i].second<dis[u].second+ww[i])
                    {
                        ways[i]+=ways[u];
                        pre[i]=u;
                        dis[i].second=dis[u].second+ww[i];
                        if(!vis[i])
                        {
                            q.push(i);
                            vis[i]=1;
                        }
                    }
                }
            }
        }
    }
//    printf("%d\n",dis[t].first);
    printf("%lld %d\n",ways[t],dis[t].second);
    int v=t;
    num=0;
    while(pre[v]!=-1)
    {
        ans[num++]=v;
        v=pre[v];
    }
    ans[num++]=s;
    printf("%d",ans[num-1]);
    for(int i=num-2;i>=0;i--)
        printf(" %d",ans[i]);
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&ww[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) ma[i][i]=0;
            else ma[i][j]=ma[j][i]=INF;
        }
    int u,v,w;
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&w);
        ma[u][v]=min(ma[u][v],w);
        ma[v][u]=ma[u][v];
    }
    SPFA();
    return 0;
}

