#include <bits/stdc++.h>

using namespace std;

double a[110];
double b[110];
int n;
double x ,sigma;
int L,R,op;
void Check() {
    x = 0;
    for(int i = L;i<=R;i++) x+=a[i];
    x/=(R-L+1);
    printf("The x = %f\n",x);
    sigma = 0;
    for(int i = L;i<=R;i++) sigma += (a[i]-x)*(a[i]-x);
    sigma =sqrt(sigma/(R-L));
    printf("The simga is:%f\n",sigma);
    double g = 0;
    op = 0;
    if(fabs(x-a[L]) >fabs(x-a[R])) {
        g = (x-a[L])/sigma;
        op =1;
    }
    else {
        g = (a[R]-L)/sigma;
        op = 2;
    }
    printf("Please input is freedu is %d:\n",(R-L+1));
    double s ;
    scanf("%lf",&s);
    if(g>s) {
        if(op == 1) printf("%d\n",L);
        else printf("%d\n",R);
        if(op == 1) L++;
        else R--;
    }
    else op = 0;
}
int main() {
    while(~scanf("%d",&n)) {
        for(int i = 1;i<=n;i++) scanf("%lf",&a[i]);
        sort(a+1,a+n+1);
        printf("The sort squence is :\n");
        for(int i = 1;i<=n;i++) printf("%f ",a[i]);
        printf("\n");
        L = 1,R = n;
        while(1) {
            Check();
            if(!op) break;
        }
    }
    return 0;   
}
