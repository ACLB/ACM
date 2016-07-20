#include <bits/stdc++.h>

using namespace std;

set<int>E[15];

queue<int>Q;

bool vis[15];

int n,m;

void dfs(int u)
{
    vis[u] = true;

    Q.push(u);

    for(set<int>::iterator it = E[u].begin();it != E[u].end();it++)
    {
        if(!vis[*it])
        {
            dfs(*it);
        }
    }
}

void bfs(int u)
{
    queue<int>QI;

    QI.push(u);

    vis[u] = true;

    while(!QI.empty())
    {
        int u = QI.front();

        Q.push(u);

        QI.pop();

        for(set<int>::iterator it = E[u].begin();it != E[u].end();it++)
        {
            if(!vis[*it])
            {
                vis[*it] = true;

                QI.push(*it);
            }
        }


    }
}

int main()
{
    int u,v;

    cin>>n>>m;

    for(int i = 0;i<m;i++)
    {
        cin>>u>>v;

        E[u].insert(v);

        E[v].insert(u);
    }

    memset(vis,false,sizeof(vis));

    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);


            cout<<"{";
            while(!Q.empty())
            {
                cout<<" "<<Q.front();

                Q.pop();
            }

            cout<<" }"<<endl;
        }
    }

    memset(vis,false,sizeof(vis));

    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            bfs(i);
            cout<<"{";
            while(!Q.empty())
            {
                cout<<" "<<Q.front();

                Q.pop();
            }

            cout<<" }"<<endl;
        }
    }
    return 0;
}

