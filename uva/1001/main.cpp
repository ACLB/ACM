#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL eps = 1e-8;
const int maxn = 200100;

struct Point
{
    LL x,y;
    Point(){}
    Point(LL _x,LL _y):x(_x),y(_y){}
    Point operator -(const Point &a)const {
        return Point(x-a.x,y-a.y);
    }
} P[maxn],convex[maxn];

LL xmult(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}

bool cmpp(Point a,Point b){
    if(a.x !=b.x)
        return a.x<b.x;
    return a.y<b.y;
}

int Graham(int n){
    int m = n;
    sort(P,P+m,cmpp);
    int t = 0;
    for(int i = 0; i < m; ++i){
        while(t > 1 && xmult(convex[t-1]-convex[t-2],P[i]-convex[t-1]) <= 0) t--;
        convex[t++] = P[i];
    }
    int k = t;
    for(int i = m-2; i >=0; --i){
        while(t > k && xmult(convex[t-1]-convex[t-2],P[i]-convex[t-1]) <= 0) t--;
        convex[t++] = P[i];
    }

    if(m > 1) t--;
    return t;
}
int tot;
bool check(Point p) {
    int l = 1,r = tot-2;
    while(l<=r) {
        int mid =(l+r)>>1;
        LL a1 =xmult(convex[mid]-convex[0],p-convex[0]);
        LL a2 =xmult(convex[mid+1]-convex[0],p-convex[0]);
        if(a1>=0&&a2<=0) {
            if(xmult(convex[mid+1]-convex[mid],p-convex[mid]) >= 0 ) return true;
            return false;
        }
        if(a1 < 0) {
            r = mid-1;
        }
        else l = mid+1;
    }
    return false;
}
int main() {
    int n,m;
    while(~scanf("%d",&n)) {
        for(int i =0;i<n;i++) scanf("%lld %lld",&P[i].x,&P[i].y);
        tot = Graham(n);
        scanf("%d",&m);
        Point a;
        int ans = 0;
        for(int i = 0;i<m;i++) {
            scanf("%lld %lld",&a.x,&a.y);
            if(check(a)){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
