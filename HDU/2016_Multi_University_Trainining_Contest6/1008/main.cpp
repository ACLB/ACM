#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Mod =1e9+7;

const int Max = 1100;

int dp[2][Max][3][3];

int main()
{
    int T,n,s,x;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&s);

        memset(dp,0,sizeof(dp));

        dp[0][0][0][0] = 1;

        bool op = true;

        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&x);

            for(int j =s;j>=0;j--)
            {
                for(int s1 = 0; s1 < 3 ;s1++)
                {
                    for(int s2 = 0;s2 < 3;s2++)
                    {
                        dp[op][j][s1][s2] = dp[!op][j][s1][s2];

                        if(j>=x) dp[op][j][s1][s2] =(dp[op][j][s1][s2] + dp[!op][j-x][s1][s2])%Mod;

                        if(s1>0 && j>=x) dp[op][j][s1][s2] = (dp[op][j][s1][s2] + dp[!op][j-x][s1-1][s2])%Mod;

                        if(s2 > 0) dp[op][j][s1][s2] = (dp[op][j][s1][s2] + dp[!op][j][s1][s2-1])%Mod;
                    }
                }
            }

            op =!op;
        }

        int ans =0;

        for(int i = 0;i<=s;i++)
        {
            ans = (ans+dp[!op][i][2][2])%Mod;
        }

        ans  = (((ans*2)%Mod)*2)%Mod;

        printf("%d\n",ans);

    }
    return 0;
}
