#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#define LL long long
#define Pr pair<int,int>
#define fread(ch) freopen(ch,"r",stdin)
#define fwrite(ch) freopen(ch,"w",stdout)

using namespace std;
const int INF = 0x3f3f3f3f;
const int msz = 10000;
const int mod = 772002;
const double eps = 1e-8;

int dir[2][9] = {{ 0, 0, 1,-1, 1,-1, 1,-1, 0},
                 { 1,-1, 0, 0, 1,-1,-1, 1, 0}};
char mp[10][10];
bool vis[10][10];
Pr pr[9];
int cnt[1<<9],dp[66][1<<9];
int tp,n,m;

//判断是否越界
bool in(int x,int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

int cal()
{
    tp = 0;

    //找出沟谷
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(mp[i][j] == 'X')
            {
                pr[tp].first = i;
                pr[tp++].second = j;
            }

    //沟谷状压
    int tot = 1<<tp;
    int k;
    memset(cnt,0,sizeof(cnt));

    //统计每个状态下已标记沟谷+可标记山峰数量
    for(int s = 0; s < tot; ++s)
    {
        memset(vis,0,sizeof(vis));
        for(int i = 0; i < tp; ++i)
            if(!(s&(1<<i))) {
                    printf("%d %d\n",pr[i].first,pr[i].second);
                    vis[pr[i].first][pr[i].second] = 1;
            }

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
            {
                for(k = 0; k < 9; ++k)
                    if(in(i+dir[0][k],j+dir[1][k])
                    && vis[i+dir[0][k]][j+dir[1][k]]) break;
                if(k == 9) {
                    cnt[s]++;
                }
            }
    }

    dp[0][0] = 1;

    for(int i = 1; i <= n*m; ++i)
    {
        for(int s = 0; s < tot; ++s)
        {
            dp[i][s] = (dp[i-1][s]*max(cnt[s]-i+1,0))%mod;
            for(int j = 0; j < tp; ++j)
            {
                if(s&(1<<j))
                {
                    dp[i][s] = (dp[i][s]+dp[i-1][s-(1<<j)])%mod;
                }
            }
        }
    }
    return dp[n*m][tot-1];
}

int ans;

//判断初始地图是否合法（沟谷不相邻）
bool can()
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            if(mp[i][j] == '.') continue;
            for(int k = 0; k < 8; ++k)
            {
                if(!in(i+dir[0][k],j+dir[1][k])) continue;
                if(mp[i+dir[0][k]][j+dir[1][k]] == 'X') return false;
            }
        }
    return true;
}

//容斥
void dfs(int x,int y,int cnt)
{
    if(x == n)
    {
        ans = ((ans+cal()*(cnt&1? -1: 1))%mod+mod)%mod;
        return;
    }

    if(y == m)
    {
        dfs(x+1,0,cnt);
        return;
    }

    dfs(x,y+1,cnt);

    //如果是山峰，并且可能被当做沟谷，需排除。
    if(mp[x][y] == '.')
    {
        for(int i = 0; i < 8; ++i)
            if(in(x+dir[0][i],y+dir[1][i])
            && mp[x+dir[0][i]][y+dir[1][i]] == 'X') return;
        mp[x][y] = 'X';
        dfs(x,y+1,cnt+1);
        mp[x][y] = '.';
    }

}

int main()
{
    //fread("");
    //fwrite("");

    int z = 1;
    while(~scanf("%d%d",&n,&m))
    {
        printf("Case #%d: ",z++);

        for(int i = 0; i < n; ++i)
            scanf("%s",mp[i]);

        if(!can())
        {
            puts("0");
            continue;
        }

        ans = 0;
        dfs(0,0,0);
        printf("%d\n",ans);
    }

    return 0;
}
