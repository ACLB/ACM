/*
没有搞出来
*/

#include <bits/stdc++.h>

using namespace std;

unsigned int  Dp[110];

int main()
{
    int n,m;

    scanf("%d %d",&n,&m);

    Dp[0] = 1;

    for(int i = 1;i<=n;i++)
    {
        Dp[i] = Dp[i-1]*m;

        if(i%2 == 0)
        {
            int j = i/2;

            Dp[i]-=Dp[j];

        }
    }
    unsigned int  ans = 0;

    for(int i= 1;i<=n;i++)
    {
        ans  +=Dp[i];
    }

    printf("%u\n",ans);

    return 0;
}
