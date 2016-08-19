#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int Max = 1000100;
LL c[Max][4];
void Init(){
    c[0][0] = 1;
    for(int i =1;i<Max;i++) {
        c[i][0] =1;
        for(int j = 1;j<=3;j++) {
            c[i][j] = c[i-1][j]+c[i-1][j-1];
        }
    }
}
LL C(LL n,LL m) {
    if(m>n) return 0;
    return c[n][m];
}
int n,m;
int main()
{
    Init();
    while(~scanf("%d %d",&n,&m)) {
        n++,m++;
        LL ans = C(n*m,3); ans = ans-C(n,3)*m-C(m,3)*n;
        for(int i = 1;i<n;i++) {
            for(int j = 1;j<m;j++) {
                int g = __gcd(i,j)+1;
                ans-=((g-2)*(n-i)*(m-j)*2);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
