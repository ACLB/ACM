#include <bits/stdc++.h>

using namespace std;

double eps;

bool dbcmp(double s)
{
    if(abs(s)<=eps) return false;

    return true;
}

int main()
{
    scanf("%lf",&eps);

    int op = 0 , num = 1;

    double sum = 0;

    while(dbcmp(1.0/num))
    {
        if(op)
        {
            sum-=(1.0/num);
        }
        else sum+=(1.0/num);

        num+=3;

        op =(op+1)%2;

    }


        if(op)
        {
            sum-=(1.0/num);
        }
        else sum+=(1.0/num);

    printf("sum = %.6f",sum);

    return 0;
}
