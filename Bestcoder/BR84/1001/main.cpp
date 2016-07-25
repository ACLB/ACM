#include <iostream>

#include <cstdio>
using namespace std;

typedef long long LL;

int n,m;

int Get(LL s)
{
    int ans  = 0;

    int num = 0;
    while(s&&num<m)
    {
        if(s%2) ans++;

        num++;

        s>>=1;
    }

    return ans+s;
}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
       scanf("%d %d",&n,&m);

       int ans = Get(n);

       printf("%d\n",ans);

    }
    return 0;
}
