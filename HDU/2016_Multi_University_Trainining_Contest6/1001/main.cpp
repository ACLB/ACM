#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL Mod = 1000000007;

LL pow(LL n,LL m)
{
    LL ans = 1;

    while(m)
    {
        if(m %2 )
        {
            ans = (ans*n)%Mod;
        }

        n = (n*n)%Mod;

        m>>=1;
    }

    return ans;
}

int main()
{
    int T;

    LL n,m;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%lld %lld",&n,&m);

        LL ans = pow(m,n+1);

        ans = ((ans-1)%Mod+Mod)%Mod;

        LL ant = pow(m-1,Mod-2);

        ans = (ans*ant)%Mod;

        printf("%lld\n",ans);
    }
    return 0;
}
