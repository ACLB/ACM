#include <bits/stdc++.h>

using namespace std;

string s,t;

int n,m,k;

int Dp[11][1100][1100];

int PE[1100][1100];

int main()
{
    cin>>n>>m>>k>>s>>t;

    memset(Dp,0,sizeof(Dp));

    memset(PE,0,sizeof(PE));

    for(int i = 1 ;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(s[i-1] == t[j-1])
            {
                PE[i][j] = PE[i-1][j-1]+1;
            }
        }
    }

    int ans = 0;

    for(int kk = 1;kk<=k;kk++)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j =1;j<=m;j++)
            {
                Dp[kk][i][j] = max(Dp[kk][i-1][j],Dp[kk][i][j-1]);

                if(PE[i][j])
                {
                    Dp[kk][i][j]  = max(Dp[kk][i][j],Dp[kk-1][i-PE[i][j]][j-PE[i][j]]+PE[i][j]);
                }

                ans = max(ans,Dp[kk][i][j]);
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}
