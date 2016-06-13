#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

vector<int>E[90100];

int n,m,p,t;

int M[310][310];

int Dis[90010];

bool vis[90010];

void SPFA()
{
    memset(vis,false,sizeof(vis));

    memset(Dis,INF,sizeof(Dis));

    queue<int>Q;
    
    for(int i = 0;i<E[1].size();i++)
    {
        vis[E[1][i]] = true;

        Dis[E[1][i]] = E[1][i]/m+E[1][i]%m;

        Q.push(E[1][i]);
    }

    int x,y,Fx,Fy;

    while(!Q.empty())
    {
        int u = Q.front();  Q.pop();

        x = u/m, y = u%m;

        int op = M[x][y]+1;

        for(int i = 0;i<E[op].size();i++)
        {
            int s = E[op][i];

            Fx = s/m, Fy = s%m;

            if(Dis[s]>(abs(x-Fx)+abs(y-Fy))+Dis[u])
            {
                Dis[s] = (abs(x-Fx)+abs(y-Fy))+Dis[u];

                if(!vis[s])
                {
                    vis[s] = true;

                    Q.push(s);
                }
            }
        }

        vis[u] = false;
    }
}

int main()
{
    scanf("%d %d %d",&n,&m,&p);

    for(int i = 0;i < n ;i++)
    {
        for(int j = 0;j < m; j++)
        {
            scanf("%d",&M[i][j]);

            E[M[i][j]].push_back(i*m+j);
        }
    }

    SPFA();

    int ans;

    for(int i = 0;i<E[p].size();i++)
    {
        if(i) ans = min(ans,Dis[E[p][i]]);
        else ans = Dis[E[p][i]];
    }

    printf("%d\n",ans);

    return 0;
}
