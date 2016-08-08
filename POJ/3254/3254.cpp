#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Mod = 100000000;

int dp[20][5000];

int n,m;

int arr[15];

int main()
{
    int op;
    while(~scanf("%d %d",&n,&m))
    {
        for(int i = 0;i<n;i++)
        {
            int ans = 0;
            
            for(int j = 0;j<m;j++)
            {
                scanf("%d",&op);

                if(!op)
                {
                    ans +=(1<<j);
                }
            }

            arr[i] = ans;
        }

        memset(dp,0,sizeof(dp));

        for(int i = 0;i<(1<<m);i++)
        {
            if((arr[0]&i)) continue;

            if(i&(i<<1)) continue;

            dp[0][i] = 1;
        }
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<(1<<m);j++)
            {
                if((arr[i]&j)) continue;

                if(j&(j<<1)) continue;

                for(int k  = 0;k<(1<<m);k++)
                {
                    if(arr[i-1]&k) continue;

                    if(k&(k<<1)) continue;

                    if(j&k) continue;

                    dp[i][j] = (dp[i][j]+dp[i-1][k])%Mod;
                }
            }
        }

        int ans = 0;

        for(int i = 0;i<(1<<m);i++)
        {
            ans = (ans+dp[n-1][i])%Mod;
        }

        printf("%d\n",ans);
    }
    return 0;
}
