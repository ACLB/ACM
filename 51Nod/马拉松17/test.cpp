#include <bits/stdc++.h>
#define r(x) freopen(x,"r",stdin)
#define w(x) freopen(x,"w",stdout)
using namespace std;
typedef long long LL;
const int Max = 1e5+100;
LL Sg(LL n,LL k) {
    if(n%k == 1) return Sg(n/k,k);
    else return (n/k)*(k-1) + (n%k ? (n%k)-1 : 0);
}

LL a[Max];
LL s[Max];
int main() {
    LL n,k;
    while(~scanf("%lld %lld",&n,&k)) {
        LL ans = 0;
        for(int i = 0;i<n;i++) {
            scanf("%lld",&a[i]);

            s[i] = Sg(a[i],k);
            ans^=s[i];
        }
        if(ans == 0) printf("Bob\n");
        else {
            bool flag = false;
            for(int i = 0;i<n;i++) {
                LL ant = ans^a[i];
            }
        }
    }
    return 0;
}
