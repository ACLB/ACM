#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

long long n;

int main()
{
    while(~scanf("%I64d",&n))
    {
        if(n<=9)
        {
            printf("Stan wins.\n");

            continue;
        }
        while(1)
        {
            n = n/18+(n%18 == 0?0:1);

            if(n<=9) break;
        }

        if(n<=1)
        {
            printf("Ollie wins.\n");
        }
        else printf("Stan wins.\n");
    }

    return 0;
}
