#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct node
{
    int x1,y1,x2,y2,op;
}No;

No a[20];


bool mp[20][20];

int Du[20];

bool vis[20];

int ans ;

int n;

void dfs(int u,int op,int num)
{
    if(num == n) 
    {
        ans = min(ans,op);

        return ;
    }

    if(op>ans) return ;

    for(int  i =1;i<=n;i++)
    {
        if(mp[u][i])
        {
            Du[i]--;
        }
    }

    for(int i = 1;i<=n;i++)
    {
        if(!vis[i] && Du[i] ==0)
        {
            vis[i] = true;
            if(a[i].op == a[u].op)
            {
                dfs(i,op,num+1);
            }
            else 
            {
                dfs(i,op+1,num+1);
            }

            vis[i] = false;
        }
    }

    for(int i = 1;i<=n;i++)
    {
        if(mp[u][i])
        {
            Du[i]++;
        }
    }
}

int main()
{
    int T;


    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(int i = 1;i<=n;i++)
        {
            scanf("%d %d %d %d %d",&a[i].y1,&a[i].x1,&a[i].y2,&a[i].x2,&a[i].op);
        }

        memset(mp,false,sizeof(mp));

        memset(Du,0,sizeof(Du));

        for(int i  = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(i == j) continue;

                if(a[j].y1 != a[i].y2) continue;

                if((a[j].x1 >= a[i].x1 && a[j].x1>a[i].x2) ||(a[j].x1<=a[i].x1 && a[j].x2>=a[i].x2) || (a[j].x2>a[i].x1 &&a[j].x2<=a[i].x2))
                {
                    mp[i][j] = true;

                    Du[j]++;
                }
            }
        }

        memset(vis,false,sizeof(vis));

        ans = n+1;

        for(int i  =1;i<=n;i++)
        {
            if(Du[i] == 0)
            {
                vis[i] = true;
                dfs(i,1,1);

                vis[i] = false;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
