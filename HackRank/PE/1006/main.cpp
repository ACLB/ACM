#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int T,n;

LL a[11000];

LL b[11000];

int main()
{
    a[0] = b[0] = 0;

    for(int i = 1;i<=10000;i++)
    {
        a[i] = i*i+a[i-1];

        b[i] = b[i-1]+i;
    }

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        printf("%lld\n",b[n]*b[n]-a[n]);
    }
    return 0;
}
