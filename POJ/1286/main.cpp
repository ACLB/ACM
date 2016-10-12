#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
LL ans[30];
LL Pow(LL n,LL m) {
    LL an = 1;
    while(m) {
        if(m&1) an*=n;
        n*=n;
        m>>=1;
    }
    return an;
}
LL Solve(int s) {
    LL sum = 0;
    for(int i = 0;i<s;i++) {
        int g = __gcd(i,s);
        sum+=Pow(3,g);
    }
    return sum;
}
LL fz(LL s) {
    if(s&1)  return s*Pow(3,s/2+1);
    return s/2*Pow(3,s/2)+s/2*Pow(3,s/2+1);
}
void Init(){
    for(int i = 1;i<=24;i++) {
        ans[i] = Solve(i);
        ans[i]+=fz(i);
        ans[i]/=(2*i);
    }
}
int main(){
    Init();
    int n;
    while(~scanf("%d",&n)&&n!=-1) printf("%I64d\n",ans[n]);
    return 0;
}
