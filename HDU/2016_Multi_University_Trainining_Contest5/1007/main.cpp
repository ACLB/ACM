#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL dp[20][11][11][11][11];

int  digt[20],K,len;

bool ok(int p1,int p2,int p3,int p4,int now)
{
    if(K == 2) return p4 != now;

    if(K == 3) return p3 != now && p4 != now;

    if(K == 4) return p2 != now && p3 != now && p4 != now;

    if(K == 5) return p1 != now && p2 != now && p3 != now && p4 != now;
}

LL dfs(int pos,int p1,int p2,int p3,int p4,bool limit)
{
    if(pos ==0) return 1;

    LL & ds = dp[pos][p1][p2][p3][p4];

    if(!limit && ds !=-1) return ds;

    int n = limit ? digt[pos]:9;

    LL res = 0;

    for(int i = 0;i<=n;i++)
    {
        if(p4 == 10 && i == 0)
        {
            res +=dfs(pos-1,p2,p3,p4,10,limit && i == n);
        }
        else if(ok(p1,p2,p3,p4,i))
        {
            res +=dfs(pos-1,p2,p3,p4,i,limit && i==n);
        }
    }

    if(!limit) ds= res;

    return res;
}

LL Cal(LL n)
{
    memset(dp,-1,sizeof(dp));

    len = 0;

    while(n)
    {
        digt[++len] = n%10;

        n/=10;
    }

    return dfs(len,10,10,10,10,1);
}

int main()
{
    LL L,R;

    while(~scanf("%lld %lld %d",&L,&R,&K))
    {
        printf("%lld\n",Cal(R)-Cal(L-1));
    }
    return 0;
}
