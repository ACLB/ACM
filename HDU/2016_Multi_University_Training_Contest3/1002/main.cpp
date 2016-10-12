#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

LL sum;

double ans ;

int main()
{
    int n,c;

    while(~scanf("%d",&n))
    {
        ans = 0 ;

        sum = 0;

        for(int i = 2;i<n;i++)
        {
            sum+=(i*(i-1));
        }

        for(int i = 0;i<n;i++)
        {
            scanf("%d",&c);

            if(i == 0 || i== n-1)
            {
                ans +=(c*1.0/2);
            }
            else
            {
                ans+=(c*1.0*sum)/(n*(n-1)*(n-2));
            }
        }

        if(n == 1)
        {
            ans = c;
        }

        printf("%.6f\n",ans);
    }
    return 0;
}
