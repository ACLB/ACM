#include <bits/stdc++.h>

using namespace std;

const int  INF = 0x3f3f3f3f;

typedef struct node
{
    int v,w,f;

    node(){}

    node(int _v,int _w,int _f):v(_v),w(_w),f(_f){}
}Node;

vector<Node>E[550];

int Dis[550][2];

bool vis[550];

int n,m,s,t;

void SPFA()
{
    memset(Dis,INF,sizeof(Dis));

    memset(vis,false,sizeof(vis));

    vis[s] = true;

    Dis[s][0] = Dis[s][1] = 0;

    queue<int>Q;

    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        for(int i = 0;i<E[u].size();i++)
        {
            int v = E[u][i].v;

            if(Dis[v][0]>Dis[u][0] + E[u][i].w || (Dis[v][0] == Dis[u][0] + E[u][i].w && Dis[v][1] > Dis[u][1]+E[u][i].f))
            {
                Dis[v][0] = Dis[u][0] +E[u][i].w;

                Dis[v][1] = Dis[u][1] +E[u][i].f;

                if(!vis[v])
                {
                    vis[v] = true;

                    Q.push(v);
                }
            }
        }

        vis[u] = false;
    }
}

int main()
{
    scanf("%d %d %d %d",&n,&m,&s,&t);

    int u,v,w,f;

    for(int i = 0 ;i<m;i++)
    {
        scanf("%d %d %d %d",&u,&v,&w,&f);

        E[u].push_back(Node(v,w,f));

        E[v].push_back(Node(u,w,f));
    }

    SPFA();

    printf("%d %d\n",Dis[t][0],Dis[t][1]);
    return 0;
}
