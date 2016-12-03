#include <bits/stdc++.h>

using namespace std;
const int  maxn =1e5+100;
typedef long long LL;
int num[maxn*3];
int n;
int main() {
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j*j<=i;j++) {
            if(i%j == 0) num[i]+=2;
            if(i%j == 0 && i/j == j) num[i]-=1;
        }
    }
    LL ans = 0;
    for(int i = 1;i<n;i++) {
        ans +=(num[i]*num[n-i]);
    }
    for(int i = 1;i<=n;i++) {
        if(n%i == 0) {
            ans-=(n/i-1);
        }
    }
    printf("%lld\n",ans/2);
    return 0;
}
