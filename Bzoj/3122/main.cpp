#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define rr() freopen("in.in","r",stdin)
#define ww() freopen("out.out","w",stdout)
using namespace std;
typedef long long LL;
LL a,b,p,x1,t;
void exgcd(LL A,LL B,LL &g,LL &x,LL &y){
    if(B == 0){
        g = A;
        x = 1;
        y = 0;
        return ;
    }
    else{
        exgcd(B,A%B,g,y,x);
        y-=(A/B)*x;
    }
}
LL INV(LL A,LL B){
    LL g,x,y;
    exgcd(A,B,g,x,y);
    return g==1?(x%B+B)%B:-1;
}
LL cal1(){
    t = ((t-x1)%p+p)%p;
    LL ans = INV(b,p);
    if(ans == -1) return ans;
    else return (ans*t)%p+1;
}
LL Pow(LL A, LL m){
    LL ans = 1;
    while(m){
        if(m%2) ans = (ans*A)%p;
        A = (A*A)%p;
        m>>=1;
    }
    return ans;
}
LL bsgs(LL A, LL B,LL n){
    A%=n;
    if(!A){
        if(!B) return 1;
        else return -1;
    }
    LL m = (LL)sqrt(n)+1;
    LL inv = INV(Pow(A,m),n);
    if(inv == -1)  return -1;
    map<LL,LL>mp;mp.clear();

    mp[1] = 0;

    LL e= 1;
    for(int i = 1;i<m;i++){
        e = (e*A)%p;
        if(!mp.count(e)) mp[e] = i;
    }
    for(int i =0;i<m;i++){
        if(mp.count(B)) return m*i+mp[B];
        B =(inv*B)%p;
    }
    return -1;
}

LL cal2(){
    LL inv = INV(a-1,p);
    x1 =(x1+b*inv)%p;
    t = (t+b*inv)%p;
    LL inv2 =INV(x1,p);
    if(inv2 == -1) return -1;
    t = (t*inv2)%p;
    LL ans  = bsgs(a,t,p);
    return ans == -1?ans:ans+1;
}
LL solve(){
    if(x1 == t) return 1;
    if(a ==0) {
        if(b == t) return 2;
        else return -1;
    }
    if(a == 1) return cal1();
    else return cal2();
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld %lld %lld %lld",&p,&a,&b,&x1,&t);
        printf("%lld\n",solve());
    }
    return 0;
}
