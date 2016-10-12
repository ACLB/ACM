#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

const int Max = 1100;

typedef struct node
{
    int v,w,next;

    node(){}

    node(int _v,int _w,int _next):v(_v),w(_w),next(_next){}
}Edge;

int r[25];

int num[25];

int n;

Edge E[Max];

int h[30],top;

void Build(int u,int v,int w)
{
    E[top] = node(v,w,h[u]);

    h[u] = top++;
}

int dis[30];

bool vis[30];

int du[30];

bool spfa(int Num)
{

    for(int i =0;i<=24;i++)
    {
        dis[i] = -INF;

        vis[i] = false;

        du[i] = 0;
    }

    queue<int>Q;

    Q.push(0);

    vis[0] = true, dis[0] = 0;

    du[0] = 1;

    while(!Q.empty())
    {
        int u = Q.front();

        Q.pop();

        if(du[u]>24) return false;

        for(int i = h[u] ; ~i ;i = E[i].next)
        {
            int v = E[i].v;

            if(dis[v] < dis[u] + E[i].w)
            {
                dis[v] = dis[u] +E[i].w;

                if(!vis[v])
                {
                    du[v] ++;

                    Q.push(v);

                    vis[v] = true;
                }
            }
        }

        vis[u]  =false;
    }
    return dis[24] == Num;
}

bool Judge(int Num)
{
    memset(h,-1,sizeof(h)); top = 0;

    for(int i = 1;i<=24;i++)
    {
        Build(i-1,i,0);

        Build(i,i-1,-num[i]);
    }

    for(int i = 1;i<=8;i++)
    {
        Build(i+16,i,r[i]-Num);
    }

    for(int i = 9;i<=24;i++)
    {
        Build(i-8,i,r[i]);
    }

    Build(0,24,Num);

    return spfa(Num);
}

int Search(int L,int R)
{
    int ans = -1;

    while(L<=R)
    {
        int mid = (L+R)>>1;

        if(Judge(mid))
        {
            ans = mid;

            R = mid-1;
        }
        else L = mid+1;
    }

    return ans;
}

int main()
{
    int T,x;

    scanf("%d",&T);

    while(T--)
    {
        for(int i  = 1;i<=24;i++)
        {
            scanf("%d",&r[i]);
        }

        scanf("%d",&n);

        memset(num,0,sizeof(num));

        for(int i = 0;i<n;i++)
        {
           scanf("%d",&x);

           num[x+1]++;
        }

        int ans = Search(0,n);

        if(ans !=-1) printf("%d\n",ans);

        else printf("No Solution\n");
    }
    return 0;
}
