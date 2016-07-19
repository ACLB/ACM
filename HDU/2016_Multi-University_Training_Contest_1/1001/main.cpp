#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 110000;

const int MaxM = 1100000;

typedef struct node
{
    int v,w,next;

}Node;

Node E[MaxM];

int Head[MaxN],top;

typedef struct OO
{
    int u,v,w;

    bool operator < (const OO &a)const
    {
        return w<a.w;
    }

}Map;

Map mp[MaxM];

int pre[MaxN];

LL n,m;

double  sum;

LL Dp[MaxN][2];

bool vis[MaxN];

void Creat(int u,int v,int w)
{
    E[top].v = v;E[top].w = w;

    E[top].next = Head[u];

    Head[u] = top++;
}

int Find(int x)
{
    return pre[x] == 0?x:pre[x] = Find(pre[x]);
}

void Union(int x,int y)
{
    int Fx  = Find(x);

    int Fy = Find(y);

    if(Fx != Fy)
    {
        pre[Fx] = Fy;
    }
}

void dfs(int u)
{
    vis[u] = true;

    Dp[u][0] = 0;

    Dp[u][1] = 1;

    for(int i = Head[u]; i!=-1;i = E[i].next)
    {
        int v = E[i].v;

        int w = E[i].w;

        if(!vis[v])
        {
            dfs(v);

            sum  += ((Dp[u][0]*Dp[v][1])+(Dp[u][1] * (Dp[v][0]+w*Dp[v][1])));

            Dp[u][0] +=(Dp[v][0]+Dp[v][1]*w);

            Dp[u][1] += Dp[v][1];

        }
    }
}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%lld %lld",&n,&m);

        for(int i = 0;i<m;i++)
        {
            scanf("%d %d %d",&mp[i].u,&mp[i].v,&mp[i].w);
        }

        sort(mp,mp+m);

        memset(pre,0,sizeof(pre));

        memset(Head,-1,sizeof(Head));top = 0;

        LL ans = 0;

        int num = 0;

        for(int i = 0;i<m;i++)
        {
            if(Find(mp[i].u) != Find(mp[i].v))
            {
                ans += mp[i].w;

                num++;

                Union(mp[i].u,mp[i].v);

                Creat(mp[i].u,mp[i].v,mp[i].w);

                Creat(mp[i].v,mp[i].u,mp[i].w);
            }

            if(num == n-1) break;
        }

        sum = 0;

        memset(vis,false,sizeof(vis));

        dfs(1);

        printf("%lld %.2f\n",ans,sum/(n*(n-1)/2));
    }
    return 0;
}
