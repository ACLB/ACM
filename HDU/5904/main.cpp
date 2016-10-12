#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6+100;
int p[maxn],pb[maxn];
int a[maxn],b[maxn];
int main() {
    int n,m,t,da;
    scanf("%d",&t);
    for(int z = 1; z<=t; z++) {
        scanf("%d %d",&n,&m);
        for(int i = 0; i<n; i++) {
            scanf("%d",&da);
            p[da] = z;
            if(p[da-1] == z) a[da] = a[da-1]+1;
            else a[da] = 1;
        }
        int ans =0 ;
        for(int i = 0; i<m; i++) {
            scanf("%d",&da);
            pb[da] = z;
            if(pb[da-1] == z) b[da] = b[da-1]+1;
            else b[da] = 1;
            if(p[da]!=z) a[da] = 0;
            ans = max(ans,min(b[da],a[da]));
        }
        printf("%d\n",ans);
    }
    return 0;
}
