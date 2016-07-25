#include<iostream>
#include<cstdio>
#include<cstring>
#include <cmath>
#include<algorithm>

using namespace std;

const int Max = 1e6+100;

const double e = 2.71828;

int prime[Max];

bool vis[Max];

int num[Max];

void Get()
{
    prime[0] =0 ;

    num[0] = num[1] = 0;
    for(int i = 2;i<Max;i++)
    {
        if(!vis[i])
        {
            prime[++prime[0]] = i;

            for(int j =i+i;j<Max;j+=i)
            {
                vis[j] = true;
            }
        }

        num[i] = num[i-1];

        if(!vis[i]) num[i]++;
    }
}

int n,p;

int main()
{

    Get();

    int T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&p);

        int flag = -1;

        for(int i = 1;i<=prime[0];i++)
        {
            if(p<prime[i]) break;

            if(p%prime[i]==0 )
            {
                flag =prime[i];

                break;
            }

        }

        if(flag  == -1) flag= p;

        int s=(n-1)/p;

        s = min(s,flag);

        int ans;

        if(s<2)
        {
            ans = 0;
        }
        else
        {
            ans = num[s];
        }
        printf("%d\n",ans);
    }
    return 0;
}
