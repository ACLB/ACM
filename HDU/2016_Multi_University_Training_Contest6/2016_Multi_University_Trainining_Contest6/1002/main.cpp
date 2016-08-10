#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Mod = 110119;

const int Max = 120000;

LL fac[Max],inv[Max],facinv[Max];

typedef struct node
{
    LL x,y;

    node(){}

    node(LL _x,LL _y):x(_x),y(_y){}

    bool operator < (const node &a)const
    {
        return x == a.x ? y<a.y:x<a.x;
    }

    node operator - (const node &a) const
    {
        return node(x-a.x,y-a.y);
    }
}Point;

Point p[110];

void Init()
{
    fac[0] = inv[0] = facinv[0] = 1;

    fac[1] = inv[1] = facinv[1] =1;

    for(int i = 2;i<Max;i++)
    {
        fac[i] = (fac[i-1]*i)%Mod;

        inv[i] = (Mod-Mod/i)*inv[Mod%i]%Mod;

        facinv[i] = (facinv[i-1]*inv[i])%Mod;
    }
}

LL C(LL n, LL m)
{
    if(n<0 || m<0 || n<m) return 0;

    return (((fac[n]*facinv[m])%Mod)*facinv[n-m])%Mod;
}

LL Lucas(LL n,LL m)
{
    if(n<0 || m<0 || n<m) return 0;

    LL ans = 1;

    while(n || m)
    {
        ans  = (ans*C(n%Mod,m%Mod))%Mod;

        n/=Mod;

        m/=Mod;
    }
    return ans;
}

LL dp[110];

int main()
{
    Init();

    LL n,m;

    int r,z =1;
    while(~scanf("%lld %lld %d",&n,&m,&r))
    {
        for(int i = 1;i<=r;i++)
        {
            scanf("%lld %lld",&p[i].x,&p[i].y);
        }

        p[0] = node(1,1);

        p[r+1]  = node(n,m);

        r++;

        sort(p,p+r+1);

        memset(dp,0,sizeof(dp));

        dp[0] = 1;

        for(int i = 1;i<=r;i++)
        {
            for(int j = 0;j<i;j++)
            {
                node s = p[i]-p[j];

                if(s.x <0 || s.y<0 ||(s.x+s.y)%3) continue;

                LL st = (s.x+s.y)/3;

                if(j == 0) dp[i] = ((dp[j]*Lucas(s.x+s.y-st-st,s.x-st))%Mod+Mod)%Mod;

                else dp[i] = ((dp[i]-dp[j]*Lucas(s.x+s.y-st-st,s.x-st))%Mod+Mod)%Mod;
            }
        }
        printf("Case #%d: %lld\n",z++,dp[r]);
    }
    return 0;
}
