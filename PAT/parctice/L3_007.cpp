#include <bits/stdc++.h>

using namespace std;

const int Max = 550;

const int INF = 0x3f3f3f3f;

struct node
{
    int v,d,t;

    node(){}

    node(int _v,int _d,int _t):v(_v),d(_d),t(_t){}
};

vector<node>E[Max];

int n,m;

int s,t;

bool vis[Max];

int Dis[Max][2],Ti[Max][2];

int PreD[Max],PreT[Max];

int ansD[Max],ansT[Max];

void SPFAT()
{
    memset(vis,false,sizeof(vis));

    memset(Ti,INF,sizeof(Ti));

    for(int i =0;i<=n;i++) PreT[i] = -1;

    queue<int>Q;

    Q.push(s); Ti[s][0] = Ti[s][1] = 0;

    vis[s] = true;

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        for(int i = 0;i < E[u].size() ;i++)
        {
            int v = E[u][i].v;

            if((Ti[v][0] > Ti[u][0] + E[u][i].t) || (Ti[v][0] == Ti[u][0] + E[u][i].t && Ti[v][1] > Ti[u][1] + E[u][i].d))
            {
                PreT[v] = u;

                Ti[v][0] = Ti[u][0] + E[u][i].t;

                Ti[v][1] = Ti[u][1] +E[u][i].d;

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

void SPFAD()
{
    memset(vis,false,sizeof(vis));

    memset(Dis,INF,sizeof(Dis));

    for(int i =0;i<=n;i++) PreD[i] = -1;

    queue<int>Q;

    Q.push(s); Dis[s][0] = Dis[s][1] = 0;

    vis[s] = true;

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        for(int i = 0;i<E[u].size();i++)
        {
            int v = E[u][i].v;

            if((Dis[v][0] > Dis[u][0] + E[u][i].d) || (Dis[v][0] == Dis[u][0] + E[u][i].d && Dis[v][1] > Dis[u][1] + 1))
            {
                PreD[v] = u;

                Dis[v][0] = Dis[u][0] + E[u][i].d;

                Dis[v][1] = Dis[u][1] +1;

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
    int u,v,d,t,op;

    scanf("%d %d",&n,&m);

    for(int i = 0 ;i < m; i++)
    {
        scanf("%d %d %d %d %d",&u,&v,&op,&d,&t);

        E[u].push_back(node(v,d,t));

        if(!op) E[v].push_back(node(u,d,t));
    }

    scanf("%d %d",&s,&t);

    SPFAT(); SPFAD();

    ansT[0] = ansD[0] = 0;

    int sa = t;

    while(sa != -1)
    {
        ansT[++ansT[0]] = sa;

        sa = PreT[sa];
    }

    sa = t;

    while(sa != -1)
    {
        ansD[++ansD[0]] =sa;

        sa = PreD[sa];
    }

    bool flag = false;

    if(ansT[0] != ansD[0])
    {
        flag = true;
    }
    else
    {
        for(int i = 1;i<=ansT[0];i++)
        {
            if(ansD[i]!=ansT[i])
            {
                flag = true;

                break;
            }
        }
    }

    if(flag)
    {
        printf("Time = %d: ",Ti[t][0]);

        for(int i = ansT[0];i>=1;i--)
        {
            if(i != ansT[0]) printf(" => ");
            printf("%d",ansT[i]);
        }
        printf("\n");

        printf("Distance = %d: ",Dis[t][0]);

        for(int i = ansD[0];i>=1;i--)
        {
            if(i !=  ansD[0]) printf(" => ");
            printf("%d",ansD[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Time = %d; Distance = %d: ",Ti[t][0],Dis[t][0]);

        for(int i = ansD[0];i>=1;i--)
        {
            if(i !=  ansD[0]) printf(" => ");
            printf("%d",ansD[i]);
        }
        printf("\n");

    }
    return 0;
}
