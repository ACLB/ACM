#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;

    scanf("%d %d",&n,&m);

    int ss = 0,sum = 1;

    for(int i = n*m-1;i>=0;i--,ss++,sum+=2)
    {
        for(int j =1;j<=i;j++) printf(" ");

        int s = ((ss%m)+1);

        int  t = 2*s-1;

        int tt = (m-(s-1))*2-1;

        for(int j = 1;j<=sum;)
        {
            for(int k = 1;k<=t;k++,j++)
            {
                printf("*");
            }

            for(int k = 1;k<=tt&&j<=sum;k++,j++)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
