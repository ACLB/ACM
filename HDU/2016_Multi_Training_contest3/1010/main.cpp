#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;



int main()
{
    int a,v1,v2;

    while(~scanf("%d %d %d",&a,&v1,&v2))
    {
        if(a == 0)
        {
            printf("0\n");

            continue;

        }
        if(v1<=v2)
        {
            printf("Infinity\n");
        }
        else
        {
            printf("%.10f\n",v1*a*1.0/(v1*v1-v2*v2));
        }
    }
    return 0;
}
