#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

double dp[1100][35][35];

double p[1100][35];

double s[1100][35];

int main()
{
    int n,m,t;

    while(~scanf("%d %d %d",&m,&t,&n)&&(m+t+n))
    {
        for(int i  = 0;i<t;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                scanf("%lf",&p[i][j]);
            }
        }

        for(int i = 0;i<t;i++)
        {
            dp[i][0][0] = 1;

            for(int j = 1;j<=m;j++)
            {
                dp[i][j][0] = dp[i][j-1][0] *(1-p[i][j]);
            }

            for(int j = 1;j<=m;j++)
            {
                for(int k = 1;k<=j;k++)
                {
                    dp[i][j][k] = (dp[i][j-1][k-1]*p[i][j]+dp[i][j-1][k]*(1-p[i][j]));
                }
            }

            s[i][0] = dp[i][m][0];

            for(int j =1;j<=m;j++)
            {
                s[i][j]=s[i][j-1]+dp[i][m][j];
            }
        }

        double p1 = 1,p2 =1;
        for(int i = 0;i<t;i++)
        {
            p1*=(s[i][m]-s[i][0]);
        }

        for(int i =0;i<t;i++)
        {
            p2 *=(s[i][n-1]-s[i][0]);
        }

        printf("%.3f\n",p1-p2);
    }
    return 0;
}
