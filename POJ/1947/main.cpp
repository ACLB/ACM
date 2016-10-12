#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int Max = 155;

vector<int>E[Max];

int n,m;

int num[Max];

void dfs(int u)
{
}

int main()
{
    int u,v;
    while(~scanf("%d %d",&n,&m))
    {
        for(int i = 1;i<n;i++)
        {
            scanf("%d %d",&u,&v);

            E[u].push_back(v);
        }

        memset(num,0,sizeof(num));

        for(int i = 1;i<=n;i++)
        {
            dfs(i);
        }
    }
    return 0;
}
