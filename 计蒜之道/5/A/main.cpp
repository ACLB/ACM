#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const double PI = acos(-1.0);


int main()
{
    int n,k;

    double s,a;

    scanf("%d %d",&n,&k);

    scanf("%lf",&s);

    double ans = 0;

    a = PI/2-PI/n;

    for(int i = 0;i<=k;i++)
    {
        ans += s*(n-1);

        if(i!=k)
        {
            ans+=s/2;
        }

        s = s*sin(a);
    }

    printf("%f\n",ans);

    return 0;
}
