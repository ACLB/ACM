#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const int maxn = 1100;

struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
    bool operator < (const Point &a)const {
        return x==a.x?y<a.y:x<a.x;
    }
    Point operator + (const Point &a) const {
        return Point(x+a.x,y+a.y);
    }
    double operator * (const Point &a) const {
        return (x*a.x+y*a.y);
    }
    Point operator * (const double &a) const {
        return Point(a*x,y*a);
    }
    double operator ^ (const Point &a) const {
        reurn x*a.y-y*a.x;
    }
}a[maxn],b[maxn],tba[maxn],tbb[maxn];
Point ind;
int n,m;
int main() {
    while(~scanf("%d %d",&n,&m)){
        ind = 0;
        for(int i = 0;i<n;i++) {
            scanf("%lf %lf",&a[i].x,&a[i].y);
            if(a[ind].x < a[i].x || (a[ind].x == a[i].x && a[ind].y<a[i].y)) ind = i;
        }
        swap(a[0],a[ind]);
        
    }
    return 0;
}
