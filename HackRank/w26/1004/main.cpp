#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;

const int maxn = 1e6+100;

LL a[maxn],h1,h2,m;

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    scanf("%lld %lld %lld",&m,&h1,&h2);
    a[n+1] = 100LL*INF;
    a[0] = -100LL*INF;
    int l = 1;
    LL ans;
    for(int i = 2;i<=n;i++) {
        if(a[i]-a[i-1]>=h1) {
            while(a[i-1] - a[l]>m) l++;
            if(m-a[i-1]+a[l]>=h1 && m - a[i-1]+a[l]<=2*h2 && a[l]-a[l-1]+a[i]-a[i-1]>=m-a[i-1]+a[l]) {
                ans = a[l]-(m-a[i-1]+a[l])/2;
                break;
            }
        }
        if(a[i]-a[i-1]>h2 || a[i]-a[i-1]<h1){
            l = i+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
