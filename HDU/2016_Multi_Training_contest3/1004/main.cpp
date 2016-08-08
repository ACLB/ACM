#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int Max =1000;

int a[Max][Max];

bool vis[Max];

int x[Max];

int Free[Max];

int num;

void Gauss(int n)
{
    memset(vis,false,sizeof(vis));

    for(int row= 0 ,col = 0 ;row<n && col < n ; row++ ,col ++)
    {
        int r = row;

        for(int i = row;i<n;i++)
        {
            if(a[i][col])
            {
                r = i;

                break;
            }
        }

        if(a[r][col] == 0)
        {
            row --;

            vis[col] = true;

            continue;
        }

        for(int i = col;i<=n;i++)
        {
            swap(a[r][i],a[row][i]);
        }

        for(int i = row + 1;i<n;i++)
        {
            if(a[i][col])
            {
                int x1 = a[row][col];

                int x2 = a[i][col];

                for(int j = col;j<=n;j++)
                {
                    a[i][j] = a[i][j]*x1-a[row][j]*x2;

                    a[i][j] = (a[i][j]%3+3)%3;
                }
            }
        }
    }

    memset(x,0,sizeof(x));

    for(int i = n-1;i>=0;i--)
    {
        if(vis[i]) continue;

        int temp = a[i][n];

        for(int j = i+1;j<n;j++)
        {
            temp = ((temp-a[i][j]*x[j])%3+3)%3;
        }
        while(temp%a[i][i])
        {
            temp +=3;
        }

        x[i] = ((temp/a[i][i])%3+3)%3;
    }
}

int n,m;

void Init()
{
    memset(a,0,sizeof(a));

    for(int i = 0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(i>0) a[(i-1)*m+j][(i*m+j)] =1;

            if(j>0) a[i*m+j-1][(i*m+j)] = 1;

            if(i<n-1) a[(i+1)*m+j][i*m+j] = 1;

            if(j<m-1) a[(i*m+j+1)][i*m+j] = 1;

            a[i*m+j][i*m+j] = 2;
        }
    }
}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&m);

        Init();

        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                scanf("%d",&a[i*m+j][n*m]);

                a[i*m+j][n*m] = (3-a[i*m+j][n*m])%3;
            }
        }


        Gauss(n*m);

        int ans =0 ;

        for(int i = 0;i<n*m;i++)
        {
            ans+=x[i];
        }
        printf("%d\n",ans);

        for(int i = 0;i<n*m;i++)
        {
            for(int j = 0;j<x[i];j++)
            {
                printf("%d %d\n",i/m+1,i%m+1);
            }
        }
    }
    return 0;
}
