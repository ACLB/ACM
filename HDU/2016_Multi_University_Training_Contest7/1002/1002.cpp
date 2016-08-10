#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    LL n,m;

    while(~scanf("%lld %lld",&n,&m) &&(n||m))
    {
        LL fz = n*(m-1);

        LL fm = m*m;

        LL g =__gcd(fz,fm);

        printf("%lld/%lld\n",fz/g,fm/g);
    }
    return 0;
}
