#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int n,k,y;

int main()
{
    while(~scanf("%d",&y) && y)
    {
        k = 2+(y-1960)/10;

        k = (1<<k);

        double ans = 0;

        int ant = 1;

        for(int i = 2;;i++)
        {
            if(ans+log(i)/log(2) >= k)
            {
                ant = i-1;

                break;
            }

            ans+=log(i)/log(2);
        }
        printf("%d\n",ant);
    }
    return 0;
}
