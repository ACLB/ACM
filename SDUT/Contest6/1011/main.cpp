#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int n,m;

int pre[110];

int mp[110][110],dis[110];

bool vis[110];

bool vist[110];

int s ;

int W[110];

int spfa()
{
    memset(dis,INF,sizeof(dis));

    memset(vist,false,sizeof(vist));

    vis[1] = true; dis[1] = 0;

    queue<int>Q; Q.push(1);

    while(!Q.empty())
    {
        int u = Q.front();Q.pop();

        for(int i = 1;i<=n;i++)
        {
            if(vis[pre[i]] && dis[i]> dis[u] + mp[u][i])
            {
                dis[i] = dis[u] + mp[u][i];

                if(!vist[i])
                {
                    vist[i] = true;

                    Q.push(i);
                }
            }
        }

        vist[u] = false;
    }

    int ans = INF;

    for(int i = 1;i<=n;i++)
    {
        printf("%d %d\n",i,dis[i]);

        ans = min(ans,dis[i]+W[i]);
    }

    printf("----------------------------\n");
    return ans;
}

int main()
{
    while(~scanf("%d %d",&m,&n))
    {
        int p,l,k,w,t;

        memset(mp,INF,sizeof(mp));

        for(int i = 1;i<=n;i++)
        {
            scanf("%d %d %d",&p,&l,&k);

            if(i == 1) s = l;

            pre[i] = l;

            W[i] = p;

            for(int j = 0;j<k;j++)
            {
                scanf("%d %d",&t,&w);

                mp[i][t] = p - w;
            }
        }

        int ans = INF;


        for(int i = min(1,s-m);i<=s+m;i++)
        {
            memset(vis,false,sizeof(vis));

            for(int j = 1;j<=m;j++)
            {
                vis[i+j] =true;
            }

            ans = min(ans,spfa());
        }
        printf("%d\n",ans);
    }
    return 0;
}
