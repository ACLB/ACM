#include <bits/stdc++.h>

using namespace std;
<<<<<<< HEAD
typedef long long LL;
const LL maxn = 1e5+100;
const LL INF = 0x3f3f3f3f;
struct PoLL {
    LL x,y;
    PoLL() {}
    PoLL(LL _x,LL _y):x(_x),y(_y){}
    void Multi2() {
        x*=2; y*=2;
    }
    bool operator == (const PoLL &a)const{
        return x == a.x && y==a.y;
    }
    bool operator < (const PoLL &a)const {
        return x==a.x ? y<a.y:x<a.x;
    }
    PoLL operator - (const PoLL &a)const {
        return PoLL(x-a.x,y-a.y);
    }
    PoLL operator + (const PoLL &a)const {
        return PoLL(x+a.x,y+a.y);
    }
    PoLL operator * (const LL &a)const {
        return PoLL(y*a,x*-a);
    }
    LL operator * (const PoLL &a)const {
        return x*a.x+y*a.y;
    }
    LL operator ^ (const PoLL &a)const {
        return x*a.y-y*a.x;
    }
    PoLL operator / (const LL &a)const {
        return PoLL(x/a,y/a);
    }

};
struct Import{
    PoLL p;
    double d;
    Import(){}
    Import(PoLL _p,double _d):p(_p),d(_d){}
    bool operator < (const Import &a)const {
        return p == a.p?d<a.d:p<a.p;
    }
};

struct Line {
    PoLL p1,p2;
=======
const int maxn = 1e5+100;
struct Point {
    int x,y;
    Point() {}
    Point(int _x,int _y):x(_x),y(_y){}
    void Multi2() {
        x<<=1; y<<=1;
    }
    bool operator < (const Point &a)const {
        return x==a.x ? y<a.y:x<a.x;
    }
    Point operator - (const Point &a)const {
        return Point(x-a.x,y-a.y);
    }
    Point operator + (const Point &a)const {
        return Point(x+a.x,y+a.y);
    }
    Point operator * (const int &a)const {
        return Point(y*a,a*x*-1);
    }
    int operator * (const Point &a)const {
        return x*a.x+y*a.y;
    }
    int operator ^ (const Point &a)const {
        return x*a.y-y*a.x;
    }
    Point operator / (const int &a)const {
        return Point(x/a,y/a);
    }

};
struct Line {
    Point p1,p2;
>>>>>>> 28af7c988148508dbc2d79f31b2e4ff94484b19c
    void Multi2() {
        p1.Multi2();
        p2.Multi2();
    }
    void Swap() {
        if(p1.x>p2.x|| (p1.x == p2.x && p1.y>p2.y)) {
            swap(p1,p2);
        }
    }
<<<<<<< HEAD
    Import GetVeector() {
        PoLL v = p2-p1;
        LL g = __gcd(abs(v.x),abs(v.y));
        v.x/=g;v.y/=g;
        double d;
        if(v.x == 0) d  =INF;
        else if(v.y == 0) d = 0;
        else {
            d = (p2.y*v.x-v.y*p2.x)*1.0/v.x;
        }
        return Import(v,d);
    }
    bool Instraction(PoLL s) {
        if(((p1-s)^(p2-s))==0 &&((p1-s)*(p2-s))<=0) return true;
=======
    Point GetVeector() {
        Point v = p2-p1;
        int g = __gcd(abs(v.x),abs(v.y));
        v.x/=g;v.y/=g;
        return v;
    }
    bool Instraction(Point s) {
        if(((p1-s)^(p2-s)) ==0 && (p1-s)*(p2-s)<=0) return true;
>>>>>>> 28af7c988148508dbc2d79f31b2e4ff94484b19c
        return false;
    }
}Li[3*maxn];

struct Circ {
<<<<<<< HEAD
    LL r;
    PoLL cen;
=======
    int r;
    Point cen;
>>>>>>> 28af7c988148508dbc2d79f31b2e4ff94484b19c
    void Multi() {
        cen.Multi2(); r<<=1;
    }
}c[1550];
vector<Line>vp[maxn*3];
<<<<<<< HEAD
map<Import,vector<Line> >mp;
int main(){
    LL n,m;
    scanf("%I64d %I64d",&n,&m);
    for(LL i = 0;i<n;i++) {
        scanf("%I64d %I64d %I64d %I64d",&Li[i].p1.x,&Li[i].p1.y,&Li[i].p2.x,&Li[i].p2.y);
        Li[i].Multi2();Li[i].Swap();
        Import v = Li[i].GetVeector();
        mp[v].push_back(Li[i]);
    }
    for(LL i = 0;i<m;i++) {
        scanf("%I64d %I64d %I64d",&c[i].cen.x,&c[i].cen.y,&c[i].r);
        c[i].Multi();
    }
    LL ans= 0;
    for(LL i = 0;i<m;i++) {
        for(LL j = i+1;j<m;j++) {
            if(c[i].r != c[j].r) continue;
            if((c[i].cen - c[j].cen)*(c[i].cen - c[j].cen) <= 4*c[i].r *c[i].r) continue;
            Line L ;
            L.p1 = (c[i].cen + c[j].cen)/2;
            PoLL st = (c[i].cen +c[j].cen)/2;
            PoLL v = c[i].cen-L.p1;
            L.p2 = (L.p1+(v * -1));
            L.Swap();
            Import iv = L.GetVeector();
            for(auto x:mp[iv]) {
                if(x.Instraction(st)) ans++;
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
/*
6 3
-68 -85 -31 -16
-68 -85 6 53
-68 -85 43 122
-31 -16 6 53
-31 -16 43 122
6 53 43 122
-137 -48 1
-68 -85 1
1 -122 1
*/
=======
map<Point,vector<Line> >mp;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++) {
        scanf("%d %d %d %d",&Li[i].p1.x,&Li[i].p1.y,&Li[i].p2.x,&Li[i].p2.y);
        Li[i].Multi2();Li[i].Swap();
        Point v = Li[i].GetVeector();
        mp[v].push_back(Li[i]);
    }
    for(int i = 0;i<m;i++) {
        scanf("%d %d %d",&c[i].cen.x,&c[i].cen.y,&c[i].r);
        c[i].Multi();
    }
    int ans= 0;
    for(int i = 0;i<m;i++) {
        for(int j = i+1;j<m;j++) {
            if(c[i].r != c[j].r) continue;
            if((c[i].cen - c[j].cen)*(c[i].cen - c[j].cen) <= 4*c[i].r *c[i].r) continue;
            Point cc = (c[i].cen + c[j].cen)/2;
            Point v = cc-c[i].cen;
            Line L ;
            L.p1 = (cc+(v * -1));
            L.p2 = (cc+(v*1));
            L.Swap();
            v = L.GetVeector();
            for(auto x:mp[v]) {
                if(x.Instraction(cc)) ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
>>>>>>> 28af7c988148508dbc2d79f31b2e4ff94484b19c
