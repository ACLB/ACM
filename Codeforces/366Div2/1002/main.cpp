#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int Sg[100];

bool vis[110];

int GetSg(int s)
{
    memset(vis,false,sizeof(vis));

    for(int i =1;i<s;i++)
    {
        vis[Sg[i]^Sg[(s-i)]] = true;
    }

    for(int i = 0;;i++)
    {
        if(!vis[i]) return i;
    }
}

int main()
{

    int n;

    LL x,ans;

    scanf("%d",&n);

    ans = 0;

    for(int i = 0;i<n;i++)
    {
        scanf("%I64d",&x);

        if(x%2 ==0) ans^=1;

        if(ans) printf("1\n");

        else printf("2\n");
    }

    return 0;
}
