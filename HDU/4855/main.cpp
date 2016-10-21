#include <bits/stdc++.h>
using namespace std;
const int maxn = 220;
const double Pi = acos(-1.0);
const double eps = 1e-13;
struct node {
    double x,y,r;
}circ[maxn];
int n,m;
double ang[maxn*10];
double Getdistances(double x,double y) {return sqrt(x*x+y*y);}
int dbcmp(double s) {
    return s>eps?1:(s<-eps?-1:0);
}
double cal(double Ang) {
    double ans = 0;
    for(int i = 0;i<n;i++) {
        double x = circ[i].x*cos(Ang)+circ[i].y*sin(Ang);
        double y = fabs(circ[i].x*sin(Ang)-circ[i].y*cos(Ang));
        if(dbcmp(y-circ[i].r)<0 && dbcmp(x)>0) {
            ans += 2.0*sqrt(circ[i].r*circ[i].r-y*y);
        }
    }
    return ans;
}
int main(){
    while(~scanf("%d",&n)) {
        for(int i = 0;i<n;i++) scanf("%lf %lf %lf",&circ[i].x,&circ[i].y,&circ[i].r);
        m  =  0;
        ang[m++] = Pi; ang[m++] = -Pi;
        for(int i = 0;i<n;i++) {
            double acen = atan2(circ[i].y,circ[i].x);
            double dist = Getdistances(circ[i].x,circ[i].y);
            double delta = asin(circ[i].r/dist);
            double ang1 = acen-delta , ang2 = acen + delta;
            if(dbcmp(ang1+Pi)<0) ang1+=2*Pi;
            if(dbcmp(ang2-Pi)>0) ang2-=2*Pi;
            ang[m++] = acen;
            ang[m++] = ang1;
            ang[m++] = ang2;
        }
        sort(ang,ang+m);
        m = unique(ang,ang+m)-ang;
        double ans = 0;
        for(int i = 0;i< m - 1;i++) {
            double l = ang[i];
            double r = ang[i+1];
            double ant = 0;
            while(l<=r) {
                double cl = l+(r-l)/3;
                double cr = l+ 2*(r-l)/3;
                double antl = cal(cl);
                double antr = cal(cr);
                if(dbcmp(antl-antr)>=0) {
                    ant = antl;
                    r = cr-eps;
                }
                else {
                    ant = antr;
                    l = cl+eps;
                }
            }
            if(dbcmp(ans-ant)<0) ans = ant;
        }
        printf("%.10f\n",ans);
    }
    return 0;
}
