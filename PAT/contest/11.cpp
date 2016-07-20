#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int n,k;

bool mp[110][110];

int Du[110];

bool vis[110];

int main()
{
    scanf("%d",&n);

    int u;

    memset(mp,false,sizeof(mp));

    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&k);

        for(int j = 1;j<=k;j++)
        {
            scanf("%d",&u);

            mp[i][u] = true;

            Du[u]++;
        }
    }
    memset(vis,false,sizeof(vis));

    bool flag = false;

    for(int i = 0;i<n;i++)
    {
        int fa = -1;
        for(int j = 1;j<=n;j++)
        {
            if(!vis[j] && Du[j] == 0)
            {
                fa = j;

                break;
            }
        }

        if(fa == -1)
        {
            flag = true;
            break;
        }
        vis[fa] = true;

        for(int j = 1;j<=n;j++)
        {
            if(!vis[j] && mp[fa][j])
            {
                Du[j] --;
            }
        }
    }

    if(flag)
    {
        printf("0\n");
    }
    else printf("1\n");
    return 0;
}
