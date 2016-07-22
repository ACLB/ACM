#include <bits/stdc++.h>

using namespace std;

double p[20][20];

double Dp[1<<18][18];

int main()
{
    int n;

    cin>>n;

    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin>>p[i][j];

    Dp[1][0] = 1;

    for(int _ = 0;_<(1<<18);_++)
    {
        for(int i = 0;i<n;i++)
        {
            if(!(_&(1<<i))) continue;
            for(int j = 0;j<n;j++)
            {
                if(!(_&(1<<j)|| i == j)) continue;

                Dp[_][i] = max(Dp[_][i] ,p[i][j]*Dp[_^(1<<j)][i]+p[j][i]*Dp[_^(1<<i)][j]);
            }
        }
    }

    double ans = 0;

    for(int i = 0;i<n;i++)
    {
        ans  = max(ans,Dp[(1<<n)-1][i]);
    }

    cout<<ans<<endl;

    return 0;
}
