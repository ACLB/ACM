#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <queue>
#include <algorithm>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)

using namespace std;
typedef long long LL;
const int Mod = 1e9+7;
const double Pi = acos(-1.0);
const double eps = 1e-8;
double ans[5];
int main() {
    int T,z = 1;
    double n,m,c,t;
    scanf("%d",&T);
    while(T--) {
        scanf("%lf %lf %lf %lf",&m,&n,&t,&c);
        ans[0] = t*t*n*m;
        ans[1] = (t-c/2)*(t-c/2)*4+(t-c/2)*(t-c)*(n+m-4)*2+(t-c)*(t-c)*(n*m-(2*(n+m)-4));
        ans[2] = (c*(t-c/2)*((m-1)*2+(n-1)*2))+c*(t-c)*((m-1)*n+(n-1)*m - (m-1)*2-(n-1)*2);
        ans[3] = (c*c-Pi*(c/2)*(c/2))*(n-1)*(m-1);
        ans[4] = (Pi*c*c/4)*(n-1)*(m-1); 
        printf("Case %d:\n",z++);
        for(int i = 1;i<=4;i++) {
            if(i == 1) printf("Probability of covering %d tile  = %.4f%%\n",i,ans[i]/ans[0]*100);
            else printf("Probability of covering %d tiles = %.4f%%\n",i,ans[i]/ans[0]*100);
        }
        printf("\n");
    }
    return 0;
}
