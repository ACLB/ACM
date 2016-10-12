#include <bits/stdc++.h>

using namespace std;

const int Max = 1e6+100;

bool vis[Max];

int pr[Max];

void Get()
{
    memset(vis,false,sizeof(vis));

    pr[0] = 0;

    for(int i  =2;i<Max;i++)
    {
        if(!vis[i])
        {
            pr[++pr[0]]  = i;

            for(int j = i+i;j<Max;j+=i) vis[j] = true;
        }
    }
}

int main()
{
    Get();
    int T,n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        printf("%d\n",pr[n]);
    }
    return 0;
}
