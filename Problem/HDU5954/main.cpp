#include <bits/stdc++.h>

using namespace std;
const double Pi = acos(-1.0);
const double eps = 1e-9;
int n;
double d,V;
int dbcmp(double s) {
    if(fabs(s) <=eps) return 0; 
    return s>0?1:-1;
}
void GetV(double theta) {
    
    return 
}
double Get() {
    double l = 0,r = Pi/2;
    double ans;
    while(dbcmp(r-l)>0) {
        double mid = (l+r)/2;
        double v = GetV(mid) ;
        if(v<V) {
            r = v;  
        }
        else {
            ans = mid;
            l = mid;
        }
    }
    return ans;
}
int main() {
    scanf("%d",&n);
    for(int i =0 ;i<n;i++) {
        scanf("%lf",&d);
        if(dbcmp(d,0) ==0) {
            printf("%.5f\n",0);
            continue;
        }
        else if(dbcmp(d,1)>0){
            double theta = atan(2-d);
            double ans = Pi/cos(theta);
            printf("%.5f\n",ans);
            continue;
        }
        
    }
    return 0;
}
