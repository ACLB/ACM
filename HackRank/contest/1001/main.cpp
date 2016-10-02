#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL q,k,m,a,b;

struct node{
    int n,m;
    LL a[5][5];
    void Clear() {
        n = m = 0;
        memset(a,0,sizeof(a));
    }
    node operator * (const node &s) const {
        node temp;
        temp.Clear();
        temp.n = n ; temp.m = s.m;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<s.m;j++) {
                for(int k = 0;k<m;k++) {
                    temp.a[i][j] =(temp.a[i][j]+ (((a[i][k]*s.a[k][j])%m+m)%m))%m;
                }
            }
        }
    }
}

LL Pow(LL n,LL s) {
    LL ans = 1;
    while(s) {
        if(s&1) ans = (ans*n) %m;
        n = (n*n)%m;
        s>>=1;
    }
    return ans;
}

int main() {
    scanf("%lld",&q);
    for(LL i = 1;i<=q;i++) {
        scanf("%lld %lld %lld %lld",&a,&b,&k,&m);
        LL ans = Pow((a+b*i)%m,k);
        LL d = ans/i;
        LL c = ans%i;
        d%=m;c%=m;
        printf("%lld %lld\n",d,c);
    }
    return 0;
}
