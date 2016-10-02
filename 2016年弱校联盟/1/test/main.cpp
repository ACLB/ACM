#include <bits/stdc++.h>

using namespace std;
const int maxn = 110;
int va[4];
int dp[110];
int ok(int a1,int a2,int a3)  {
    va[1] = a1;
    va[2] = a2;
    va[3] = a3;
    memset(dp,0,sizeof(dp));
    for(int i = 1;i<=3;i++) {
        for(int j = 1;j<=va[i];j++) {
            for(int k = maxn-1;k>=j*i;k--) dp[k] = max(dp[k],dp[k-j*i]+j*i);
        }
    }
    int ans = 0;
    for(int i = 1;i<maxn;i++)
    {
        if(dp[i] == i) ans++;
    }
    return ans;
}
int main()
{
    freopen("out.out","w",stdout);
    for(int i = 0;i<10;i++) {
        for(int j = 0;j<10;j++) {
            for(int k = 0;k<10;k++) {
                printf("%d %d %d %d\n",i,j,k,ok(i,j,k));
                for(int z= 1;z<maxn;z++) {
                    if(dp[z] == z) printf("%d ",z);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
