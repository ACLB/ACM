#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

const double Pi = acos(-1.0);

const double eps = 1e-8;

typedef long long LL;

LL a[110000];

LL b[110000];

int main()
{
    int T;

    int n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(int i = 0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
        }

        for(int i = 0;i<n-1;i++)
        {
           b[i] = abs(a[i+1]-a[i]);
        }

        sort(b,b+n-1);

        LL sum = 0;

        for(int i = 0;i<n;i++)
        {
            if(i ==0)
            {
                LL ant = abs(a[i]-a[i+1]);

                if(ant < b[n-2])
                {
                    sum+=b[n-2];
                }
                else sum+=b[n-3];
            }
            else if(i == n-1)
            {
                LL ant = abs(a[i]-a[i-1]);

                if(ant < b[n-2])
                {
                    sum+=b[n-2];
                }
                else sum+=b[n-3];
            }
            else
            {
                LL ant1 = abs(a[i]-a[i-1]);

                LL ant2 = abs(a[i]-a[i+1]);

                LL ant3 = abs(a[i+1]-a[i-1]);

                if(ant1<ant2) swap(ant1,ant2);

                if(ant3>=b[n-2])
                {
                    sum+=ant3;
                }
                else
                {
                    if(ant1!=b[n-2])
                    {
                        sum+=b[n-2];
                    }
                    else
                    {
                        if(ant2!=b[n-3])
                        {
                            if(ant3>=b[n-3])
                            {
                                sum+=ant3;
                            }
                            else sum+=b[n-3];
                        }
                        else
                        {
                            if(n==3)
                            {
                                sum+=ant3;
                            }
                            else
                            {
                                sum+=(ant3>=b[n-4]?ant3:b[n-4]);
                            }
                        }
                    }
                }
            }
        }

        printf("%I64d\n",sum);

    }

    return 0;
}
