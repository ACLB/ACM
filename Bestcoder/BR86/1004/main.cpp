#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

const double Pi = acos(-1.0);

const double eps = 1e-8;

typedef long long LL;

const LL mod = 998244353;

const int Max = 55;

int n,m,k,q;

int w[Max];

bool mp[Max][Max];

LL dp[Max][Max][Max][3];

bool ok(int x,int y,int z)
{
    if(abs(w[x]-w[y])<=k && abs(w[x]-w[z])<=k && abs(w[y]-w[z])<=k) return true;

    return false;
}

LL dfs(int x,int y,int z,int op)
{
    if(dp[x][y][z][op] != -1) return dp[x][y][z][op];


    dp[x][y][z][op]  =0;

    if(op == 0 && ok(x,y,z)) dp[x][y][z][op] = 1;

    LL temp = 0;

    for(int i = 1;i<=n;i++)
    {
        if(op == 0 && mp[x][i] )
        {
            temp+=dfs(i,y,z,1);

            temp%=mod;
        }
        else if(op == 1 && mp[y][i])
        {
            temp+=dfs(x,i,z,2);

            temp%=mod;
        }
        else if(op == 2 && mp[z][i] && ok(x,y,i))
        {
            temp+=dfs(x,y,i,0);

            temp%=mod;
        }
    }
    (dp[x][y][z][op]+=temp)%=mod;

    return dp[x][y][z][op];
}

int main()
{
    int T,u,v;

    int x,y,z;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d %d %d",&n,&m,&k,&q);

        for(int i = 1;i<=n;i++) scanf("%d",&w[i]);

        memset(mp,false,sizeof(mp));

        for(int i = 0;i<m;i++)
        {
            scanf("%d %d",&u,&v);

            mp[u][v] = true;
        }

        memset(dp,-1,sizeof(dp));

        while(q--)
        {
            scanf("%d %d %d",&x,&y,&z);

            printf("%I64d\n",dfs(x,y,z,0));
        }
    }

    return 0;
}
