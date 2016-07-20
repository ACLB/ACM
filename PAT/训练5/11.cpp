#include <bits/stdc++.h>

using namespace std;

int n,m;

int u,v;

vector<int>E[11000];

int num;

bool vis[11000];

void bfs(int u)
{
    queue<pair<int,int> >Q;

    Q.push(make_pair(u,0));

    memset(vis,false,sizeof(vis));

    vis[u] = true;

    while(!Q.empty())
    {
        pair<int,int> u = Q.front(); Q.pop();

        num+=u.second;

        for(int i = 0;i<E[u.first].size();i++)
        {
            int v = E[u.first][i];

            if(!vis[v])
            {
                vis[v] = true;

                Q.push(make_pair(v,u.second+1));
            }
        }
    }

}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i = 0 ;i<m;i++)
    {
        scanf("%d %d",&u,&v);

        E[u].push_back(v);

        E[v].push_back(u);
    }

    int k;

    bfs(1);

    bool flag = false;

    for(int i = 1;i<=n;i++)
    {
        if(!vis[i])
        {
            flag = true;

            break;
        }
    }

    scanf("%d",&k);

    while(k--)
    {
        scanf("%d",&u);

        if(flag)
        {

            printf("Cc(%d)=0.00\n",u);

            continue;
        }

        num = 0;
        bfs(u);

        printf("Cc(%d)=%.2f\n",u,(n-1)*1.0/num);
    }
    return 0;
}
