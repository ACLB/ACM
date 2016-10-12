#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long LL;

LL gcd(LL a,LL b) {
    return b ==0?a:gcd(b,a%b);
}
LL ok(LL x,LL y,LL g) {
    return (x%g ==0 && y%g ==0);
}
int main() {
    LL a,b,x,y;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld %lld %lld %lld",&a,&b,&x,&y);
        LL g = gcd(2*a,2*b);
        if(ok(x,y,g)||ok(x+a,y+b,g)||ok(x+b,y+a,g)||ok(x+a+b,y+a+b,g)) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
