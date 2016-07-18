#include <bits/stdc++.h>

using namespace std;

const int Max = 11000000;

bool vis[Max];

void Getprime()
{
    for(int i = 2;i<Max;i++)
    {
        if(!vis[i])
        {
            for(int j = i+i;j<Max;j+=i)
            {
                vis[j]  = true;
            }
        }
    }
}

int main()
{
    int n;

    Getprime();

    while(~scanf("%d",&n))
    {
        if(n<8)
        {
            printf("Impossible.\n");
        }
        else 
        {
            if(n%2 == 0)
            {
                printf("2 2");

                n-=4;
            }
            else 
            {
                n-=5;
                printf("2 3");
            }

            for(int i = 2;i+i<=n;i++)
            {
                if(!vis[i]&& !vis[n-i])
                {
                    printf(" %d %d\n",i,n-i);



                    break;
                }

            }

        }
    }
    return 0;
}
