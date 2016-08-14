#include <bits/stdc++.h>

using namespace std;

const int Max =5* 1e4;

int sum[Max],num[Max];

int FJ(int s)
{
    int ans = 1;
    for(int i = 2;i<=s;i++)
    {
        if(s%i ==0)
        {
            int num = 0;
            while(s%i ==0)
            {
                s/=i;

                num++;
            }

            ans *= (num+1);
        }
    }
    if(s !=1) ans*=2;
    return ans;
}

void Get()
{
    sum[0] = 0;

    num[0] = 0;


    for(int i = 1;i<Max;i++)
    {
        sum[i]=sum[i-1]+i;
        num[i] = FJ(sum[i]);
    }
}

int main()
{
    Get();

    int T;

    int n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(int i = 1;i<Max;i++)
        {
            if(num[i]>n)
            {
                printf("%d\n",sum[i]);

                break;
            }
        }
    }
    return 0;
}
