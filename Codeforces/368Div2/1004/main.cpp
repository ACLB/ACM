#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
using namespace std;
typedef long long LL;
const double Pi = acos(-1.0);
const double e = exp(1);
const int Max = 1e5+100;
vector<int>vi[Max];
int a[Max],b[Max];
int op[Max],ans[Max];
bitset<1001>bi[1100];
bitset<1001>C;
void dfs(int u) {
    if(u == 0) {
        for(int i = 0;i<vi[u].size();i++) {
            ans[vi[u][i]] = ans[u];
            dfs(vi[u][i]);
        }
        return ;
    }
    if(op[u] == 1) {
        bool flag = false;
        if(!bi[a[u]][b[u]]) {
            ans[u]++; flag = true;
            bi[a[u]][b[u]] = 1;
        }
        for(int i = 0; i<vi[u].size();i++) {
            ans[vi[u][i]] = ans[u];
            dfs(vi[u][i]);
        }
        if(flag) bi[a[u]][b[u]] = 0;
    }
    if(op[u] == 2) {
        bool flag = false;
        if(bi[a[u]][b[u]]) {
            ans[u]--; flag = true;
            bi[a[u]][b[u]] = 0;
        }
        for(int i = 0;i<vi[u].size();i++) {
            ans[vi[u][i]] = ans[u];
            dfs(vi[u][i]);
        }
        if(flag) bi[a[u]][b[u]] = 1;
    }
    if(op[u] == 3) {
        ans[u]-=bi[a[u]].count();
        bi[a[u]] ^=C;
        ans[u]+=bi[a[u]].count();
        for(int i = 0;i<vi[u].size();i++) {
            ans[vi[u][i]] = ans[u];
            dfs(vi[u][i]);
        }
        bi[a[u]] ^=C;
    }
    if(op[u] == 4) {
        for(int i = 0;i<vi[u].size();i++) {
            ans[vi[u][i]] = ans[u];
            dfs(vi[u][i]);
        }
    }
}
int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i = 1;i<=m;i++) C[i] = 1;
    for(int i = 1;i<=q;i++) {
        scanf("%d",&op[i]);
        if(op[i] == 1 || op[i] == 2) {
            scanf("%d %d",&a[i],&b[i]);
        }
        else if(op[i] == 3 || op[i] == 4) {
            scanf("%d",&a[i]);
        }
        if(op[i] == 4) {
            vi[a[i]].push_back(i);
        }
        else vi[i-1].push_back(i);
    }
    dfs(0);
    for(int i = 1;i<= q;i++ ) printf("%d\n",ans[i]);
    return 0;
}
