#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int a[1100];

bool cmp(int s,int d)
{
    return s>d;
}

int main()
{
    int n;

    while(~scanf("%d",&n))
    {
        for(int i = 0; i< n; i++)
        {
            scanf("%d",&a[i]);
        }

        sort(a,a+n,cmp);

        int ans = 0;

        int num = n;

        if(n == 1)
        {
            printf("%d\n%d\n",a[0],a[0]);

            continue;
        }

        for(int i = 0; i<n; i+=2,num-=2)
        {
            if(num == 2)
            {
                ans+=a[i];

                break;
            }
            else if(num == 3)
            {
                ans+=(a[i]+a[i+1]+a[i+2]);

                break;
            }
            else
            {
                if(a[n-1]*2+a[i]+a[i+1] < a[n-1]+a[n-2]+a[i]+a[n-2])
                {
                    ans+=(a[n-1]*2+a[i]+a[i+1]);
                }
                else
                {
                    ans+=( a[n-1]+a[n-2]+a[i]+a[n-2]);
                }
            }
        }

        printf("%d\n",ans);

        num = n;

        for(int i = 0; i<n; i+=2,num-=2)
        {
            if(num == 2)
            {
                printf("%d %d\n",a[i+1],a[i]);

                break;
            }
            else if(num == 3)
            {
                printf("%d %d\n",a[n-1],a[i]);
                printf("%d\n",a[n-1]);
                printf("%d %d\n",a[n-1],a[n-2]);
                break;
            }
            else
            {
                if(a[n-1]*2+a[i]+a[i+1] < a[n-1]+a[n-2]+a[i]+a[n-2])
                {
                    printf("%d %d\n",a[n-1],a[i]);
                    printf("%d\n",a[n-1]);
                    printf("%d %d\n",a[n-1],a[i+1]);
                    printf("%d\n",a[n-1]);
                }
                else
                {
                    printf("%d %d\n",a[n-1],a[n-2]);
                    printf("%d\n",a[n-1]);
                    printf("%d %d\n",a[i+1],a[i]);
                    printf("%d\n",a[n-2]);
                }
            }
        }
    }
    return 0;
}
