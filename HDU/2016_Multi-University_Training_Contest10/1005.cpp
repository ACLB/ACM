#include <bits/stdc++.h>
#define rson mid+1,r,st<<1|1
#define lson l,mid,st<<1
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int Max = 220000;
int tr[Max*5];
int n,m;
int ans[Max][2];
void pushd(int st,int l,int r) {
    if(!tr[st]) return ;
    int mid = (l+r)>>1;
    tr[st<<1] = tr[st<<1|1] = tr[st];
    tr[st] =0;
    if( l== mid) {
        ans[mid][0] = min(ans[mid][0],tr[st<<1]);
        ans[mid][1] = max(ans[mid][1],tr[st<<1]);
        tr[st<<1] = 0;
    }
    if(mid+1== r) {
        ans[mid+1][0] = min(ans[mid+1][0],tr[st<<1|1]);
        ans[mid+1][1] = max(ans[mid+1][1],tr[st<<1|1]);
        tr[st<<1|1] = 0;
    }
}
void upd(int l,int r,int st,int L,int R,int d){
    if(l == L &&r == R) {
        if(L== R){
            ans[l][0] = min(d,ans[l][0]);
            ans[l][1] = max(d,ans[l][1]);
        }
        else {
            pushd(st,l,r);
            tr[st] = d;
        }
        return ;
    }
    pushd(st,l,r);
    int mid = (l+r)>>1;
    if(R<=mid) upd(lson,L,R,d);
    else if(L>mid) upd(rson,L,R,d);
    else {
        upd(lson,L,mid,d);
        upd(rson,mid+1,R,d);
    }
}
void qu(int l,int r,int st,int d) {
    if(l == r) return ;
    pushd(st,l,r);
    int mid = (l+r)>>1;
    if(d<=mid) qu(lson,d);
    else qu(rson,d);
}
int w[Max];
int an[Max];
int main() {
    int n,m,l,r;
    while(~scanf("%d %d",&n,&m)){
        n --;
        for(int i =1;i<=n;i++) {
            scanf("%d",&w[i]);
            ans[i][0] = INF; ans[i][1] = 0;
        }
        memset(tr,0,sizeof(tr));
        for(int i =1;i<=m;i++) {
            scanf("%d %d",&l,&r);
            upd(1,n,1,l,r-1,i);
        }
        memset(an,0,sizeof(an));
        for(int i = 1;i<=n;i++) {
            qu(1,n,1,i);
            if(ans[i][0] > ans[i][1]) continue;
            an[ans[i][0]] += w[i]; an[ans[i][1]+1] -=w[i];
        }

        for(int i = 1;i<=m;i++) {
            an[i]+=an[i-1];
            printf("%d\n",an[i]);
        }
        
    }
    return 0;
}
