#include <bits/stdc++.h>
#define ww(x) freopen(x,"w",stdout)
#define rr(x) freopen(x,"r",stdin)
using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double Pi = acos(-1.0);
const int  Max = 110000;
int x[Max],h[Max];
int main() {
    int n,m;
    long long  sum = 0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) scanf("%d",&h[i]);
    scanf("%d",&m);
    for(int i = 1;i<=m;i++) scanf("%d",&x[i]);
    sort(x+1,x+m+1);
    int op ;
    for(int i = x[m];i<=n;i++) sum+=h[i];
    for(int i = m;i>=2;i--) 
    {
        op = 1;
        for(int j = x[i]-1;j>=x[i-1];j--,op++)sum +=min(op,h[j]);
    } 
    op = 1;
    for(int i = x[1]-1;i>=1;i--,op++) sum+=min(op,h[i]) ;
    printf("%lld\n",sum);
    return 0;
}
