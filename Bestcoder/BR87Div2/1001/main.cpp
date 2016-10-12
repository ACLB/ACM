#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <stack>
#include <functional>
#include <vector>
#include <algorithm>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
using namespace std;

typedef long long LL;
const int mod = 1e9+7;
const double pi = acos(-1.0);
const double eps = 1e-9;
const double e = exp(1.0);
const int maxn = 1e6+100;
int n,m;
int dp1[maxn];
int dp2[maxn];
int a[maxn],b[maxn];
int vis[maxn];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        for(int i = 0;i<n;i++) scanf("%d",&a[i]);
        for(int i = 0;i<m;i++) scanf("%d",&b[i]);
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<n;i++) {
            dp1[i] = vis[a[i]-1]+1;
            vis[a[i]] = max(dp1[i],vis[a[i]]);
        }
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<m;i++) {
            dp2[i] = vis[b[i]-1]+1;
            vis[b[i]] = max(dp2[i],vis[b[i]]);
        }
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<n;i++) vis[a[i]] = max(dp1[i],vis[a[i]]);
        int ans = 0 ;
        for(int i = 0;i<m;i++) ans = max(ans,min(vis[b[i]] ,dp2[i]));
        printf("%d\n",ans);
    }
    return 0;
}
