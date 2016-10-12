#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Max = 5*1e6+100;

int num[Max];

int ans[Max];

int  dfs(LL s)
{
    if(s == 1) return 0;

    if(s<Max && num[s]) return num[s];

    if(s%2)
    {
        int ans = dfs(3*s+1)+1;

        if(s<Max) num[s] = ans;

        return ans;
    }
    else
    {
        int ans = (dfs(s/2)+1);

        if(s<Max) num[s] = ans;

        return ans;
    }
}

void Get()
{
    memset(num,0,sizeof(num));

    int M = 0;

    num[1] = 0;

    ans[1] = 0;

    for(int i = 2;i<Max;i++)
    {
        num[i] = dfs(i);

        ans[i] = num[M]>num[i]?M:i;

        M = ans[i];
    }
}

int main()
{
    int T;

    int n;

    Get();

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        printf("%d\n",ans[n]);

    }
    return 0;
}
