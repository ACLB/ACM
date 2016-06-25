#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

char c;

int main()
{
    bool flag = false;

    bool fu = false;

    long long sum = 0;

    while(scanf("%c",&c))
    {
        if(c == '#')
        {
            break;
        }

        if((c>='0' && c<='9')||(c >='a' && c <= 'f') || (c >= 'A' && c <= 'F'))
        {
            if(c >= '0' && c<='9')
            {
                sum = sum*16+c-'0';
            }
            else if(c>='a' && c<='f')
            {
                sum = sum*16+c-'a'+10;
            }
            else sum =sum*16+c-'A'+10;

            flag = true;
        }
        else if(c == '-')
        {
            if(flag)
            {
                continue;
            }
            else fu = true;
        }

    }

    if(fu  && sum)
    {
        printf("-");
    }
    printf("%lld\n",sum);

    return 0;
}
