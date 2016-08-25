#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
using namespace std;
typedef long long LL;
int main() {
    rr("data1.in");
    ww("data1.out");
    int n,da;
    while(~scanf("%d",&n)) {
        stack<int>St;
        LL sum = 0;
        for(int i = 0;i<n;i++) {
            scanf("%d",&da);
            sum+=St.size();
            while(!St.empty() && St.top()<da) St.pop();
            St.push(da);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
