#include <bits/stdc++.h>

using namespace std;

string s,t;

int n,m,k;

int Dp[11][1100][1100];

int PE[11][1100][1100];

int main()
{
    cin>>n>>m>>k>>s>>t;

    memset(Dp,0,sizeof(Dp));

    mesmet(PE,0,sizeof(PE));

    for(int st = 1; st<=k; st++)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    PE[st][i][j] = max(PE[st][i-1][j-1]+1,Dp[st-1][i-1][j-1]);
                }
                Dp[st][i][j] = max(Dp[st][i-1][j],Dp[st][i][j-1]);
            }
        }
    }
    return 0;
}
