#include <bits/stdc++.h>

using namespace std;

int a[13][2] ={
{284,220},
{1210,1184},
{2924,2620},
{5564,5020},
{6368,6232},
{10856,10744},
{14595,12285},
{18416,17296},
{66992,66928},
{71145,67095},
{76084,63020},
{87633,69615},
{88730,79750}
};


int main()
{
    int T,n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        int sum = 0;

        for(int i = 0;i<13;i++)
        {
            if(a[i][0]<n) sum+=a[i][0];

            if(a[i][1]<n) sum+=a[i][1];
        }

        printf("%d\n",sum);
    }
    return 0;
}
