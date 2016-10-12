#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

long long dp[12][5000];

int n,m;

bool ok1(int s)
{
    for(int i =0; i<m; i++)
    {
        if(((1<<i)&s))
        {
            if(((1<<(i+1)) & s ))
                i++;
            else return false;
        }
    }
    return true;
}


void dfs(int u,int st,int num1,int num2)
{
    if(st == m)
    {
        dp[u][num1] += dp[u-1][num2];

        return ;
    }
    if(st+1<=m)
    {
        dfs(u,st+1,num1<<1|1,num2<<1);

        dfs(u,st+1,num1<<1,num2<<1|1);
    }
    if(st+2<=m)
    {
        dfs(u,st+2,num1<<2|3,num2<<2|3);
    }

}

int main()
{
    while(~scanf("%d %d",&n,&m) &&(n+m))
    {
        memset(dp,0,sizeof(dp));

        for(int i = 0; i<(1<<m); i++)
        {
            if(ok1(i)) dp[0][i] = 1;
        }

        for(int i = 1; i<n; i++)
        {
            dfs(i,0,0,0);
        }

        cout<<dp[n-1][(1<<m)-1]<<endl;
    }
    return 0;
}
