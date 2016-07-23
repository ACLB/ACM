#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

int n,k;

double l,v1,v2;

double t;

int main()
{
    scanf("%d %lf %lf %lf %d",&n,&l,&v1,&v2,&k);

    int num = (n+k-1)/k;

    double s = l*(v2+v1)/((num-1)*2*v1+v1+v2);

    printf("%.10f\n",(l-s)/v1+s/v2);

    return 0;
}
