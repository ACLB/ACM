#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int arr[35][35];

void Init()
{
    memset(arr,0,sizeof(arr));

    for(int i = 0;i<5;i++)
    {
        for(int j = 0;j<6;j++)
        {
            if(i>0)
            {
                arr[i*6+j][(i-1)*6+j] = 1;
            }

            if(i<4)
            {
                arr[i*6+j][(i+1)*6+j] = 1;
            }

            if(j>0)
            {
                arr[i*6+j][(i*6+j-1)] = 1;
            }

            if(j<5)
            {
                arr[i*6+j][i*6+j+1]  = 1;
            }

            arr[i*6+j][i*6+j] = 1;
        }
    }
}

bool vis[35];

int ans[35];

void Gauss(int n,int m)
{
    int row ,col;

    memset(vis,false,sizeof(vis));

    for(row = 0,col = 0;row <= n && col<m;row++,col++)
    {
        int r = row;

        for(int i = row;i<=n;i++)
        {
            if(arr[i][col]) r = i;
        }

        if(!arr[r][col])
        {
            vis[col] = true;

            row--;

            continue;
        }

        for(int i = col;i<=m;i++)
        {
            swap(arr[r][i],arr[row][i]);
        }

        for(int i = row+1;i<=n;i++)
        {
            if(arr[i][col])
            {
                int x1 = arr[row][col];

                int x2 = arr[i][col];

                for(int j = col;j<=m;j++)
                {
                    arr[i][j] = ((x1*arr[i][j] - x2 *arr[row][j])%2+2)%2;
                }
            }
        }
    }

    memset(ans,0,sizeof(ans));

    for(int i = m-1;i>=0;i--)
    {
        if(vis[i]) continue;

        int temp = arr[i][m];

        for(int j = i+1;j<m;j++)
        {
            temp = ((temp - arr[i][j]*ans[j])%2+2)%2;
        }

        while(temp%arr[i][i]) temp+=2;

        ans[i] = ((temp/arr[i][i])%2+2)%2;
    }
}

int main()
{
    int T,z = 1;

    scanf("%d",&T);

    while(T--)
    {
        Init();
        for(int i  = 0;i<5;i++)
        {
            for(int j = 0;j<6;j++)
            {
                scanf("%d",&arr[i*6+j][30]);
            }
        }
        Gauss(29,30);

        printf("PUZZLE #%d\n",z++);

        for(int i = 0;i<5;i++)
        {
            for(int j = 0;j<6;j++)
            {
                if(j) printf(" ");

                printf("%d",ans[i*6+j]);
            }

            printf("\n");
        }
    }
    return 0;
}
