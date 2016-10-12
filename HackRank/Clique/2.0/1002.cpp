#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
using namespace std;
typedef long long LL;
const LL Mod = 1e9+7;
const double Pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int Max = 1e6+100;
LL A,N,K;
LL num[Max];
int  main() {
    while(~scanf("%lld %lld %lld",&A,&N,&K)) {
        if(A%K == 0) printf("%lld\n",(N*(N-1)/2));
        else {
            LL g =__gcd(A,K);
            g = K/g;
            LL sum = 0;
            LL s = N/g;
            for(int i = 0;i<g;i++) {
                num[i] = s;
            }
            for(int i =1;i<=N%g;i++) num[i]++;
            sum+=(num[0]*(num[0]-1)/2);
            for(int i = 1;i<=g/2;i++) {
                sum+=(num[i]*(num[g-i]));
            }
            if(g%2 == 0)
            {
                sum-=num[g/2]*num[g/2];
                sum+=num[g/2]*(num[g/2]-1)/2;
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}
