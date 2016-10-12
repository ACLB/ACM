#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL sum1,sum2;

int a[110000];

int b[110000];

int main()
{
    int n,k;

    scanf("%d %d",&n,&k);

    sum1 = 0;

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);

        sum1+=a[i];
    }
    sum2 = 0;

    for(int i = 0;i<n;i++)
    {
        if(i == 0)
        {
            sum2+=(a[i]*a[n-1]);
        }
        else sum2+=a[i]*a[i-1];

        if(i ==0)
        {
            b[i] = a[i]*a[n-1]+a[i]*a[i+1];
        }
        else if(i ==n-1)
        {
            b[i] = a[i-1]*a[i]+a[i]*a[0];
        }
        else b[i] = a[i-1]*a[i]+a[i+1]*a[i];
    }

    int op ;

    LL ant = 0;
    for(int i = 0;i<k;i++)
    {
        scanf("%d",&op);

        sum2+=(a[op-1]*(sum1-a[op-1])-b[op-1])-a[op-1]*ant;

        ant+=a[op-1];
    }

    cout<<sum2<<endl;
    return 0;
}
