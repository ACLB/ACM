#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1000;
int dp[maxn];
int a[maxn];
int main(){
    int T,n,da;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        int ans = 0;
        memset(dp,0,sizeof(dp));
        for(int i =0 ;i<n;i++) {
            scanf("%d",&a[i]);
            int st = 0;
            for(int j = i-1;j>=0;j--) {
                if(a[j] >a[i]) {
                    st = max(dp[j],st);
                }
            }
            dp[i] = st+1;
            ans = max(ans,dp[i]);
        }

        printf("%d\n",ans);
    }
    return 0;
}
