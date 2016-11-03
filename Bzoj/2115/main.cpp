#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 55000;
const int maxm = 100100;
struct node {
    int v;
    LL da;
    int to;
} e[maxm*2];
int n,m;
int h[maxn],top;
LL xo[maxm*2];
int xonum;
LL sp[maxn];
void addedge(int u,int v,LL w) {
    e[top].v = v;
    e[top].da =w;
    e[top].to = h[u];
    h[u] = top++;
}
void dfs(int u) {
    for(int i = h[u]; ~i ; i = e[i].to) {
        int v = e[i].v;
        LL w = e[i].da;
        if(sp[v]!=-1) xo[xonum++] = sp[v]^sp[u]^w;
        else {
            sp[v] = sp[u]^w;
            dfs(v);
        }
    }
}
void Gauss() {
    int row = 0,col = 63;
    for(; row<xonum&&col>=0; row++,col--) {
        int r = row;
        for(int i = row+1; i<xonum; i++) {
            if((xo[i]>>col)&1) {
                r = i;
            }
        }
        if((xo[r]>>col)&1) {

            swap(xo[r],xo[row]);
            for(int i = 0; i<xonum; i++) {
                if(i!=row && ((xo[i]>>col)&1)) {
                    xo[i] = xo[row]^xo[i];
                }
            }
        } else row --  ;
    }
    LL ans = sp[n];
    for(int i = 0 ; i<row; i++) ans = max(ans,ans^xo[i]);
    printf("%lld",ans);
}
int main() {
    int u,v;
    LL w;
    scanf("%d %d",&n,&m);
    memset(h,-1,sizeof(h));
    top = 0;
    for(int i = 0; i<m; i++) {
        scanf("%d %d %lld",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    xonum = 0;
    memset(sp,-1,sizeof(sp));
    sp[1] = 0;
    dfs(1);
    Gauss();
    return 0;
}
