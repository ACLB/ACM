#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);

const double e = exp(1);

typedef long long LL;

int T;

int n,m;

int a[111111];

int vis[5500];

int main()
{
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&m);

        a[0] =0;

        memset(vis,0,sizeof(vis));

        for(int i  = 1;i<=n;i++)
        {
            scanf("%d",&a[i]);

            a[i] = (a[i-1]+a[i])%m;
        }

        bool flag = false;

        vis[0] = true;

        for(int i = 1;i<=n;i++)
        {
            if(vis[a[i]])
            {
                flag = true;

                break;
            }

            vis[a[i]] = true;
        }

        if(flag) printf("YES\n");

        else printf("NO\n");
    }

    return 0;
}
