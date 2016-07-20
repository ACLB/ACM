
#include <bits/stdc++.h>

using namespace std;

int n,m;

int s;

set<int>E[1100];

bool vis[1100];

bool flag;

int num;

void dfs(int u)
{
    if(flag) cout<<" ";
    else flag=  true;

    printf("%d",u);

    if(!vis[u])
    {
        num++;

        vis[u] = true;
    }

    
    for(set<int>::iterator it = E[u].begin();it != E[u].end();it++)
    {
        if(!vis[*it])
        {
            dfs(*it);
            
            if(flag) cout<<" ";
            
            else flag=  true;
            
            printf("%d",u);
        }
    }
    
}

int main()
{
    cin>>n>>m>>s;

    int u,v;

    for(int i = 0;i<m;i++)
    {
        cin>>u>>v;

        E[u].insert(v);

        E[v].insert(u);
    }
    memset(vis,false,sizeof(vis));

    flag = false;

    num= 0;
    
    dfs(s);

    if(num != n)
    {
        cout<<" 0";
    }
    cout<<endl;
    return 0;
}
