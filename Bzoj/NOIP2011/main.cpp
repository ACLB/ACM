#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL Mod = 10007;
const int Max = 200010;
LL fac[Max],facv[Max];
LL Pow(LL n, LL m) {
    LL ans = 1;
    while(m) {
        if(m&1) ans = (ans*n)%Mod;
        n = (n*n)%Mod;
        m>>=1;
    }
    return ans;
}
void Init(){
    fac[0] = 1; facv[0] = 1;
    for(int i =1;i<Max;i++) {
        fac[i] = (fac[i-1]*i)%Mod;
        facv[i] = Pow(fac[i],Mod-2);
    }
}
LL C(LL n,LL m) {
    if(m>n) return 0;
    return  ((fac[n]*facv[m])%Mod*facv[n-m])%Mod;
}
int  a,b,k,n,m;
int main(){
    Init();
    while(~scanf("%d %d %d %d %d",&a,&b,&k,&n,&m)){
        LL ans = ((C(k,n)*Pow(a,n))%Mod*Pow(b,m))%Mod;
        printf("%d\n",(int)ans);
    }
    return 0;
}
