#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[110][300][300];

int n,m;

int arr[110];

int st[300];

int bite[300];

char s[15];

int Bite(int s)
{
    int ans = 0;

    while(s)
    {
        if(s%2) ans++;

        s>>=1;
    }

    return ans;
}



int main()
{
    for(int i = 0;i<(1<<10);i++)
    {
        bite[i] = Bite(i);
    }

    st[0] = 0;

    for(int i = 0;i<(1<<10);i++)
    {
            if(i&(i<<1)) continue;

            if(i&(i<<2)) continue;

            st[++st[0]] = i;
    }

    while(~scanf("%d %d",&n,&m))
    {
        memset(dp,0,sizeof(dp));

        for(int i = 0;i < n;i++)
        {
            scanf("%s",s);

            int ans = 0;

            for(int j = 0;j<m;j++)
            {
                if(s[j] == 'H')
                {
                    ans +=(1<<j);
                }
            }

            arr[i]+=ans;
        }

        int lim = (1<<m);

        for(int i = 1;i<=st[0] && st[i] <lim;i++)
        {
            if(st[i] & arr[0]) continue;

            dp[0][st[i]][0] = bite[st[i]];
        }
        int ans = 0;

        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<=st[0]&& st[j] <lim;j++)
            {
                if(arr[i] & st[j]) continue;

                for(int k = 1;k<=st[0]&& st[k] <lim;k++)
                {
                    if(st[j] & st[k]) continue;

                    for(int s = 1;s<=st[0]&& st[s] <lim;s++)
                    {
                        if(st[j] & st[s]) continue;

                        dp[i][st[j]][st[k]] = max(dp[i][st[j]][st[k]],dp[i-1][st[k]][st[s]]+bite[st[j]]);
                    }
                }
            }
        }



        for(int i =1;i<=st[0]&& st[i] <lim;i++)
        {
            for(int j = 1;j<=st[0]&& st[j] <lim;j++)
            {
                ans = max(ans,dp[n-1][st[i]][st[j]]);
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
