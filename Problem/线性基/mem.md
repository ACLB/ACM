## 线性基
#### Codeforces 587E 线段树+线性基
```
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;
struct node {
    int bas[30],lazy,st;
    void init() {
        memset(bas,0,sizeof(bas));
        lazy = 0;st = 0;
    }
    int Count() {
        int ans = 0;
        for(int i = 0;i<=29;i++) {
            if(bas[i]) ans++;
        }
        return ans;
    }
    void add(int x) {
        for(int i = 29;i>=0;i--) {
            if((x>>i)&1){
                if(bas[i])x^=bas[i];
                else {
                    bas[i] = x;
                    break;
                }
            }
        }
    }
    node operator + (const node &a) const{
        node ans;  ans.init();
        for(int i = 0;i<=29;i++) {
            ans.add(bas[i]);
            ans.add(a.bas[i]);
        }
        ans.add(st^a.st);
        ans.st = a.st;
        return ans;
    }
}tr[8*maxn],ans;
int n,q;
void pushdown(int st) {
    if(tr[st].lazy) {
        tr[st<<1].lazy ^= tr[st].lazy;
        tr[st<<1].st ^= tr[st].lazy;
        tr[st<<1|1].lazy ^= tr[st].lazy;
        tr[st<<1|1].st ^= tr[st].lazy;
        tr[st].lazy = 0;
    }
}
void build(int l,int r,int st) {
    tr[st].init();
    if(l == r) {
        scanf("%d",&tr[st].st);
        return ;
    }
    int mid = (l+r)>>1;
    build(l,mid,st<<1);
    build(mid+1,r,st<<1|1);
    tr[st] = tr[st<<1] + tr[st<<1|1];
}
void update(int l,int r,int st,int L,int R,int d) {
    if(l>=L && r<=R) {
        tr[st].lazy ^= d;
        tr[st].st ^= d;
        return ;
    }
    pushdown(st);
    int mid = (l+r) >>1;
    if(L<=mid) update(l,mid,st<<1,L,R,d);
    if(R> mid) update(mid+1,r,st<<1|1,L,R,d);
    tr[st] = tr[st<<1] + tr[st<<1|1];
}
void Query(int l,int r,int st,int L,int R) {
    if(l >= L && r <= R) {
        ans = ans + tr[st];
        return ;
    }
    pushdown(st);
    int mid = (l+r) >>1;
    if(L<=mid) Query(l,mid,st<<1,L,R);
    if(R>mid)  Query(mid+1,r,st<<1|1,L,R);
    tr[st] = tr[st<<1] + tr[st<<1|1];
}
int main() {
    int op,l,r,d;
    scanf("%d %d",&n,&q);
    build(1,n,1);
    while(q--) {
        scanf("%d %d %d",&op,&l,&r);
        if(op == 1) {
            scanf("%d",&d);
            update(1,n,1,l,r,d);
        }
        else {
            ans.init();
            Query(1,n,1,l,r);
            printf("%d\n",1<<ans.Count());
        }
    }
    return 0;
}

```
#### Bzoj 4184 线段树+时间分治+线性基
#### Bzoj 4296 线性基
#### Bzoj 4568 LCA+线性基
#### Bzoj 2115 线性基
#### Bzoj 2844 线性基
#### Bzoj 2011 线性基
#### Bzoj 2460 线性基+贪心
#### Bzoj 3105 动态维护线性基
#### HDU 3949 XOR线性基

