#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int g[110][110];

bool vis[110];

int pos[110];

int n,m,na,np;

int s,t;

bool bfs(int s)
{
    memset(vis,false,sizeof(vis));

    memset(pos,0,sizeof(pos));

    vis[s] = true;

    pos[s] = 1;

    queue<int>Q;

    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        for(int i = 0;i<=n;i++)
        {
            if(!vis[i] && g[u][i])
            {
                pos[i] = pos[u]+1;

                vis[i] = true;

                Q.push(i);
            }
        }
    }

    return pos[t]!=0;
}

int dfs(int St,int Flow)
{
    if(St == t || Flow == 0)
    {
        return Flow;
    }

    int st = 0;

    for(int i  = 0;i<=n;i++)
    {
        if(pos[St] +1 == pos[i])
        {
            int ss = dfs(i,min(Flow,g[St][i]));


            st+=ss;

            g[St][i]-=ss;

            g[i][St]+=ss;

            Flow-=ss;

            if(Flow == 0) break;
        }
    }

    return st;
}

int Dinic()
{
    int ans = 0;

    while(bfs(s))
    {
        ans += dfs(s,INF);
    }

    return ans;
}

int main()
{
    int u,v,w;
    while(~scanf("%d %d %d %d",&n,&na,&np,&m))
    {

        memset(g,0,sizeof(g));

        for(int i = 0;i<m;i++)
        {
            scanf(" (%d,%d)%d",&u,&v,&w);

            g[u+1][v+1] = w;
        }

        for(int i = 0;i<na;i++)
        {
            scanf(" (%d)%d",&u,&w);

            g[0][u+1] = w;
        }

        for(int i = 0;i<np;i++)
        {
            scanf(" (%d)%d",&u,&w);

            g[u+1][n+1] = w;
        }

        n++;

        s = 0; t = n;

        printf("%d\n",Dinic());
    }
    return 0;
}
