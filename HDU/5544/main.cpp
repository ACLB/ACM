#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 1e5+100;
int n,m,T;
struct node {
    int v,to;
    LL w;
} E[maxn*3];
int H[maxn],top;
LL xo[maxn];
LL cir[maxn],num;
int vis[maxn];
void addedge(int u,int v,LL w) {
    E[top].v = v;
    E[top].w = w;
    E[top].to = H[u];
    H[u] = top++;
}
void dfs(int u,int fa,int dep) {
    vis[u] = dep;
    for(int i = H[u]; ~i; i = E[i].to) {
        int v = E[i].v;
        LL w = E[i].w;
        if(v == fa) continue;
        if(vis[v]!=-1) {
            if(vis[v] <= dep)
                cir[num++] = xo[u]^xo[v]^w;
        } else {
            xo[v] = xo[u] ^ w;
            dfs(v,u,dep+1);
        }
    }
}
void Gauss() {
    int row = 0,col = 61;
    while(col >=0 && row < num) {
        int r = row;
        LL s = 1LL<<col;
        for(; r<num; r++) if(cir[r]&s) break;
        if(r == num) {
            col--;
            continue;
        }
        swap(cir[r],cir[row]);
        for(int i = 0; i<num; i++) if(i!=row && cir[i]&s) cir[i] = cir[i]^cir[row];
        row++;
        col--;
    }
}

int main() {
    int u,v,z = 1;
    LL w;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        memset(H,-1,sizeof(H));
        top = 0;
        for(int i = 0; i<m; i++) {
            scanf("%d %d %lld",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        memset(vis,-1,sizeof(vis));
        xo[1] = 0;
        num =0 ;
        dfs(1,0,0);
        Gauss();
        LL ans = 0;
        for(int i = 0; i<num; i++) ans = max(ans,ans^cir[i]);
        printf("Case #%d: %lld\n",z++,ans);
    }
    return 0;
}
