#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

int n,k;

double l,v1,v2;

double t;

int dbcmp(double s)
{
    if(fabs(s)<eps) return 0;

    return s>0?1:-1;
}

double Gets(double s)
{
    return (s-(s/v2)*v1)/(v1+v2)*v1+s/v2*v1;
}

int main()
{
    scanf("%d %lf %lf %lf %d",&n,&l,&v1,&v2,&k);


    int num = (n+k-1)/k;

    double L = 0,R = l;

    t = l/v1;

    while(dbcmp(R-L)>0)
    {
        double mid = (L+R)/2;

        if(mid+(num-1)*Gets(mid)>l)
        {
            R = mid;

            continue;
        }

        if(t >((l-mid)/v1+mid/v2))
        {
            t = (l-mid)/v1+mid/v2;

            L = mid;
        }
        else R = mid;

    }
    printf("%.10f\n",t);
    return 0;
}
