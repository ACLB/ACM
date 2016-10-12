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

int X,Y,Z;

int x[2],y[2],z[2];
int main() {
    scanf("%d %d %d",&X,&Y,&Z);
    scanf("%d %d %d",&x[0],&y[0],&z[0]);
    x[0]-=X;
    y[0]-=Y;
    z[0]-=Z;
    scanf("%d %d %d",&x[1],&y[1],&z[1]);
    x[1]-=X;
    y[1]-=Y;
    z[1]-=Z;
    LL ans = 0;
    if(x[0]*x[1]>0) ans +=(min(x[0]*x[0],x[1]*x[1]));
    if(y[0]*y[1]>0) ans +=(min(y[0]*y[0],y[1]*y[1]));

    if(z[0]*z[1]>0) ans +=(min(z[0]*z[0],z[1]*z[1]));
    printf("%lld\n",ans);

    return 0;
}
/*
0 0 0
1 1 1
2 2 2
1 1 1
0 0 0
2 2 2
*/
