#include <bits/stdc++.h>

using namespace std;

int a[1100][5];

int vis[1100];

int s[1100];

void dfs(int u)
{
    if(a[u][2]!=-1)
    {
        dfs(a[u][2]);
    }

    s[++s[0]] = a[u][0];

   if(a[u][3] !=-1)
   {
       dfs(a[u][3]);
   } 
}

int main()
{
    int n;

    cin>>n;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<4;j++)
        {
            cin>>a[i][j];


            if(a[i][j]!=-1 && j>=2)

            vis[a[i][j]]++;
        }
    }

    bool flag =false;

    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);

            break;
        }
    }

    for(int i = 2;i<=n;i++)
    {
        if(s[i]<s[i-1])
        {
            flag = true;

            break;
        }
    }

    if(!flag)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 2;j<4;j++)
            {
                if(a[i][j] == -1) continue;

                if(a[a[i][j]][1] < a[i][1])
                {
                    flag = true;

                    break;
                }
            }
        }
    }

    if(!flag) cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

    return 0;
}

