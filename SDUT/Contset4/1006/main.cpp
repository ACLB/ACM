#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int Max= 200;

int cnt[Max][Max];

void Init()
{
    cnt['A']['A'] = 5; cnt['A']['C'] = cnt['C']['A'] = -1;

    cnt['A']['G'] = cnt['G']['A'] = -2; cnt['A']['T'] = cnt['T']['A'] = -1;

    cnt['A'][' '] = cnt[' ']['A'] = -3; cnt['C']['C'] = 5;

    cnt['C']['G'] = cnt['G']['C'] = -3; cnt['C']['T'] = cnt['T']['C'] = -2;

    cnt['C'][' '] = cnt[' ']['C'] = -4; cnt['G']['G'] = 5;

    cnt['G']['T'] = cnt['T']['G'] = -2; cnt['G'][' '] = cnt[' ']['G'] = -2;

    cnt['T']['T'] = 5; cnt['T'][' '] = cnt[' ']['T'] = -1;
}

char s[110],t[110];

int dp[110][110];

int main()
{
    Init();

    int T;

    int n,m;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %s",&n,s);

        scanf("%d %s",&m,t);

        dp[0][0] = 0;

        for(int i = 0;i<n;i++) dp[i+1][0] = dp[i][0]+cnt[s[i]][' '];

        for(int i = 0;i<m;i++) dp[0][i+1] = dp[0][i] +cnt[' '][t[i]];

        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                    dp[i+1][j+1] = max(dp[i][j] + cnt[s[i]][t[j]],max(dp[i+1][j]+cnt[' '][t[j]],dp[i][j+1]+cnt[s[i]][' ']));
            }
        }

        printf("%d\n",dp[n][m]);
    }

    return 0;
}
