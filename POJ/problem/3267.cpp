#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int Dp[350];

char s[350];

char str[650][30];

int main()
{
    int n,m;

    while(~scanf("%d %d",&n,&m))
    {
        scanf("%s",s+1);

        for(int i = 0;i<n;i++)
        {
            scanf("%s",str[i]);
        }

        Dp[0] = 0;

        for(int i = 1;i<=m;i++)
        {
            Dp[i] = Dp[i-1]+1;

            for(int j = 0;j<n;j++)
            {
                int len = strlen(str[j]);

                int l = len-1;

                for(int k = i;k>=1;k--)
                {
                    if(str[j][l] == s[k]) l--;

                    if(l == -1)
                    {
                        Dp[i] = min(Dp[i],Dp[k-1]+i-k+1-len);

                        break;
                    }
                }
            }
        }

        printf("%d\n",Dp[m]);
        
    }
    return 0;
}
