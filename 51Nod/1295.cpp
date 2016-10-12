#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
using namespace std;
const int Max = 110000;
const int Maxn = 2555000;
const int Log = 16;
int tr[Maxn][2],num[Maxn],root[Max];
bool bt[Log];
int n,m,top,da;
void Insert(int v,int &x,int y) {
    x = ++top;
    for(int i = 0;i<2;i++) 
        tr[x][i] = tr[y][i];
    num[x] = num[y]+1;
    if(!v) return ;
    Insert(v-1,tr[x][bt[v-1]],tr[y][bt[v-1]]);
}
int qu(int v,int x,int y) {
    if(!v) return 0;
    if(num[tr[x][bt[v-1]]] > num[tr[y][bt[v-1]]]) 
        return qu(v-1,tr[x][bt[v-1]],tr[y][bt[v-1]])+(1<<(v-1));
    else 
        return  qu(v-1,tr[x][1-bt[v-1]],tr[y][1-bt[v-1]]);
    return 0;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--){    
        top = 0;
        memset(tr,0,sizeof(tr));
        scanf("%d %d",&n,&m);
        for(int i = 1;i<=n;i++) {
            scanf("%d",&da);
            for(int j = 0;j<Log;j++,da/=2) bt[j] = da % 2;
            Insert(Log,root[i],root[i-1]);
        }
        int l,r;
        for(int i = 1;i<=m;i++) {
            scanf("%d %d %d",&da,&l,&r);
            for(int j = 0;j<Log;j++,da/=2) bt[j] = (1-(da % 2));
            printf("%d\n",qu(Log,root[r],root[l-1]));
        }
    }
    return 0;
}

