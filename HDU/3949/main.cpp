#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 11000;

LL a[maxn];

int main() {
    int T,z = 1;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;i++) {
            scanf("%lld",&a[i]);
        }
        int row  = 0;
        bool flag = false;
        for(int i = 62;i>=0&&row<n;i--) {
            int r  = row;
            for(int j = row+1;j<n;j++) {
                if((a[j]>>i)&1) r = j;
            }
            if((a[r]>>i)&1) {
                swap(a[row],a[r]);
                for(int j = 0;j<n;j++) {
                    if(j!=row && ((a[j]>>i)&1)) {
                        a[j] = a[j]^a[row];
                        if(!a[j]) flag = true;
                    }
                }
                row++;
            }
        }
        int q;
        LL k;
        scanf("%d",&q);
        LL ans ;
        printf("Case #%d:\n",z++);
        for(int i = 1;i<=q;i++) {
            scanf("%lld",&k);
            if(flag) k--;
            if(k>>row) {
                printf("-1\n");
                continue;
            }
            ans = 0;
            for(int j = 0;j<row;j++) {
                if((k>>j)&1) {
                    ans^=a[row-1-j];
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
