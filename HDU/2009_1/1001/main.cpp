#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL Mod = 200907;

int n;

LL a[3],k;

LL Pow(LL n,LL m) {
    LL ans  = 1;
    while(m) {
        if(m&1) ans = (ans*n)%Mod;
        n = (n*n)%Mod;
        m>>=1;
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for(int i = 0;i<n;i++) {
        for(int i = 0;i<3;i++) scanf("%lld",&a[i]);
        scanf("%d",&k);
        LL ans;
        if(a[1]%a[0] == 0 && a[2]%a[1] == 0 && a[1]/a[0]  == a[2]/a[1]) {
            LL q = a[1]/a[0];
            LL st = Pow(q,k-1);
            a[0] %= Mod;
            ans = (a[0]*st)%Mod;
        }
        else {
            LL d = (a[1] -a[0])%Mod;
            d = ((k-1)*d)%Mod;
            ans = (a[0]%Mod+d)%Mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
