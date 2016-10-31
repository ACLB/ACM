#include <bits/stdc++.h>

using namespace std;
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
    void Multi2() {
        p1.Multi2();
        p2.Multi2();
    }
    void Swap() {
        if(p1.x>p2.x|| (p1.x == p2.x && p1.y>p2.y)) {
            swap(p1,p2);
        }
    }
    Point GetVeector() {
        Point v = p2-p1;
        int g = __gcd(abs(v.x),abs(v.y));
        v.x/=g;v.y/=g;
        return v;
    }
    bool Instraction(Point s) {
        if(((p1-s)^(p2-s)) ==0 && (p1-s)*(p2-s)<=0) return true;
        return false;
    }
}Li[3*maxn];

struct Circ {
    int r;
    Point cen;
    void Multi() {
        cen.Multi2(); r<<=1;
    }
}c[1550];
vector<Line>vp[maxn*3];
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
