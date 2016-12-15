#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+100;
const int mod = 1e9+7;
struct node {
    int lazy;
    int num[26];
    void Clear() {
        lazy = 0;
        memset(num,0,sizeof(num));
    }
}tr[maxn*5];
char str[maxn];
int Pow[maxn];
int suffix[30],prefix[30],odd[30],even[30];
int n,q;
node  ans;
void pushup(int st) {
    for(int i = 0;i<26;i++) tr[st].num[i] = tr[st<<1].num[i]+tr[st<<1|1].num[i];
}
void build(int L,int R,int st) {
    tr[st].Clear();
    if(L==R) {
        tr[st].num[str[L-1] - 'a']++;
        return ;
    }
    int mid = (L+R) >>1;
    build(L,mid,st<<1);
    build(mid+1,R,st<<1|1);
    pushup(st);
}
node Rotate(node a,int b) {
    node ans; ans.Clear();
    ans.lazy = a.lazy;
    for(int i = 0;i<26;i++) ans.num[(i+b)%26] = a.num[i];
    return ans;
}
void pushdown(int L,int R,int st) {
    if(L==R || tr[st].lazy == 0) return ;
    tr[st<<1].lazy = (tr[st<<1].lazy+tr[st].lazy)%26;
    tr[st<<1|1].lazy =(tr[st<<1|1].lazy+tr[st].lazy)%26;
    tr[st<<1] = Rotate(tr[st<<1],tr[st].lazy);
    tr[st<<1|1] = Rotate(tr[st<<1|1],tr[st].lazy);
    tr[st].lazy = 0;
}
void Update(int L,int R,int st,int l,int r,int tm) {
    if(l<=L && R<=r) {
        tr[st].lazy = (tr[st].lazy+tm)%26;
        tr[st] = Rotate(tr[st],tm);
        return ;
    }
    pushdown(L,R,st);
    int mid = (L+R) >>1;
    if(l<=mid) Update(L,mid,st<<1,l,r,tm);
    if(r> mid) Update(mid+1,R,st<<1|1,l,r,tm);
    pushup(st);
}
void Query(int L,int R,int st,int l,int r) {
    if(l<=L && R<=r) {
        for(int i = 0;i<26;i++) ans.num[i] = ans.num[i]+tr[st].num[i];
        return ;
    }
    pushdown(L,R,st);
    int mid = (L+R)>>1;
    if(l<=mid) Query(L,mid,st<<1,l,r);
    if(r>mid)  Query(mid+1,R,st<<1|1,l,r);
    pushup(st);
}
int Count() {
    int ant = 1;
    for(int i = 0;i<26;i++) {
        if(ans.num[i] ==0) {
            odd[i] = 0;
            even[i] = 1;
        }
        else {
            odd[i]  = Pow[ans.num[i]-1];
            even[i] = Pow[ans.num[i]-1];
        }
    }
    prefix[0] = even[0];
    for(int i = 1;i<26;i++) prefix[i] = (prefix[i-1]*1LL*even[i])%mod;
    suffix[25] = even[25];
    for(int i = 24;i>=0;i--) suffix[i] = (suffix[i+1]*1LL*even[i])%mod;
    ant = prefix[25];
    for(int i = 0;i<26;i++) {
        int cur = ((i == 0?1:prefix[i-1])*1LL*(i==25?1:suffix[i+1]))%mod;
        cur = (cur*1LL*odd[i])%mod;
        ant = (ant+cur)%mod;
    }
    return (ant-1+mod)%mod;
}
int main() {
    scanf("%d %d",&n,&q);
    int op,l,r,tm;
    Pow[0] = 1;
    for(int i = 1;i<maxn;i++) Pow[i] = (Pow[i-1]<<1)%mod;
    scanf("%s",str);
    build(1,n,1);
    while(q--) {
        scanf("%d %d %d",&op,&l,&r);
        if(op == 1) scanf("%d",&tm);
        l++,r++;
        if(op == 1) {
            Update(1,n,1,l,r,tm%26);
        }
        else {
            ans.Clear();
            Query(1,n,1,l,r);
            printf("%d\n",Count());
        }
    }
    return 0;
}
