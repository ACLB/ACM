#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;

typedef struct node
{
    int v,next;

    int flow;

    node(){}

    node(int _v,int _next,LL _flow):v(_v),next(_next),flow(_flow){}

}No;


int a[15],b[15];

int w[110][110];

int n,num[110];

int s,t;

char str[110];

int Head[11000],top;

No E[111000];

int Sy[11000];

void AddEdge(int u,int v,LL flow)
{
    E[top] = node(v,Head[u],flow);

    Head[u] = top++;

    E[top] = node(u,Head[v],0);

    Head[v] = top++;
}


bool bfs()
{
    memset(Sy,0,sizeof(Sy));

    queue<int>Q;

    Sy[s] = 1;

    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        for(int i = Head[u];i !=-1;i = E[i].next)
        {
            int v = E[i].v;

            if(!Sy[v] && E[i].flow>0)
            {
                Sy[v] = Sy[u]+1;

                Q.push(v);
            }
        }
    }

    return Sy[t] !=0;
}

int dfs(int u,int Flow)
{
    if(u == t || Flow ==0) return Flow;

    int f = 0;

    for(int  i = Head[u]; i != -1 ; i = E[i].next)
    {
        int v = E[i].v;

        if(Sy[v] == Sy[u]+1)
        {
            int ans = dfs(v,min(Flow,E[i].flow));

            f+=ans;

            Flow-=ans;

            E[i].flow-=ans;

            E[i^1].flow+=ans;

            if(Flow ==0)
                break;
        }
    }

    return f;
}

int Dinic()
{
    int ans = 0;

    while(bfs())
    {
        ans+=dfs(s,INF);
    }

    return ans;
}

int  Solve()
{
    s = 0; top = 0;

    int End = n+10;

    int sum = 0;

    memset(Head,-1,sizeof(Head));

    for(int i = 1;i<=n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            End++;

            AddEdge(s,End,w[i][j]+w[j][i]);

            AddEdge(End,i,INF);

            AddEdge(End,j,INF);

            sum+=(w[i][j] + w[j][i]);
        }
    }

    t = ++End;

    for(int i =1;i<=n;i++)
    {
        AddEdge(i,num[i]+n+1,INF);

        AddEdge(i,t,a[num[i]+1]);
    }

    for(int i = 1;i<=10;i++)
    {
        AddEdge(i+n,t,b[i]-a[i]);
    }

    return sum-Dinic();
}
int main()
{
    int T;

   // freopen("1009.in","r",stdin);

    scanf("%d",&T);

    for(int z = 1;z<=T;z++)
    {
        scanf("%d",&n);

        if(n != 0)
            scanf("%s",str);

        for(int i = 1;i<=10;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                scanf("%d",&w[i][j]);
            }
        }

        for(int i = 1;i<=n;i++)
            num[i] = str[i-1]-'0';

        if(n == 0) printf("Case #%d: 0\n",z);
        else printf("Case #%d: %d\n",z,Solve());
    }
    return 0;
}
