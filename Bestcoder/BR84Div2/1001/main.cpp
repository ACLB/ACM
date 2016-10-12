#include<iostream>
#include<cstdio>
#include<cstring>
#include <cmath>
#include<algorithm>

using namespace std;

const int Max = 1e7+100;


int prime[Max];

bool vis[Max];

void Get()
{
    prime[0] =0 ;

    for(int i = 2; i<Max; i++)
    {
        if(!vis[i])
        {
            prime[++prime[0]] = i;

            for(int j =i+i; j<Max; j+=i)
            {
                vis[j] = true;
            }
        }

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

        int s=(n-1)/p;

        if(s <= 1)
        {
            printf("0\n");

            continue;
        }

        int ans = 0;

        for(int i = 1;i<=prime[0] && prime[i]<=s;i++)
        {
            ans++;
            if(p%prime[i] == 0)
            {
                break;
            }

        }

        printf("%d\n",ans);
    }
    return 0;
}
