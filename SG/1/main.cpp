#include <bits/stdc++.h>

using namespace std;

bool Sg[1100];

int main()
{
    for(int i  = 1;i<=1000;i++)
    {
        int num = 1;
        while(num<=i)
        {
            if(!Sg[i-num])
            {
               Sg[i] = true;
               break;
            }

            num*=2;
        }
    }

    int n;

    while(~scanf("%d",&n))
    {
        if(Sg[n])
        {
            printf("Kiki\n");
        }
        else printf("Cici\n");
    }
    return 0;
}
