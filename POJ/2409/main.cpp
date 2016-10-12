#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-10;
double h,v;
double fz[5]= {9800,9878.287,9956.574,10034.86,10113.148};
int dbcmp(double s) {
    if(fabs(s) < eps) return 0;
    return s>0 ?1:-1;
}
double fm() {
    return 0.625*(4-2*h)*v*v;
}
double Getalpha() {
    return (31541.3*h-(double)236561098)/fm();
}
double ash(double x) {
    return log(x + sqrt(x*x+1));
}
double ach(double x) {
    return log(x + sqrt(x*x-1));
}
double arth(double x) {
    return 0.5*log((1+x)/(1-x));
}
double Get() {
    double ans = fm()/7;
    double a = Getalpha();
    return ans*(cosh(ash(154.35/fm()+a))-cosh(ash(a)));
}
double Getans() {
    double ans = h;
    for(int j = 0; j<5; j++) {
        ans +=(cos(atan(fm()/(31541.3*h-fz[j]))));
    }
    ans+=Get();
    return ans;
}
int main() {
    freopen("out.txt","w",stdout);
//    freopen("in.txt","r",stdin);
//    double ans,s;
//    while(~scanf("%lf %lf",&v,&s)) {
//        ans = 0;
//        double l = 0,r = 2;
//        while(dbcmp(r-l)>0) {
//            h = (l+r)/2;
//            double st = Getans();
//            if(dbcmp(st-s)>=0) {
//                ans = h;
//                l= h;
//            }
//            else r = h;
//        }
//        h = ans;
//        printf("when v  = %.10f s = %.10f the h = %.10f s' = %.10f\n",v,s,ans,Getans());
//    }
    v = 12;
    for(h = 0;h<=2;h+=0.001) printf("%f\n",Getans());
    return 0;
}
