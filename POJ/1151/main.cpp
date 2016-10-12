#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
using namespace std;
struct node {
    double x,y1,y2;
    int op;
    bool operator < (const node &a)const {
        return x<a.x;
    }
}p[3000];
struct Tree {
    int c;
    double dis;
}tr[300000];
double a[3000];
int n,m;
void pushup(int l,int r,int st) {
    if(tr[st].c) tr[st].dis = a[r-1] -a[l-1]; 
    else if(r-l == 1) tr[st].dis = 0;
    else tr[st].dis = tr[st<<1].dis + tr[st<<1|1].dis;
}
void build(int l,int r,int st) {
    tr[st].c = 0; tr[st].dis = 0;
    if(r-l <= 1) return ;
    int mid = (l+r)>>1;
    build(l,mid,st<<1);
    build(mid,r,st<<1|1);
    pushup(l,r,st);
}
void update(int l,int r,int st,int L,int R,int op ){
    if(L<=l && r<= R) {
        tr[st].c+=op;
        pushup(l,r,st);
        return ;
    }
    int mid = (l+r)>>1;
    if(L<mid) update(l,mid,st<<1,L,R,op);
    if(R>mid) update(mid,r,st<<1|1,L,R,op);
    pushup(l,r,st);
}
int main() {
    double x1,y1,x2,y2;
    int z = 0;
    while(~scanf("%d",&n)&&n) {
        int num = 0; m = 0;
        for(int i = 0;i<n;i++) {
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            a[num++] = y1;
            a[num++] = y2;
            p[m].x = x1; p[m].y1 = y1; p[m].op = 1; p[m++].y2 = y2;
            p[m].x = x2; p[m].y1 = y1; p[m].op = -1;p[m++].y2 = y2;
        }
        sort(a,a+num);
        sort(p,p+m);
        int s = num; num = 0;
        for(int  i = 1;i<s;i++) if(a[i]!=a[num]) a[++num] = a[i];
        num++;
        build(1,num,1);
        double ans =  0;
        for(int i = 0;i<m-1;i++) {
            int l = lower_bound(a,a+num,p[i].y1)-a+1;
            int r = lower_bound(a,a+num,p[i].y2)-a+1;
            update(1,num,1,l,r,p[i].op);
            ans+=(p[i+1].x - p[i].x)*tr[1].dis;
        }
        printf("Test case #%d\n",++z);
        printf("Total explored area: %.2f\n\n",ans);
    }
    return 0;
}
