#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Max = 110000;

int arr[Max];

LL gcd(LL a,LL b)
{
    return b == 0?a:gcd(b,a%b);
}

int main()
{
    int T,n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        LL sum1 = 0,sum2 = 0;

        for(int i = 0;i<n;i++)
        {
            scanf("%d",&arr[i]);

            sum1 += abs(arr[i]);

            sum2 += arr[i]*arr[i];
        }

        LL fm = 4*n;

        LL fz = 4*sum2*n - 4*sum1*sum1;

        LL g = gcd(fm,fz);

        printf("%lld/%lld\n",fz/g,fm/g);
    }

    return 0;
}
