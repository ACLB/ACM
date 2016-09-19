#include <bits/stdc++.h>
using namespace std;
int main() {
    double x,y,a,b;
    scanf("%lf %lf %lf %lf",&x,&y,&a,&b);
    double k = (a*x+y*b)/(a*a+b*b);
    double n = -(x-k*a)/b;
    printf("%.12lf\n%.12lf",k,n);
    return 0;
}
