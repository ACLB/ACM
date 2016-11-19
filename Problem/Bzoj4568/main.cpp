#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 64;
const int maxm = 21000;
struct Linear_basis {
    LL bas[maxn];
    void Clear() {
        memset(bas,0,sizeof(bas));
    }
    void add(LL x) {
        for(int i = 61;i>=0;i--) {
            if((x>>i)&1) {
                if(bas[i]) x^=bas[i];
                else {
                    bas[i] = x;
                    break;
                }
            }
        }
    }
    Linear_basis operator + (const Linear_basis &a) const {
        Linear_basis temp = a;
        for(int i = 61;i>=0;i--) {
            if(bas[i]) {
                temp.add(bas[i]);
            }
        }
        return temp;
    }
    LL num() {
        LL ans = 0;
        for(int i = 61;i>=0;i--) ans = max(ans,ans^bas[i]);
        return ans;
    }
}val[maxm][17];
vector<LL>mp[maxm];
int dep[maxm];
int fa[maxm][17];
int n,q,x,y;
LL G;
void dfs(int u,int f ){
    if(f) {
        dep[u] = dep[f]+1;
    }
    for(int i = 0;i<mp[u].size();i++) {
        int v = mp[u][i];
        if(v!=f) {
            for(int j = 1,t = u;t;j++) {
                fa[v][j] =t;
                t = fa[t][j];
            }
            if(fa[v][1]) val[v][1] = val[v][0]+val[fa[v][1]][0];
            for(int j = 2;fa[v][j];j++) val[v][j] =  val[v][j-1] + val[fa[v][j-1]][j-1];
            dfs(v,u);
        }
    }
}
Linear_basis find(int x,int y) {
    Linear_basis res; res.Clear();
    res=res+val[x][0];
    res=res+val[y][0];
    if(dep[x]<dep[y]) swap(x,y);
    for(int i = 16;i>=0;i--) {
        if(dep[fa[x][i]] >= dep[y]) {
            res  = res+val[x][i];
            x  = fa[x][i];
        }
    }
    for(int i = 16;i>=0;i--) {
        if(fa[x][i]!=fa[y][i]) {
            res = res+val[x][i];
            res = res+val[y][i];
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x!=y) {
        res = res+val[x][1];
    }
    return res;
}
int main() {
    while(~scanf("%d %d",&n,&q)) {
        memset(fa,0,sizeof(fa));
        for(int i = 1;i<=n;i++) {
            val[i][0].Clear();
            scanf("%lld",&G);
            val[i][0].add(G);
            mp[i].clear();
            fa[i][0] = i;
        }
        for(int i = 1;i<n;i++) {
            scanf("%d %d",&x,&y);
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        dep[1] = 1;
        dfs(1,0);
        for(int i = 1;i<=q;i++) {
            scanf("%d %d",&x,&y);
            printf("%lld\n",find(x,y).num());
        }
    }
    return 0;
}
