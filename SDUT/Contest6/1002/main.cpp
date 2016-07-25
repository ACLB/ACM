#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

struct node
{
    int u,v,w;

    node() {}

    node(int _u,int _v,int _w):u(_u),v(_v),w(_w) {}

} edge[6666];

int n,m,w,num;

int dis[666];

bool bellmanford()
{
    memset(dis,INF,sizeof(INF));

    dis[1] = 0;

    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<num; j++)
        {
            if(dis[edge[j].v] > dis[edge[j].u] + edge[j].w)
            {
                dis[edge[j].v] = dis[edge[j].u] + edge[j].w;
            }
        }
    }

    for(int j = 0; j<num; j++)
    {
        if(dis[edge[j].v] > dis[edge[j].u] + edge[j].w)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int T;

    scanf("%d",&T);

    int u,v,W;

    while(T--)
    {
        scanf("%d %d %d",&n,&m,&w);

        num = 0;

        for(int i= 1; i<=m; i++)
        {
            scanf("%d %d %d",&u,&v,&W);

            edge[num++] = node(u,v,W);

            edge[num++] = node(v,u,W);
        }

        for(int i = 1; i<=w; i++)
        {
            scanf("%d %d %d",&u,&v,&W);

            edge[num++] = node(u,v,-W);
        }

        if(bellmanford())
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
