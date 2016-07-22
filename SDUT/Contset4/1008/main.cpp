#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

bool x[550];

bool y[550];

bool mp[550][550];

int pre[550];

int n,m;

int dfs(int u)
{
    x[u] = true;

    for(int i = 1;i<=n;i++)
    {
        if(mp[u][i] &&!y[i] )
        {
            y[i] = true;

            if(pre[i] == 0 ||dfs(pre[i]))
            {
                pre[i] = u;

                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int u,v;
    while(~scanf("%d %d",&n,&m))
    {

        memset(pre,0,sizeof(pre));

        memset(x,false,sizeof(x));

        memset(mp,false,sizeof(mp));

        for(int i = 1;i<=m;i++)
        {
            scanf("%d %d",&u,&v);

            mp[u][v] = true;
        }

        int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            if(!x[i])
            {
                memset(y,false,sizeof(y));
                ans+=dfs(i);
            }
        }

        printf("%d",ans);
    }
    return 0;
}
