#include <bits/stdc++.h>
using namespace std;
const int maxn = 101000;
struct node {
    double p,sp;
}tr[maxn*6];
int n,m;
void pushup(int st) {
    tr[st].p = (tr[st<<1].p * tr[st<<1|1].p);
    tr[st].sp = tr[st<<1].sp + tr[st<<1|1].sp *tr[st<<1].p;
}
void build(int l,int r,int st) {
    if( l == r) {
        double a,b,p;
        scanf("%lf %lf",&a,&b);
        p = a/b;
        tr[st].p = tr[st].sp = (1-p)/p;
        return ;
    }
    int mid = (l + r) >>1;
    build(l,mid,st<<1);
    build(mid+1,r,st<<1|1);
    pushup(st);
}
void change(int l,int r,int st,int x) {
    if(l == r) {
        double a,b,p ;
        scanf("%lf %lf",&a,&b);
        p = a/b;
        tr[st].p = tr[st].sp = (1-p)/p;
        return ;
    }
    int mid = (l+r)>>1;
    if(x <= mid ) change(l,mid,st<<1,x);
    else change(mid+1,r,st<<1|1,x);
    pushup(st);

}
double  p , sp;
void Query(int l,int r,int st,int L,int R) {
    if(L == l &&R  == r) {
        sp += tr[st].sp * p;
        p  *= tr[st].p;
        return ;
    }
    int mid = (l + r) >>1;
    if(R<=mid) Query(l,mid,st<<1,L,R);
    else if(L>mid) Query(mid+1,r,st<<1|1,L,R);
    else {
        Query(l,mid,st<<1,L,mid);
        Query(mid+1,r,st<<1|1,mid+1,R);
    }
}
int main() {
    scanf("%d %d",&n,&m);
    build(1,n,1);
    int op,l,r;
    while(m--) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d",&l);
            change(1,n,1,l);
        }
        else {
            p = 1;sp = 0;
            scanf("%d %d",&l,&r);
            Query(1,n,1,l,r);
            double ans = 0;
            if(sp < 1e15) ans = (1.0/(sp+1));
            printf("%.10f\n",ans);
        }
    }
    return 0;
}
