#include <bits/stdc++.h>
#define ww(x) freopen(x,"w",stdout)
#define rr(x) freopen(x,"r",stdin)
using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double Pi = acos(-1.0);
const int Max = 1e6+100;
int pre[Max];
struct node {
    int x1,y1,x2,y2;
    int Id;
    bool operator < (const node &a) const {
        return x1 == a.x1?y1>a.y1:x1<a.x1;
    }
}a[Max];
int Find(int x) {return pre[x] == -1?x:pre[x] = Find(pre[x]);}
double ok(int x,int y) {
    double x1 = a[y].x2-a[y].x1;
    double y1 = a[y].y2-a[y].y1;
    double s =fabs((a[x].x1-a[y].x1)/x1);
    return y1 = s*y1+a[y].y1;
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0 ;i<n;i++) {
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        if(a[i].y1>a[i].y2) {
            swap(a[i].x1,a[i].x2);
            swap(a[i].y1,a[i].y2);
        }
    }
    memset(pre,-1,sizeof(pre));
    for(int i = 0;i<n;i++) {
        double s = -Max;
        int In = -1;
        for(int j =0;j<n;j++) {
            if(i ==j) continue;
            double t = (ok(i,j));
            if(t<a[i].y1 && a[i].x1 >=min(a[j].x1,a[j].x2) && a[i].x1<=max(a[j].x2,a[j].x1)) {
                if(s<t) {
                    s= t;
                    In = j;
                }
            }    
        }
        if(In!=-1) pre[i] = In;
    }
    for(int i = 0;i<m;i++) {
        scanf("%d %d",&a[n].x1,&a[n].y1);
        double s = -Max;
        int In = -1;
        for(int j = 0;j<n;j++) {
            double t = ok(n,j);
            if(t<a[n].y1 && a[n].x1 >=min(a[j].x1,a[j].x2) && a[n].x1<=max(a[j].x2,a[j].x1)) {
                if(s<t) {
                    s = t;
                    In = j;
                }
            }
        }
        if(In!=-1) {
            In  = Find(In);
            printf("%d\n",a[In].x1);
        }
        else printf("%d\n",a[n].x1);
    }
    return 0;
}

