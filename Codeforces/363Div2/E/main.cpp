<<<<<<< HEAD
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
=======
#include <bits/stdc++.h>

using namespace std;

const int Max = 30;

const double eps = 1e-7;

double p[Max];

double  Dp[1<<20];

double ans[25];

int n,k;

int Bite(int s)
{
    int sum = 0;

    while(s)
    {
        if(s%2) sum++;

        s >>=1;
    }

    return sum;
}

int main()
{
    scanf("%d %d",&n,&k);

    int tot = (1<<n);

    int num = 0;

    for(int i = 0;i<n;i++)
    {
        scanf("%lf",&p[i]);

        if(p[i]>=eps) num++;
    }

    k = min(k,num);

    memset(Dp,0,sizeof(Dp));

    memset(ans,0,sizeof(ans));

    Dp[0] = 1;

    for(int i = 0;i<tot;i++)
    {
        double fm = 1;

        for(int j  = 0;j<n;j++)
        {
            if(i&(1<<j))
            {
                fm -= p[j];

                if(Bite(i) == k)
                {
                    ans[j] += Dp[i];
                }
            }
        }

        for(int j = 0;j<n;j++)
        {
            if((i&(1<<j)) == 0)
            {
                Dp[i|(1<<j)]+=Dp[i]*p[j]/fm;
            }
        }
    }

    for(int i = 0;i<n;i++)
    {
        if(i) printf(" ");

        printf("%.7f",ans[i]);
    }

    printf("\n");

>>>>>>> 0cb576ae3a1f15ec03ffe131c0c1cc7dd0222900
    return 0;
}
