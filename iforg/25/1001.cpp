#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL Mod = 998244353;
LL fac[550];
LL facv[550];
LL Pow(LL n,LL m){
    LL ans = 1;
    while(m) {
        if(m&1) ans = (ans*n)%Mod;
        m>>=1;
        n = (n*n)%Mod;
    }
    return ans;
}
void init() {
    fac[0] =1,facv[0] = 1;
    for(int i = 1;i<=500;i++) {
        fac[i] = (fac[i-1]*i)%Mod;
        facv[i] = Pow(fac[i],Mod-2);
    }
}
LL C(LL n,LL m) {
    if(m>n || n<0 || m<0) return 0;
    return (((fac[n]*facv[m])%Mod)*facv[n-m])%Mod;
}
int main() {
    int n,m;
    init();
    while(~scanf("%d %d",&n,&m)) {
        LL ans = C(n+m-1,m-1);
        for(int i = 0;i<=n;i++) {
            for(int k = 1;k<=m-1;k++) {
                LL ant =  ((C(m-1,k)*C(n-(k+1)*i+m-2,m-2))%Mod);
                if(k&1) {
                    ans  = ((ans - ant)%Mod+Mod)%Mod;
                }
                else ans = (ans + ant) %Mod;
            }
        }
        ans = (ans*m)%Mod;
        printf("%lld\n",ans);
    }
    return 0;
}
