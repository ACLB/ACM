#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
    LL b,d,s;
    scanf("%lld %lld %lld",&b,&d,&s);
    LL st = max(b,max(d,s))-1;
    LL ans = max(0LL,st-b)+max(0LL,st-d)+max(0LL,st-s);
    printf("%lld\n",ans);
    return 0;
}
