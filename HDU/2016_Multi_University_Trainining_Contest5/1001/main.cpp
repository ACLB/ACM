#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

double dp[2220][16];

int main()
{
    for(int i = 0;i<=2000;i++)
        for(int j = 0;j<=15;j++)
            dp[i][j] = INF;

    for(int i = 0;i<=15;i++) dp[0][i] = 0;

    for(int i = 1;i<=2000;i++)
    {
        for(int j = 1;j<=15;j++)
        {
            for(int z = 1;z<=i;z++)
            {
                dp[i][j] = min(dp[i][j],dp[i-z][j]*(i-z+1)*1.0/(i+1)+dp[z-1][j-1]*z*1.0/(i+1)+1);
            }
        }
    }


    int k,w;

    while(~scanf("%d %d",&k,&w))
    {
        w = min(w,15);

        printf("%.6f\n",dp[k][w]);
    }
    return 0;
}
