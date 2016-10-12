#include <bits/stdc++.h>

using namespace std;

const int Max  = 1e5+100;

double a[Max];

int main()
{
    int T;

    int n,m,k;

    double c,x,d;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %lf",&n,&c);

        for(int i = 0;i<n;i++)
        {
            scanf("%lf %lf %lf",&a[i],&d,&x);

            a[i] = a[i]*a[i]/(2*c);
        }

        sort(a,a+n);

        scanf("%d",&m);

        while(m--)
        {
            scanf("%lf %d",&d,&k);

            printf("%.3f\n",sqrt((a[k-1]+d)*c*2));
        }
    }
    return 0;
}
