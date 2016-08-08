#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

char s[110][110];

bool vis[550][550];

int mp[110][110];

bool Y[550];

int pre[550];

int n,m;

int num;

bool Ok(int x,int y)
{
    if(x>=0 && x<n &&y>=0 &&y<m) return true;

    return false;
}

int dfs(int u)
{
    for(int i = 1;i<num;i++)
    {
        if(vis[u][i] && !Y[i])
        {
            
            Y[i] = true;

            if(pre[i] ==0 || dfs(pre[i]))
            {
                pre[i] = u;

                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        num = 1;

        memset(vis,false,sizeof(vis));

        memset(mp,0,sizeof(mp));

        scanf("%d %d",&n,&m);

        for(int i = 0;i<n;i++)
        {
            scanf("%s",s[i]);

            for(int j =0 ;j<m;j++)
            {
                if(s[i][j] == '*')
                {
                    mp[i][j] = num++;
                }
            }
        }

        for(int i =0 ;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mp[i][j])
                {
                    for(int k= 0;k<4;k++)
                    {
                        int Fx = i+dir[k][0];

                        int Fy = j+dir[k][1];

                        if(Ok(Fx,Fy) && mp[Fx][Fy])
                        {
                            vis[mp[i][j]][mp[Fx][Fy]] = true;
                        }
                    }
                }
            }
        }

        int ans =0;

        memset(pre,0,sizeof(pre));

        for(int i=1;i<num;i++)
        {
            memset(Y,false,sizeof(Y));
            
            ans += dfs(i);
        }

        printf("%d\n",num-1-ans/2);

    }


    return 0;
}
