#include <bits/stdc++.h>

using namespace std;

const int Max = 1e5+100;

struct node
{
    int v,next,cost;

}E[Max*2];

int h[Max],top;

int w[Max];

int dp[Max][2],to[Max];

int ans[Max];

void add(int u,int v,int cost)
{
    E[top].v = v; E[top].cost = cost;

    E[top].next = h[u]; h[u] = top++;
}

void dfs1(int u,int fa)
{
    dp[u][0] = dp[u][1] = w[u];

    to[u] = 0;

    for(int i = h[u];~i;i = E[i].next)
    {
        int v = E[i].v;

        if(v == fa)continue;

        dfs1(v,u);

        int ans1 =max(0,dp[v][0]-2*E[i].cost);

        int temp = max(0,dp[u][0]+dp[v][1]-E[i].cost);

        dp[u][1]+=ans1;

        if(dp[u][1]<temp)
        {
            dp[u][1] = temp;

            to[u] = v;
        }

        dp[u][0]+=ans1;
    }
}

void dfs2(int u,int fa,int M0,int M1)
{
    ans[u] = max(dp[u][0] + M1,dp[u][1] + M0);

    int W0=  dp[u][0];

    int W1 = dp[u][1];

    int id = to[u];

    W1 += M0;

    if(W1<W0+M1)
    {
        W1 = W0+M1;

        id = fa;
    }

    W0 += M0;

    for(int i = h[u]; ~i;i = E[i].next)
    {
        int v = E[i].v;

        if(v == fa)continue;

        if(v == id)
        {
            int ans0 = M0+w[u];

            int ans1 = M1+w[u];

            for(int j = h[u];~j; j = E[j].next)
            {
                int tv = E[j].v;

                if(tv == fa || tv == id) continue;

                int temp = max(0,dp[tv][0]-2*E[j].cost);

                ans1 = max(ans0+max(0,dp[tv][1]-E[j].cost),ans1+temp);

                ans0+=temp;
            }

            ans0 = max(0,ans0-2*E[i].cost);

            ans1 = max(0,ans1-E[i].cost);

            dfs2(v,u,ans0,ans1);
        }
        else
        {
            int temp = max(0,dp[v][0] - 2*E[i].cost);

            int ans0 = max(0,W0-temp-2*E[i].cost);

            int ans1 = max(0,W1-temp-E[i].cost);

            dfs2(v,u,ans0,ans1);
        }
    }
}

int main()
{
    int T,n,u,v,W,z = 1;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        memset(h,-1,sizeof(h));top =0;

        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&w[i]);
        }
        for(int i =1 ;i<=n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&W);
            add(u,v,W);
            add(v,u,W);
        }

        dfs1(1,-1);

        dfs2(1,-1,0,0);

        printf("Case #%d:\n",z++);

        for(int i = 1;i<=n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
