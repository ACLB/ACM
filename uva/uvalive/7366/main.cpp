#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


const double Pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;

typedef struct Point {
    double x,y;
    Point() {}
    Point(double _x,double _y):x(_x),y(_y) {}
    Point operator - (const Point &a)const {
        return Point(x-a.x,y-a.y);
    }
    double operator * (const Point &a)const {
        return x*a.x+y*a.y;
    }
    double operator ^ (const Point &a) const {
        return x*a.y-y*a.x;
    }
    Point operator *(const double &a) const {
        return Point(x*a,y*a);
    }
    Point operator + (const Point &a) const {
        return Point(x+a.x,y+a.y);
    }
} Vector;

Point p[4];
struct Line {
    Point a,b;
};

int dbcmp(double s ) {
    if(fabs(s)<eps) return 0;
    return s>0?1:-1;
}

Point Ratote(Point a,double angle) {
    return Point(a.x*cos(angle)-a.y*sin(angle),a.x*sin(angle)+a.y*cos(angle));
}

Point GetIntersectionLine(Point P,Vector v,Point Q,Vector w) {
    Vector u  = P - Q;
    double t = (w^u)/(v^w);
    return P+v*t;
}
double Angle (Vector a,Vector b) {
    return acos((a*b)/(sqrt(a*a)*sqrt(b*b)));
}
Point ans,s;
bool ok(double angle) {
    Vector a = p[1]-p[0];
    Vector b = p[2]-p[1];
    a = Ratote(a,angle);
    b = Ratote(b,angle);
    s = GetIntersectionLine(p[0],a,p[1],b);
    double ss =  Angle(s-p[2],p[0]-p[2]);
    //printf("%f %f\n",ss,angle);
    return angle>ss;
}


int main() {
    int T,k;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&k);
        for(int i = 0; i<3; i++) {
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        double l = 0,r = Pi/2;
        r = min(r,Angle(p[1]-p[0],p[2]-p[0]));
        r = min(r,Angle(p[0]-p[1],p[2]-p[1]));
        r = min(r,Angle(p[1]-p[2],p[0]-p[2]));
        while(dbcmp(r-l)>0) {
            double mid = (l+r)/2;
            if(ok(mid)) {
                r = mid;
            } else l = mid;
        }
        printf("%d %.5f %.5f\n",k,s.x,s.y);
    }
    return 0;
}
/*
3
1 0 -1.3 3.4 0.5 1.1 2.3
2 0 0 3 0 0 4
3 3.1 0.2 4.3 0.4 0 0.8
*/
