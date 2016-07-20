#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

const int Max = 1100000;

bool vis[Max];

void GetPrime()
{
    for(int i =2;i<Max;i++)
    {
        if(!vis[i])
        {
            for(int j = 2;i*j<Max;j++)
            {
                vis[i*j] = true; 
            }
        }
    }
}

int main()
{
    GetPrime();

    int n;

    while(~scanf("%d",&n) && n)
    {
        int ans1 = -1,ans2 = -1;
        for(int i = 3;i+i<=n;i++)
        {
            if(!vis[i] && !vis[n-i])
            {
                ans1 = i;

                ans2 = n-i;

                break;
            }
        }

        if(ans1 == -1)
        {
            printf("Goldbach's conjecture is wrong.\n");
        }
        else printf("%d = %d + %d\n",n,ans1,ans2);
    }
    return 0;
}
