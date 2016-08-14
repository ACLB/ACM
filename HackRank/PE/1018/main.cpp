#include <bits/stdc++.h>

using namespace std;

int a[20][20];

int dp[20][20];
int main()
{
    int T;

    int n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<=i;j++) scanf("%d",&a[i][j]);
        }
        dp[0][0] = a[0][0];

        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<=i;j++)
            {
                if(j ==0 )dp[i][j] = dp[i-1][j]+a[i][j];
                else if(j ==i) dp[i][j] = dp[i-1][j-1]+a[i][j];
                else dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
            }
        }
        int ans = 0;

        for(int i = 0;i<n;i++) ans = max(ans,dp[n-1][i]);

        printf("%d\n",ans);
    }
    return 0;
}
