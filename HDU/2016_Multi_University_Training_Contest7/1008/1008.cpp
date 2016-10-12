#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Max = 1<<21;

LL fac[30];

LL dp[Max];

int p[30];

int T;

int n,m,ph;

int num1 ,num2;

bool ok(int s)
{
    num1 = 0,num2 = 0;
    
    for(int i = 0;i<m;i++) if(s&(1<<i)) num1++;

    for(int i = 0;i<n;i++) if(s&(1<<(i+m))) num2++;

    return num2-num1+1>=0;

}


int count(int s)
{
    int ans =0 ;

    for(int i =0;i<m;i++) if(s&(1<<i)) ans+=p[i];

    return ans;
}
void Init()
{
    fac[0] =1;

    for(int i = 1;i<=21;i++) fac[i]=fac[i-1]*i;
}

int main()
{
    scanf("%d",&T);

    Init();

    while(T--)
    {
        scanf("%d %d %d",&ph,&n,&m);

        for(int i =0;i<m;i++) scanf("%d",&p[i]);

        memset(dp,0,sizeof(dp));

        dp[0] = 1;

        LL sum = 0;

        for(int i =0;i<(1<<(n+m));i++)
        {
            if(!dp[i] || !ok(i)) continue;

            int ans = count(i);

            if(ans>=ph)
            {
                sum+=dp[i]*fac[n+m-num1-num2];

                continue;
            }

            if(num2-num1+1==0)continue;

            for(int j = 0;j<n+m;j++)
            {
                if(i&(1<<j)) continue;

                dp[i^(1<<j)]+=dp[i];
            }
        }

        LL g = __gcd(sum,fac[n+m]);

        printf("%lld/%lld\n",sum/g,fac[n+m]/g);

    }
    return 0;
}
