#include <bits/stdc++.h>

using namespace std;

const int Max = 1100000;

bool vis[Max];

int num[Max];

bool Judge(int s)
{
    int ans = 0;
    while(s)
    {
        ans+=(s%10);

        s/=10;
    }

    return (!vis[ans]);
}

void Get()
{

    vis[1] = true;
    for(int i = 2;i<Max;i++)
    {
        if(!vis[i])
        {
            for(int j =i +i;j<Max;j+=i)
            {
                vis[j] = true;
            }
        }
    }

    num[0] = 0;

    for(int i = 1;i<Max;i++)
    {
        num[i] = num[i-1];

        if(!vis[i] && Judge(i))
        {
            num[i] ++;
        }
    }
    
}

int main()
{
    Get();
    int n;

    int l,r;

    scanf("%d",&n);
    
    while(n--)
    {
        scanf("%d %d",&l,&r);

        printf("%d\n",num[r]-num[l-1]);
    }
    
    return 0;
}
