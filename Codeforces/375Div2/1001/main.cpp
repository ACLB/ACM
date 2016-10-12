#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

int main() {
    int n,da;
    int Min  = 1100,Max = 0;
    for(int i = 0;i<3;i++)
    {
        scanf("%d",&da);
        Min = min(Min,da);
        Max = max(da,Max);
    }
    printf("%d\n",Max-Min);
    return 0;
}
