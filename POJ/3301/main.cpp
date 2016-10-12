#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)

using namespace std;

typedef long long LL;
const double Pi = acos(-1.0);
const double eps = 1e-10;
const int INF = 0x3f3f3f3f;

struct node {
    double x,y;
}p[50];
int n;
double ok(double a) {
    double Minx = INF,Maxx = -INF,Miny = INF,Maxy = -INF;
    for(int i = 0;i<n;i++) {
        double x = p[i].x * cos(a) - p[i].y * sin(a);
        double y = p[i].y * cos(a) + p[i].x * sin(a);
        Minx = min(Minx,x); Miny = min(Miny,y);
        Maxx = max(Maxx,x); Maxy = max(Maxy,y);
    }
    return (Maxx - Minx)>(Maxy - Miny)?(Maxx-Minx):(Maxy-Miny);
}

int main() {
    int T;
    double ans;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i = 0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        double l = 0,r = Pi/2;
        ans = 0;
        while((r-l)>eps) {
            double mid2 = (l+r)/2;
            double mid1 = (mid2+l)/2;
            double ans1 = ok(mid1);
            double ans2 = ok(mid2);
            if(ans1<=ans2) r = mid2;
            else l = mid1;
            ans = min(ans1,ans2);          
        }
        printf("%.2f\n",ans*ans);
    }
    return 0;
}
