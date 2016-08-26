#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
using namespace std;
#define Clear(a,x) memset(a,x,sizeof(a))
typedef long long LL;
const double eps = 1e-8;
const double Pi = acos(-1.0);
const int Max = 11000;
int a[Max],b[Max],n;
int zh[Max][2],top;
bool vis[Max];
void dfs(int u) {
    for(int i = 1;i<=n;i++) {
        if(b[i] == u && !vis[i]) {
            vis[i] = true;
            zh[top][1] ++;
            zh[top][0] = min(zh[top][0],b[i]);
            dfs(a[i]);
        }
    }
}
int main() {
    while(~scanf("%d",&n)){
        int sum = 0;int Mi =(1<<30);
        for(int i = 1;i<=n;i++) {
            scanf("%d",&b[i]);
            sum+=b[i];
            a[i] = b[i];
            Mi = min(Mi,b[i]);
        }
        top = 0;
        sort(a+1,a+n+1);
        memset(vis,false,sizeof(vis));
        for(int i = 1;i <= n;i++) {
            if(vis[i]) continue;
            zh[top][0] = b[i];
            zh[top][1] = 1;
            vis[i] = true;
            dfs(a[i]);
            top++;
        }
        for(int i = 0;i<top;i++) sum+=min(zh[i][0]*(zh[i][1]-2),Mi*(zh[i][1]+1)+zh[i][0]);
        printf("%d\n",sum);
    }
    return 0;
}
