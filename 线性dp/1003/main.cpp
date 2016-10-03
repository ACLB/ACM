#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 110;

int dpr[maxn],dpl[maxn];

int a[maxn];

int main() {
    int n;
    while(~scanf("%d",&n)) {
        for(int i = 0; i<n; i++) scanf("%d",&a[i]);
        memset(dpr,0,sizeof(dpr));
        memset(dpl,0,sizeof(dpl));
        for(int i = 0;i<n;i++) {
            int st = 0;
            for(int j = i-1;j>=0;j--) if(a[j] < a[i]) st = max(st,dpr[j]);
            dpr[i] = st+1;
        }
        for(int i = n-1;i>=0;i--) {
            int st = 0;
            for(int j = i+1;j<n;j++) if(a[j] < a[i]) st = max(st,dpl[j]);
            dpl[i] = st+1;
        }
        int ans  = 0;
        for(int i = 0;i<n;i++) ans = max(ans,dpr[i]+dpl[i]-1);
        printf("%d\n",n - ans);
     }
    return 0;
}
