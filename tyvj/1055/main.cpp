#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1100;
int dp[maxn][maxn];
int sum[maxn],a[maxn];
int main() {
    int n;
    while(~scanf("%d",&n)) {
        sum[0] = 0;
        memset(dp,INF,sizeof(dp));
        for(int i = 1; i<=n; i++)  {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1]+a[i];
            dp[i][i] = 0;
        }
        for(int i = 2; i<=n; i++) {
            for(int j = 1; j+i-1<=n; j++) {
                for(int k = j; k<j+i-1; k++)
                    dp[j][j+i-1] = min(dp[j][j+i-1],dp[j][k]+dp[k+1][j+i-1]);
                dp[j][j+i-1] +=(sum[j+i-1]-sum[j-1]);
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
