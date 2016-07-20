#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int Max = 1299710; 

bool vis[Max];

int num[Max];

int prime[Max];

void GetPrime()
{
    memset(vis,false,sizeof(vis));
    prime[0] = 0;

    for(int i = 2;i<Max;i++)
    {
        if(!vis[i])
        {
            prime[++prime[0]] = i;

            for(int j = i+i;j<Max;j+=i)
            {
                vis[j] = true;
            }
        }
    }

    memset(num,0,sizeof(num));

    for(int i = 2;i<=prime[0];i++)
    {
        for(int j = prime[i-1]+1;j<prime[i];j++)
        {
            num[j] = (prime[i]-prime[i-1]);
        }
    }
}

int main()
{
    int n;

    GetPrime();

    while(~scanf("%d",&n) && n)
    {
        printf("%d\n",num[n]);
    }
    return 0;
}
