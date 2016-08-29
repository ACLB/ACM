#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL Mod = 998244353;
LL Pow(LL n,LL m){
    LL ans = 1;
    while(m) {
        if(m&1) ans = (ans*n)%Mod;
        n = (n*n)%Mod;
        m>>=1;
    }
    return ans;
}
int main(){
    LL n,m;

    while(~scanf("%lld %lld",&n,&m)){
        if(n == 1) printf("%lld\n",m%Mod);
        else if(n == 2) {
            if(m>1)
            printf("%lld\n",(m*(m-1))%Mod);
            else printf("0\n");
        }
        else {
            if(m>1)
                printf("%lld\n",(((Pow(m-1,n-2)*m)%Mod)*(m-2)%Mod));
            else printf("0\n");
        }
    }
    return 0;
}
