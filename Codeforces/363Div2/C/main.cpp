#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int Dp[110][3];

int main()
{
    int n;

    int day;

    scanf("%d",&n);

    int ans = INF;

    memset(Dp,INF,sizeof(Dp));

    Dp[0][0] = Dp[0][1] =Dp[0][2] =0;

    for(int i = 1; i<=n; i++)
    {
        scanf("%d",&day);

        if(day == 0)
        {
            Dp[i][0] = min(Dp[i-1][0],min(Dp[i-1][1],Dp[i-1][2]))+1;

            if(i == n)
            {
                ans = Dp[i][0];
            }
        }

        else if(day == 1)
        {
            Dp[i][1] = min(Dp[i-1][0],Dp[i-1][2]);

            Dp[i][0] = min(Dp[i-1][0],min(Dp[i-1][1],Dp[i-1][2]))+1;
            if(i == n)
            {
                ans = min(Dp[i][0],Dp[i][1]);
            }
        }
        else if(day == 2)
        {
            Dp[i][2] = min(Dp[i-1][0],Dp[i-1][1]);
            Dp[i][0] = min(Dp[i-1][0],min(Dp[i-1][1],Dp[i-1][2]))+1;
            if(i == n)
            {
                ans = Dp[i][2];
            }
        }
        else if(day == 3)
        {
            Dp[i][0] =  min(Dp[i-1][0],min(Dp[i-1][1],Dp[i-1][2]))+1;

            Dp[i][1] = min(Dp[i-1][0],Dp[i-1][2]);

            Dp[i][2] = min(Dp[i-1][0],Dp[i-1][1]);
            if(i == n)
            {
                ans = min(Dp[i][0],min(Dp[i][1],Dp[i][2]));
            }
        }

    }

    printf("%d\n",ans);

    return 0;
}
