#include <bits/stdc++.h>

using namespace std;

const double Pi = acos(-1.0);
int n;
int main() {
    scanf("%d",&n);
    double M1 = cos(0),M2 = cos(0.5);
    double ans = -10;
    for(int i = 2;i<=n;i+=2) {

        ans = max(ans,2*sin(i*1.0/2)*M1+sin(n-i));
        M1 = max(M1,cos(i*1.0/2));
    }
    for(int i = 3;i<=n;i+=2) {
        ans = max(ans,2*sin(i*1.0/2)*M2+sin(n-i));
        M2 = max(M2,cos(i*1.0/2));
    }
    printf("%.9f\n",ans);
    return 0;
}
