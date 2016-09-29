#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[355][2];
bool g[355][355];
LL dp[355][355];
LL sum[355];
int main() {
    int T,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        sum[0] = 0;
        for(int i = 1;i<=n;i++) scanf("%lld",&a[i][0]);
        for(int i = 1;i<=n;i++) scanf("%lld",&a[i][1]),sum[i] = sum[i-1]+a[i][1];
        memset(g,false,sizeof(g));
        memset(dp,0,sizeof(dp));
        for(int i =1;i<=n;i++) if(__gcd(a[i][0],a[i-1][0])!=1) g[i-1][i] = true;
        for(int len = 2;len<=n;len+=2) {
            for(int i = 1;i+len-1<=n;i++) {
                int j = i+len-1;
                if(__gcd(a[i][0],a[j][0])   != 1 && g[i+1][j-1]) g[i][j] = true;
                if(__gcd(a[i][0],a[i+1][0]) != 1 && g[i+2][j]) g[i][j] = true;
                if(__gcd(a[j][0],a[j-1][0]) != 1 && g[i][j-2]) g[i][j] = true;
            }
        }
        for(int len = 2;len<=n;len++) {
            for(int i =1;i+len-1<=n;i++) {
                int j = i+len-1;
                if(g[i][j]) {
                    dp[i][j] = sum[j]-sum[i-1];
                }
                else {
                    for(int k = i;k<j;k++) {
                        dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
                    }
                }
            }
        }
        printf("%lld\n",dp[1][n]); 
    }
    return 0;
}
