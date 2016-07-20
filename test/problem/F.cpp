#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int Dp[110];

int a[110][2];

int main()
{
    int n;

    int T;
    
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n))
    {
        for(int i = 1;i<=n;i++)
        {
            scanf("%d %d",&a[i][0],&a[i][1]);
        }

        Dp[0] = 0 ;

        for(int i = 1;i<=n;i++)
        {
            Dp[i] = (a[i][0]+10)*a[i][1]+Dp[i-1];

            int sum  = a[i][0];

            for(int j = i-1;j>=1;j--)
            {
                sum+=a[j][0];

                Dp[i] = min(Dp[j-1]+(sum+10)*a[i][1],Dp[i]);
            }
        }

        printf("%d\n",Dp[n]);
    }
    return 0;
}
