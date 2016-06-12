#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<int>E[20];

int s[20][3];

int bite[20];

LL op[20];

LL Dp[20];

bool vis[20];

void DFS(int u)
{
    vis[u] = true;

    Dp[u] = 0;

    for(int i = 0;i<E[u].size();i++)
    {
        if(!vis[E[u][i]])
        {
            DFS(E[u][i]);
        }

        Dp[u] = max(LL((abs(op[u]- op[E[u][i]])+999)/1000*666*(u+1)),Dp[u]);
    }
}

int main()
{
    int  n;

    int u,v;

    scanf("%d",&n);

    for(int i = 0 ;i<n;i++)
    {
        scanf("%d %d",&s[i][0],&s[i][1]);
    }

    for(int i = 0;i<n-1;i++)
    {
        scanf("%d %d",&u,&v);

        E[u-1].push_back(v-1);
    }
    LL ans;

    for(int i = 0;i<(1<<n);i++)
    {
        int num = 0;

        int b =  i;

        memset(bite,0,sizeof(bite));

        while(b)
        {
            bite[num++] = b%2;

            b/=2;
        }

        for(int j = 0 ;j<n;j++)
        {
            if(bite[j])
            {
                op[j] = s[j][1];
            }
            else op[j] = s[j][0];
        }

        memset(vis,false,sizeof(vis));

        for(int j = 0 ;j<n;j++)
        {
            if(!vis[j])
            {
                DFS(j);
            }
        }

        LL sum = 0;

        for(int j = 0;j<n;j++)
        {

            sum+=(op[j]-Dp[j]);
        }
        if(i == 0)
        {
            ans = sum;
        }
        else ans = max(ans,sum);
    }

    printf("%lld\n",ans);
    return 0;
}
