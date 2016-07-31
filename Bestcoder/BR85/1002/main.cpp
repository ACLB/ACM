#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);

const double e = exp(1);

typedef long long LL;

int T;

int n,k;

int a[110000];

int main()
{
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&k);


        LL sum = n;

        for(int i = 0; i<n-1; i++)
        {
            scanf("%d",&a[i]);

            sum+=a[i];
        }
        if(k>=n)
        {
            sum = n;
        }
        else

        {
            sort(a,a+n-1);

            for(int i = n-2; i>=(n-1-k+1); i--)
            {
                sum-=a[i];
            }
        }
        printf("%I64d\n",sum);
    }

    return 0;
}
