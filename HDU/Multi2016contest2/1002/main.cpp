#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL Mod = 1e9+7;

const int Max  = 65540;

LL w[Max],ans;

char op[6];

LL f[256][256],h[Max][256];

int vis[256];

vector<int>E[Max];

void read(LL &a)
{
    char c;
    while(!(((c=getchar())>='0')&&(c<='9')));
    a=c-'0';
    while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';
}
int Ok(int a,int b)
{
    if(op[0] == 'A') return a&b;

    if(op[0] == 'X') return a^b;

    return a|b;
}

void dfs(int u)
{
    LL dp = 0;

    LL a = w[u]>>8;

    LL b = w[u]&255;

    for(int i = 0;i<256;i++)
    {
        if(vis[i])
            dp = max(dp,f[i][b]+(Ok(a,i)<<8));
    }

    ans =(1LL*u*(dp+w[u])+ans)%Mod;

    vis[a]++;

    for(int i = 0;i<256;i++)
    {
        h[u][i] = f[a][i];

        f[a][i] = max(f[a][i],Ok(b,i)+dp);
    }

    for(int i = 0;i<E[u].size() ;i++)
    {
        dfs(E[u][i]);
    }

    vis[a]--;

    for(int i =0; i<256;i++)
    {
        f[a][i] = h[u][i];
    }
}
int main()
{
    int T,n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %s",&n,op);

        for(int i = 1;i<=n;i++) E[i].clear();

        for(int i = 1;i<=n;i++) read(w[i]);

        int x;

        for(int i = 2;i<=n;i++)
        {
            scanf("%d",&x);

            E[x].push_back(i);

        }
        ans = 0;

        memset(vis,0,sizeof(vis));

        dfs(1);

        printf("%lld\n",ans);
    }

    return 0;
}
