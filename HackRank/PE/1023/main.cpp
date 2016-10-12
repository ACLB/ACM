#include <bits/stdc++.h>

using namespace std;

const int Max = 1e5;

bool vis[Max+100];

int pr[Max];

int solve(int s)
{
    int ans = 0 ;

    for(int i =2;i*i<=s;i++)
    {
        if(s%i ==0 )
        {
            ans+=i;

            if(s/i!=i) ans+=s/i;
        }
    }

    return ans;
}

void Get()
{

    pr[0] = 0;

    memset(vis,false,sizeof(vis));

    for(int i = 2;i<=Max;i++)
    {

        if(i<solve(i))
        {
            pr[++pr[0]] = i;
            for(int j = 1;j<=pr[0];j++)
            {
                if(pr[j]+i<=Max)
                {
                    vis[pr[j]+i] = true;
                }
                else break;
            }


        }
    }

}

int main()
{
    Get();

    int T,n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        if(vis[n]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
