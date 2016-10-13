#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+100l;
LL a[maxn*2],sum[maxn*2];
LL Tr[maxn*10][2];
 int T,n,m,k;
void pushup(int st) { Tr[st][0] = max(Tr[st<<1][0],Tr[st<<1|1][0]);}

void pushdown(int st) {
    Tr[st<<1][1]   += Tr[st][1];
    Tr[st<<1][0]   += Tr[st][1];
    Tr[st<<1|1][1] += Tr[st][1];
    Tr[st<<1|1][0] += Tr[st][1];
    Tr[st][1] = 0;
}

void build(int L,int R,int st) {
    Tr[st][0] = -INF;
    Tr[st][1] = 0;
    if(L ==R) {
        Tr[st][0] = sum[L+k-1]-sum[L-1];
        return ;
    }
    int mid = (L+R) >>1;
    build(L,mid,st<<1);
    build(mid+1,R,st<<1|1);
    pushup(st);
}

LL Query(int L,int R,int st,int l,int r) {
    if(L >= l && R <= r) return Tr[st][0];
    pushdown(st);
    LL ans = -INF;
    int mid = (L+R)>>1;
    if(l<=mid) ans = max(ans,Query(L,mid,st<<1,l,r));
    if(r>mid) ans = max(ans,Query(mid+1,R,st<<1|1,l,r));
    pushup(st);
    return ans;
}
void Update(int L,int R,int st,int l,int r,int d){
    if(L >= l && R <= r) {
        Tr[st][0] += d;
        Tr[st][1] += d;
        return ;
    }
    pushdown(st);
    int mid = (L+R) >>1;
    if(l<=mid) Update(L,mid,st<<1,l,r,d);
    if(r>mid) Update(mid+1,R,st<<1|1,l,r,d);
    pushup(st);
}
int main() {
    int op,x,y,l,r;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&n,&m,&k);
        sum[0] = 0;
        for(int i = 1;i<=n;i++) scanf("%lld",&a[i]),sum[i] = sum[i-1]+a[i];
        int nn = n-k+1;
        build(1,nn,1);
        for(int i = 0;i<m;i++) {
            scanf("%d %d %d",&op,&x,&y);
            if(op == 0) {
                l = max(x-k+1,1);
                r = min(x,nn);
                Update(1,nn,1,l,r,y-a[x]);
                a[x] = y;
            }
            else if(op == 1) {
                l = max(x-k+1,1);
                r = min(x,nn);
                Update(1,nn,1,l,r,a[y]-a[x]);
                l = max(y-k+1,1);
                r = min(y,nn);
                Update(1,nn,1,l,r,a[x]-a[y]);
                swap(a[x],a[y]);
            }
            else if(op == 2) {
                l = x;
                r = y-k+1;
                printf("%lld\n",Query(1,nn,1,l,r));
            }
        }
    }
    return 0;
}
/*
1
5 7 3
-1 2 -4 6 1
2 1 5
2 1 3
1 2 1
2 1 5
2 1 4
0 2 4
2 1 5
4
-3
3
1
6
*/
