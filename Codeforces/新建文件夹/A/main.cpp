#include <bits/stdc++.h>

using namespace std;

int vis[110];

int main()
{
    int data;

    int sum = 0;

    for(int i = 0; i<5; i++)
    {
        scanf("%d",&data);

        vis[data]++;

        sum+=data;
    }

    int ans = sum;

    for(int i = 0;i<=100;i++)
    {
        if(vis[i]&&vis[i]!=1)
        {
            ans = min(ans,sum-(i*(vis[i] > 3 ? 3 : vis[i])));
        }
    }

    printf("%d\n",ans);
    return 0;
}
