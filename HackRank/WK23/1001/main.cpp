#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = 1e4+100;
double a[maxn];
struct node{
    double x,y;
    node(){}
    node(double _x,double _y):x(_x),y(_y){}
    node operator + (const node &b)const  {
        return node(x+b.x,y+b.y);
    }
    node operator * (const double &b) const{
        return node(x*cos(b)-y*sin(b),x*sin(b)+y*cos(b));
    }
}ans[maxn];
int main(){
    int n;
    scanf("%d",&n);
    double r = 0;
    for(int i = 0;i<n;i++) {
        scanf("%lf",&a[i]);
        r+=a[i];
    }
    int mx = 0;
    for(int i = 1;i<n;i++) if(a[i]>a[mx]) mx = i;
    double l = a[mx]/2; r =r/2+1;
    double phi = 0;
    for(int i = 0;i<n;i++) {
            if(i != mx)phi += acos(1-a[i]*a[i]/(2*l*l));
    }
    bool flag = phi<pi;
    while(r-l>eps) {
        double mid = (l+r)/2;
        double phi = 0;
        for(int i = 0;i<n;i++) if(i!=mx) phi += acos(1-a[i]*a[i]/(2*mid*mid));
        double phii = acos(1-a[mx]*a[mx]/(2*mid*mid));
        if(flag) {
            if(phi<phii) l = mid;
            else r = mid;
        }
        else {
            if(phi+phii > 2*pi) l = mid;
            else r = mid;
        }
    }
    r = l;
    ans[0].x = 0; ans[0].y = 0;
    ans[1].x = 0,ans[1].y= a[0];
    node ve,circ;
    if(flag && mx == 0) {
        ve.x = sqrt(r*r-a[0]*a[0]/4);
        ve.y = a[0]/2;
        circ.x = -ve.x; circ.y = a[0]/2;
    }
    else {
        ve.x = -sqrt(r*r-a[0]*a[0]/4);
        ve.y = a[0]/2;
        circ.x = -ve.x; circ.y = ve.y;
    }
    for(int i = 1;i<n;i++) {
        double c = acos(1-a[i]*a[i]/(2*r*r));
        if(flag && i ==mx) c = 2*pi-c;
        c = -c;
        printf("%f\n",c);
        ve = ve*c;
        ans[i+1] = circ+ve;
    }
    for(int i = 0;i<n;i++) printf("%.6f\n%.6f\n\n",ans[i].x,ans[i].y);
    return 0;
}
