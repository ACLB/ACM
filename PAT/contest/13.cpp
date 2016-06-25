#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int n,m;

int mp[1100][1100];

bool vis[1100];

int Dis[1100];

int main()
{
    int n,m;

    memset(mp,INF,sizeof(mp));

    scanf("%d %d",&n,&m);

    int u,v,w;

    for(int i = 0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        mp[u][v] = mp[v][u] = min(mp[u][v],w);
    }

    int sum = 0;

    for(int i = 1;i<=n;i++)
    {
        Dis[i] = mp[1][i];
    }

    bool Ju = false;

    memset(vis,false,sizeof(vis));

    vis[1] = true;

    for(int i = 0;i<n-1;i++)
    {
        int Mi = INF,flag ;

        for(int j =1;j<=n;j++)
        {
            if(!vis[j] && Dis[j] < Mi)
            {
                Mi = Dis[j];

                flag = j;
            }
        }

        if(Mi == INF)
        {
            Ju = true;

            break;
        }
        sum+=Mi;

        vis[flag] = true;

        for(int j = 1;j<=n;j++)
        {
            if(!vis[j] && mp[flag][j] < Dis[j])
            {
                Dis[j] = mp[flag][j];
            }
        }
    }

    if(Ju)
    {
        printf("Impossible\n");
    }
    else printf("%d\n",sum);


    return 0;
}
