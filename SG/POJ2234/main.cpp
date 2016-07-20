#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int Sg[1100];

bool vis[1100];

int GetSg(int s)
{
    memset(vis,false,sizeof(vis));

    for(int i = 0;i<s;i++)
    {
        vis[Sg[i]] = true;
    }

    for(int i = 0;i<=s;i++)
    {
        if(!vis[i]) return i ;
    }
}

int main()
{
    Sg[0] = 0;

    //for(int i = 1;i<=1000;i++)
    //{
      //  Sg[i] = GetSg(i);

        //cout<<i<<" "<<Sg[i]<<endl;
    //}

    int n,op;

    while(~scanf("%d",&n))
    {
        int ans  = 0;
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&op);

            ans ^=op;
        }

        if(ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
