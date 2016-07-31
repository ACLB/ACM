#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int m,n;

int w[110];

int mp[110][110];

int pre[110];

int s;

bool vist[110],vis[110];

int dis[110];

int spfa()
{
    memset(dis,INF,sizeof(dis));

    memset(vis,false,sizeof(vis));

    dis[1] = 0;

    vis[1] = true;

    queue<int>Q;

    Q.push(1);

    while(!Q.empty())
    {
        int u = Q.front();

        Q.pop();

        for(int i = 1;i<=n;i++)
        {
            if(vist[pre[i]]  && dis[i] > dis[u] + mp[u][i])
            {
                dis[i] = dis[u] + mp[u][i];

                if(!vis[i])
                {
                    vis[i] = true;

                    Q.push(i);
                }
            }
        }

        vis[u] =false;
    }

    int ans = INF;

    for(int i=1;i<=n;i++)
    {
        ans = min(ans,dis[i] + w[i]);
    }

    return ans;
}

int main()
{
    int l,x,t,v;

    while(~scanf("%d %d",&m,&n))
    {
        memset(mp,INF,sizeof(mp));

        for(int i = 1;i<=n;i++)
        {
            scanf("%d %d %d",&w[i],&l,&x);

            if( i == 1) s = l;

            pre[i] = l;

            for(int j = 1;j<=x;j++)
            {
                scanf("%d %d",&t,&v);

                mp[i][t] = v;
            }
        }

        int ans = INF;

        for(int i = max(1,s-m);i<=min(s+m,n);i++)
        {
            memset(vist,false,sizeof(vist));

            for(int j = i;j<=i+m && j<=min(s+m,n);j++)
            {
                vist[j] = true;
            }

            ans = min(ans,spfa());
        }


        printf("%d\n",ans);
    }
    return 0;
}
