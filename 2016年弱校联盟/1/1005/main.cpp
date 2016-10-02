#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);

int main() {
    LL a1,a2,a3;
    LL ans = 0;
    scanf("%lld %lld
          %lld",&a1,&a2,&a3);
    if(a1 && a2 && a3) ans = a1+2*a2+3*a3;
    else if(a1 && a2) ans = a1+2*a2;
    else if(a1 && a3) {
        if(a1 == 1) ans = 2*a3+a1;
        else ans = 3*a3+a1;
    } else if(a2&& a3) {
        if(a2 == 1) ans = 2*a3+a2;
        else ans = 2*a2*3*a3-2;
    } else ans = a1+a2+a3;
    printf("%lld\n",ans);
    return 0;
}
/*
1 0 1
0 0 0
*/
