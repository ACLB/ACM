
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n,m;

vector<pair<int,int> >E[1100];

int Dis[1100];

bool vis[1100];

int ans;

bool Op()
{
    memset(vis,false,sizeof(vis));

    for(int i = 1;i<=n;i++) Dis[i] =INF;

    vis[1] = true;

    for(int i = 0;i<E[1].size();i++)
    {
        Dis[E[1][i].first] = E[1][i].second;
    }

    for(int i = 1;i<n;i++)
    {
        int Mi = -1, D = INF;

        for(int j = 1;j<=n;j++)
        {
            if(!vis[j] && D>Dis[j])
            {
                Mi  = j;

                D = Dis[j];
            }
        }

        if(Mi == -1)
        {
            return false;
        }
        ans += D;

        vis[Mi] = true;

        for(int j = 0;j<E[Mi].size();j++)
        {
            Dis[E[Mi][j].first] = min(Dis[E[Mi][j].first],E[Mi][j].second);
        }
    }

    return true;
}

int main()
{
    cin>>n>>m;

    int u,v,w;
    for(int i = 0;i<m;i++)
    {
        cin>>u>>v>>w;

        E[u].push_back(make_pair(v,w));

        E[v].push_back(make_pair(u,w));
    }

    ans  = 0;

    if(!Op()) cout<<-1<<endl;
    else cout <<ans<<endl;
    return 0;
}
