#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n,m,s,t;

map<string,int>SI;

vector<pair<int,int> >E[300];

int num;

int sum[300];

int pre[300];

int dis[300][4];

bool vis[300];

char ss[300][4];

int GetIndex(char *S)
{
    if(!SI[S])
    {
        SI[S] = ++num;

        strcpy(ss[num],S);
    }

    return SI[S];
}

void spfa()
{
    for(int i = 1; i<=num; i++)
    {
        dis[i][0] = INF;

        dis[i][1] = dis[i][2] = dis[i][3] = 0;

        pre[i] = -1;

        vis[i] = false;
    }

    dis[s][0] = 0;

    dis[s][1] = 1;

    dis[s][2] = 0;

    dis[s][3] = 1;

    vis[s] = true;

    queue<int>Q;

    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front();

        Q.pop();

        for(int i= 0 ; i<E[u].size(); i++)
        {
            int v = E[u][i].first;

            int w = E[u][i].second;

            if(dis[v][0] == dis[u][0] + w)
            {
                dis[v][3] += dis[u][3];
            }

            if(dis[v][0] > dis[u][0] + w)
            {
                dis[v][0] = dis[u][0] + w;

                dis[v][1] = dis[u][1] +1;

                dis[v][2] = dis[u][2] + sum[v];

                dis[v][3] = dis[u][3];

                pre[v] = u;

                if(!vis[v])
                {
                    vis[v] = true;

                    Q.push(v);
                }
            }
            else if(dis[v][0] == dis[u][0] + w && dis[v][1] < dis[u][1] +1)
            {
                dis[v][1] = dis[u][1] +1;

                dis[v][2] = dis[u][2] + sum[v];

                pre[v] = u;

                if(!vis[v])
                {
                    vis[v] = true;

                    Q.push(v);
                }
            }
            else if(dis[v][0] == dis[u][0] + w && dis[v][1] == dis[u][1] +1 && dis[v][2] < dis[u][2]+sum[v])
            {
                dis[v][2] = dis[u][2] + sum[v];

                pre[v] = u;

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

char u[5],v[5];

int main()
{
    int w;

    num = 0;

    scanf("%d %d %s %s",&n,&m,u,v);

    s = GetIndex(u);

    t = GetIndex(v);

    for(int i = 0; i<n-1; i++)
    {
        scanf("%s",u);

        int st = GetIndex(u);

        scanf("%d",&sum[st]);
    }

    for(int i  = 0 ; i<m; i++)
    {
        scanf("%s %s %d",u,v,&w);

        int U = GetIndex(u);

        int V = GetIndex(v);

        E[U].push_back(make_pair(V,w));

        E[V].push_back(make_pair(U,w));
    }

    spfa();

    int tt = t;

    stack<int>S;

    while(tt!=-1)
    {
        S.push(tt);

        tt = pre[tt];
    }

    bool flag = false;

    while(!S.empty())
    {
        if(flag) printf("->");
        else flag  = true;

        printf("%s",ss[S.top()]);

        S.pop();
    }

    printf("\n%d %d %d\n",dis[t][3],dis[t][0],dis[t][2]);
    return 0;
}
