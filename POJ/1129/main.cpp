#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

int n;

char s[110];

vector<int>E[30];

int vis[50];

int num ;

bool vist[11];



int dfs(int u)
{
    for(int i = 0;i<E[u].size();i++)
    {
        if(!vis[E[u][i]]) continue;

        else vist[vis[E[u][i]]] = true;
    }

    for(int i = 1;i<=10;i++)
    {
        if(!vist[i]) return i;
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 0;i<n;i++) E[i].clear();
        for(int i = 0;i<n;i++)
        {
            scanf("%s",s);

            int len = strlen(s);


            int  u = s[0] - 'A';

            for(int j = 2;j<len;j++)
            {
                int v = s[j]-'A';

                E[u].push_back(v);
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            memset(vist,false,sizeof(vist));

            vis[i] = dfs(i);

            printf("%d\n",vis[i]);

            ans = max(ans,vis[i]);
        }

        if(ans == 1)
        {
            printf("1 channel needed.\n");
        }
        else printf("%d channels needed.\n",ans);
    }
    return 0;
}
