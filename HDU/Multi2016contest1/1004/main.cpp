#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

const int Max = 110000;

int arr[Max];

int f[100010][18];

int n;

map<int,long long >M;

int GCD(int a,int b)
{
    return b == 0?a:GCD(b,a%b);
}

void rmq()
{
    for(int j=1; j<=n; j++) f[j][0]=arr[j];

    for(int i=1; i<18; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j+(1<<i)-1 <= n)
            {
                f[j][i]=GCD(f[j][i-1],f[j+(1<<(i-1))][i-1]);
            }
        }
    }
}
int look(int l,int r)
{
    int k=(int)log2((double)(r-l+1));
    return GCD(f[l][k],f[r-(1<<k)+1][k]);
}

void Op(int s)
{
    int r =s;

    int g;

    while(r<=n)
    {
        g = look(s,r);

        int L = r,R = n;

        while(L<R)
        {

            int mid = (L+R+1)>>1;

            if(look(s,mid) == g)
            {
                L = mid;
            }
            else R = mid-1;
        }
        M[g]+=(L-r+1);

        r = L+1;

    }
}

int main()
{


    int T;

    int z = 1;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(int i = 1; i<=n; i++) scanf("%d",&arr[i]);

        rmq();

        M.clear();

        for(int i = 1; i<=n; i++)
        {
            Op(i);
        }

        int m;

        scanf("%d",&m);

        int l,r;
        printf("Case #%d:\n",z++);

        while(m--)
        {
            scanf("%d %d",&l,&r);

            int g = look(l,r);

            printf("%d %lld\n",g,M[g]);
        }
    }
    return 0;
}
