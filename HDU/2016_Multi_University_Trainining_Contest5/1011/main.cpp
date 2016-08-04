#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL Mod = 1000000007;

const int Max = 1100;

LL dp[Max][Max];

int a[Max],b[Max];

int main()
{
    int n,m;

    while(~scanf("%d %d",&n,&m))
    {
        memset(dp,0,sizeof(dp));

        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }

        for(int i = 1;i<=m;i++)
        {
            scanf("%d",&b[i]);
        }

        for(int i=  1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                dp[i][j]=  ((dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%Mod+Mod)%Mod;

                if(a[i] == b[j])
                {
                    dp[i][j] = (dp[i][j]+dp[i-1][j-1]+1)%Mod;
                }
            }
        }

        printf("%lld\n",dp[n][m]);
    }
    return 0;
}
