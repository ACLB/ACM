#include <bits/stdc++.h>
#define rr() freopen("in.in","r",stdin)
#define ww() freopen("in.in","w",stdout)
#define random(x) rand()%x

using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    //rr();

    ww();

    printf("5\n");

    int st = 10;
    for(int i = 1;i<=5;i++,st*=10)
    {
        int n = st,m = n-1;

        printf("%d %d\n",n,m);

        for(int j = 2;j<=n;j++)
        {
            printf("%d %d\n",j,(random((j-1)))+1);
        }

        int q = st<=10000?10:100;
        printf("%d\n",q);

        for(int j = 1;j<=q;j++)
        {
            printf("%d\n",random(n)+1);
        }
    }
    return 0;
}
