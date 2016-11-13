#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long LL;
const LL mod = 10086;
const int maxn = 1e5+100;

int a[maxn],n,q;

void Gauss() {
    int row =0;
    for(int i = 29,j;i>=0;i--) {
        for(j = row;j<n;j++) if((a[j]>>i)&1) break;
        if(j == n) continue;
        swap(a[row],a[j]);
        for(j = 0;j<n;j++) {
            if(j == row || ((a[j]>>i)&1) == 0) continue;
            a[j]^=a[row];
        }
        row++;
    }
}

int main() {
    while(~scanf("%d",&n)) {
        for(int i = 0;i<n;i++) scanf("%d",&a[i]);
        Gauss();
        scanf("%d",&q);
        int num = 0;
        for(int i = 0;i<n;i++) if(a[i]) num++;
        LL st = 0,ans = 0;
        for(int i = 0;i<num;i++) {
            if((st^a[i])>q) continue;
            st^=a[i];
            ans = (ans+(1LL<<(num-i-1))%mod)%mod;   
        }
        for(int i = 1;i<=n-num;i++) {
            ans <<=1LL;
            ans %=mod;
        }
        ans ++;
        ans %= mod;
        printf("%lld\n",ans);
    }
    return 0;
}
