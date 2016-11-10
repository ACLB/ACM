#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int GetLen(LL s) {
    int ans = 0;
    while(s) {
        ans++;
        s/=10;
    }
    return ans;
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        LL p =0, q =1;
        for(int i  = 1; i<=n; i++) {

            LL a = p*i+q;
            LL b = q*i;
            p =  a, q = b;
            LL g = __gcd(p,q);
            p/=g,q/=g;
        }
        p*=n;
        LL g = __gcd(p,q);
        p/=g,q/=g;
        if(p%q ==0) {
            printf("%lld\n",p/q);
        } else {
            LL a = p/q;
            LL b = p%q;
            int len = GetLen(q);
            if(a == 0) {
                printf("%lld\n",b);
                for(int i = 1; i<=len; i++) printf("-");
                printf("\n");
                printf("%lld\n",q);
            } else {
                int len1 = GetLen(a)+1;
                for(int i = 1; i<=len1; i++) printf(" ");
                printf("%lld\n",b);
                printf("%lld ",a);
                for(int i = 1; i<=len; i++) printf("-");
                printf("\n");
                for(int i = 1; i<=len1; i++) printf(" ");
                printf("%lld\n",q);
            }
        }
    }

    return 0;
}
