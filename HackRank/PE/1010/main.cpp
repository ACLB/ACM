#include <bits/stdc++.h>

using namespace std;

const int Max = 1e6+100;

bool vis[Max];

int pr[Max];

void Get()
{
    memset(vis,false,sizeof(vis));

    pr[0] = 0;

    for(int i = 2;i<Max;i++)
    {
        if(!vis[i])
        {
            pr[++pr[0]] = i;

            for(int j = i+i;j<Max;j+=i)
            {
                vis[j] = true;
            }
        }
    }
}
int main()
{
    Get();

    int T,n;

    long long sum;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        sum = 0;

        for(int i = 1;i<=pr[0];i++)
        {
            if(pr[i]>n) break;

            sum+=pr[i];
        }

        printf("%lld\n",sum);
    }
    return 0;
}
