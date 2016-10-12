#include <bits/stdc++.h>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
using namespace std;
typedef long long LL;
const LL Mod = 1e9+7;
const int Max = 1e5+100;
LL fac[Max],facv[Max];
struct node{
    int x,y;
    bool operator < (const node &a) const {
        return x == a.x ? y<a.y:x<a.x;
    }
}a[Max];
LL Pow(LL n,LL m) {
    LL ans = 1;
    while(m) {
        if(m&1) ans = (ans*n)%Mod;
        n = (n*n)%Mod;
        m>>=1;
    }
    return ans;
}
void Init() {
    fac[0] = 1;
    for(int i = 1;i<Max;i++) {
        fac[i] = (fac[i-1]*i)%Mod;
        facv[i] = Pow(fac[i],Mod-2);
    }
}
LL C(LL n,LL m) {
    if(n < 0 || m <0 || n < m) return 0;
    return (((fac[n]*facv[m])%Mod)*facv[n-m])%Mod;
}
LL dp[Max];
int main() {
    int h,w,n;
    scanf("%d %d %d",&h,&w,&n);
    for(int i = 0;i<n;i++) scanf("%d %d",&a[i].x,&a[i].y);
    sort(a,a+n);

    return 0;
}
