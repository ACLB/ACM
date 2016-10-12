#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 41000;

struct node {

    int sum,maxn,minn;
    int op,lazy;
    int lson,rson;
    void Clear() {
        sum = 0; maxn = 0; minn = INF;
        op = lazy = 0;
    }
    node operator + (const node &a)const {
        node ans;
        ans.Clear();
        ans.sum = sum+a.sum;
        ans.minn = min(minn,a.minn);
        ans.maxn = max(maxn,a.maxn);
        return ans;
    }
}tr[42][MAX*5];

void pushup(int index,int st) {
    tr[index][st].sum = tr[index][st<<1].sum+tr[index][st<<1|1].sum;
    tr[index][st].minn = min(tr[index][st<<1].minn,tr[index][st<<1|1].minn);
    tr[index][st].maxn = max(tr[index][st<<1].maxn,tr[index][st<<1|1].maxn);
}

void pushdown1(node &a ,node &b) {
    b.sum +=(b.rson - b.lson+1)*a.lazy;
    b.maxn += a.lazy;
    b.minn += a.lazy;
    b.op = b.op == 2?2:1;
    b.lazy += a.lazy;
}
void pushdown2(node &a,node &b) {
    b.sum = (b.rson - b.lson +1)*a.lazy;
    b.maxn = b.minn = a.lazy;
    b.op = 2;
    b.lazy = a.lazy;
}
void pushdown(int index,int st) {
    if(tr[index][st].lson == tr[index][st].rson || tr[index][st].op == 0) return ;
    if(tr[index][st].op == 1) {
        pushdown1(tr[index][st],tr[index][st<<1]);
        pushdown1(tr[index][st],tr[index][st<<1|1]);
    }
    else {
        pushdown2(tr[index][st],tr[index][st<<1]);
        pushdown2(tr[index][st],tr[index][st<<1|1]);
    }
    tr[index][st].lazy = tr[index][st].op = 0;
}

void Build(int index,int L,int R,int st) {
    tr[index][st].lson = L;
    tr[index][st].rson = R;
    tr[index][st].op = tr[index][st].lazy = 0;
    if(L == R) {
        tr[index][st].maxn = tr[index][st].sum = 0;
        tr[index][st].minn = 0;
        return ;
    }
    int mid = (L+R)>>1;
    Build(index,L,mid,st<<1);
    Build(index,mid+1,R,st<<1|1);
    pushup(index,st);
}

void Update(int index,int st,int l,int r,int val,int op) {
    pushdown(index,st);
    if(l == tr[index][st].lson && r == tr[index][st].rson) {
        if(op == 1) {
            tr[index][st].sum += (r-l+1)*val;
            tr[index][st].minn += val;
            tr[index][st].maxn += val;
            tr[index][st].op = tr[index][st].op==2?2:1;
            tr[index][st].lazy += val;
        }
        else {
            tr[index][st].sum =  (r-l+1)*val;
            tr[index][st].maxn = tr[index][st].minn = val;
            tr[index][st].op = op;
            tr[index][st].lazy = val;
        }
        return ;
    }
    int mid = (tr[index][st].lson+tr[index][st].rson)>>1;
    if(r<=mid) Update(index,st<<1,l,r,val,op);
    else if(l>mid) Update(index,st<<1|1,l,r,val,op);
    else {
        Update(index,st<<1,l,mid,val,op);
        Update(index,st<<1|1,mid+1,r,val,op);
    }
    pushup(index,st);
}

node Query(int index,int st,int l,int r) {
    pushdown(index,st);
    node ans; ans.Clear();
    if(l == tr[index][st].lson && tr[index][st].rson == r) return tr[index][st];
    int mid = (tr[index][st].lson + tr[index][st].rson ) >>1;
    if(r<=mid) ans = ans + Query(index,st<<1,l,r);
    else if(l>mid)  ans = ans + Query(index,st<<1|1,l,r);
    else {
        ans = ans + Query(index,st<<1,l,mid);
        ans = ans + Query(index,st<<1|1,mid+1,r);
    }
    pushup(index,st);
    return ans;
}

int main() {
    int n,m,q,op,x1,y1,x2,y2,v;
    while(~scanf("%d %d %d",&n,&m,&q)) {
        for(int i = 1; i <= n; i++) Build(i,1,m,1);
        while(q--) {
            scanf("%d %d %d %d %d",&op,&x1,&y1,&x2,&y2);
            if(op!=3) {
                scanf("%d",&v);
                for(int i = x1;i<=x2;i++) Update(i,1,y1,y2,v,op);
            }
            else {
                node ans; ans.Clear();
                for(int i = x1;i<=x2;i++) ans =ans +  Query(i,1,y1,y2);
                printf("%d %d %d\n",ans.sum,ans.minn,ans.maxn);
            }
        }
    }
    return 0;
}
/*
input:
4 4 8
1 1 2 4 4 5
3 2 1 4 4
1 1 1 3 4 2
3 1 2 4 4
3 1 1 3 4
2 2 1 4 4 2
3 1 2 4 4
1 1 1 4 3 3
output:
45 0 5
78 5 7
69 2 7
39 2 7
*/
