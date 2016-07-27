#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int mp[15][15];

int n;

int dp[15][500];

void GetFloyd()
{
    for(int i = 0; i<=n; i++)
    {
        for(int k = 0; k<=n; k++)
        {
            for(int s = 0; s<=n; s++)
            {
                mp[k][s] = min(mp[k][s],mp[k][i]+mp[i][s]);
            }
        }
    }
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        for(int i = 0; i<=n; i++)
        {
            for(int j = 0; j<=n; j++)
            {
                scanf("%d",&mp[i][j]);
            }
        }

        GetFloyd();

        for(int i =0; i<(1<<n); i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if((1<<(j-1))&i)
                {
                    if((1<<(j-1)) == i)
                    {
                        dp[j][1<<(j-1)] = mp[0][j];
                    }
                    else
                    {
                        dp[j][i] = INF;

                        for(int k = 1; k<=n; k++)
                        {
                            if(((1<<(k-1))&i)&& k != j)
                            {
                                dp[j][i] = min(dp[j][i],dp[k][i^(1<<(j-1))]+mp[k][j]);
                            }
                        }
                    }
                }
            }
        }

        int ans = dp[1][(1<<n)-1]+mp[1][0];

        for(int i =2; i<=n; i++)
        {
            ans = min(ans,dp[i][(1<<n)-1]+mp[i][0]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
