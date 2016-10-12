#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

int n;

int arr[110][110];

int dis[110];

bool vis[110];

int SPFA(int s)
{
    memset(vis,false,sizeof(vis));

    memset(dis,INF,sizeof(dis));

    dis[s] = 0;

    vis[s] = true;

    queue<int>Q;

    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        for(int i =1;i<=n;i++)
        {
            if(dis[i]>dis[u]+arr[u][i])
            {
                dis[i] = dis[u] + arr[u][i];

                if(!vis[i])
                {
                    vis[i] = true;

                    Q.push(i);
                }
            }
        }

        vis[u] =false;
    }

    int Mi = 0;

    for(int i = 1;i<=n;i++)
    {
        Mi = max(Mi,dis[i]);
    }

    return Mi;
}

int main()
{
    int m,u,v;

    while(~scanf("%d",&n)&&n)
    {
        memset(arr,INF,sizeof(arr));

        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&m);

            for(int j = 0;j<m;j++)
            {
                scanf("%d %d",&u,&v);

                arr[i][u] = v;
            }
        }
        int Mi = INF,flag;

        for(int i = 1;i<=n;i++)
        {
            int ans = SPFA(i);

            if(Mi > ans)
            {
                Mi = ans;

                flag = i;
            }
        }

        if(Mi == INF) printf("disjoint\n");

        else printf("%d %d\n",flag,Mi);
    }

    return 0;
}
