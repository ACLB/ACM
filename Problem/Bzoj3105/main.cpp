#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int a[110];
int n;
int Ga[110];
bool cmp(int a,int b) {
    return a>b;
}
int main() {
    while(~scanf("%d",&n)) {
        LL sum = 0;
        for(int i = 0 ;i<n;i++) scanf("%d",&a[i]),sum+=a[i];
        sort(a,a+n,cmp);
        LL ans = 0;
        for(int i = 0;i<n;i++) {
            int st = a[i];
            for(int j = 31;j>=0;j--) {
                if((st>>j)&1) {
                    if(Ga[j]) st^=Ga[j];
                    else {
                        Ga[j] = st;
                        break;
                    }
                }
            }
           if(st)  ans+=a[i];
        }
        if(!ans) printf("-1\n");
        else printf("%lld\n",sum-ans);
    }
    return 0;
}
