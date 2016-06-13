#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    LL n,h,k;

    LL ans = 0;

    LL  data;

    LL sum = 0;

    scanf("%lld %lld %lld",&n,&h,&k);

    for(int i = 0;i<n;i++)
    {
        scanf("%lld",&data);

        if(sum+data>h)
        {
            LL ant = ceil((sum+data-h)*1.0/k);

            ans+=ant;

            sum-=(ant*k);

            if(sum<0) sum = 0;
        }
        sum+=data;
    }

    if(sum)
        ans+=ceil(sum*1.0/k);
    printf("%lld\n",ans);

    return 0;
}
