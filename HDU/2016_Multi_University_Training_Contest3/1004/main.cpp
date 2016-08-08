#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int x,y;

    bool operator < (const node &a)
    {
        return x==a.x?y<a.y:x<a.y;
    }

    double operator - (const node &a) const
    {
        return abs(x-a.x)+abs(y-a.y);
    }

    bool operator == (const node &a) const
    {
        return (x==a.x && y==a.y);
    }
}arr[110000];

bool vis[210000];

int main()
{
    int T;

    int n,m;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&m);

        for(int i = 0;i<n;i++)
        {
            scanf("%d %d",&arr[i].x,&arr[i].y);
        }

        memset(vis,false,sizeof(vis));

        bool flag = false;

        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int ans = arr[i]-arr[j];

                if(vis[ans])
                {
                    flag = true;

                    break;
                }

                vis[ans] = true;
            }

            if(flag) break;
        }

        if(flag) printf("YES\n");

        else printf("NO\n");
    }

    return 0;
}
