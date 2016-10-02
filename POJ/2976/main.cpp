#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)

using namespace std;

const int Max = 1100;
const double eps = 1e-8;
const double Pi = acos(-1.0);
int n,k;
double x;
struct node {
    int a,b;
    bool operator< (const node &c) {
        return a-x*b > c.a - x*c.b;
    }
}c[Max];

bool ok(double s) {
    x = s;
    sort(c,c+n);
    double suma = 0,sumb = 0 ;
    for(int i = 0;i<n-k;i++) {
        suma+=c[i].a;
        sumb+=c[i].b;
    }
    return (suma/sumb)>x;
}

int main() {
    while(~scanf("%d %d",&n,&k) && (n||k)) {
        for(int i = 0;i<n;i++) scanf("%d",&c[i].a);
        for(int i = 0;i<n;i++) scanf("%d",&c[i].b);
        double l = 0, r = 1;
        double ans = 0;
        while((r-l)>eps) {
            double mid = (l+r)/2;
            if(ok(mid)) {
                ans = mid;
                l = mid;
            }
            else r = mid;
        }
        printf("%.0f\n",ans*100);
    }
    return 0;
}
