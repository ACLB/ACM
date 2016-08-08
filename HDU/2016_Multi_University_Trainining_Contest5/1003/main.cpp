#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Max = 1e6+100;

LL arr[Max];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i  = 0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }

        LL sum = 0;

        int ans = 0;

        for(int i = n-1;i>=0;i--)
        {
            sum+=arr[i];

            if(sum>=0)
            {
                ans++;

                sum = 0;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
