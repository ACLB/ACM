#include <bits/stdc++.h>

using namespace std;
double a[110];
double v[110];
int n;
bool flag[110];
bool Judge() {
    double av = 0;
    int m = n;
    for(int i = 0;i<n;i++) {
        if(!flag[i]) av+=a[i];
        else m--;
    }
    av/=m;
    printf("x = %f\n",av);
    double sigma = 0;
    for(int i = 0;i<n;i++) {
        v[i] = a[i]-av;
        if(!flag[i]) {
            sigma +=v[i]*v[i];
            printf("v%d = %f\n",i,v[i]);
        }
    }
    sigma = sqrt(sigma/(m-1));
    printf("sigma = %f\n",sigma);
    bool op = false;
    for(int i = 0;i<n;i++) {
        if(!flag[i]) {
            if(3*sigma<fabs(v[i])) {
                printf("the v%d = %f\n",i,v[i]);
                flag[i] = true;
                op = true;
            }
        }
    }
    return op;
}
int main() {
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    while(~scanf("%d",&n)) {
        memset(flag,false,sizeof(flag));
        for(int i = 0;i<n;i++) {
            scanf("%lf",&a[i]);
            printf("%f ",a[i]);
        }
        printf("\n");
        int z =1;
        while(Judge()) {
            printf("The test%d is end!\n\n",z++);
        }
    }
    return 0;
}
