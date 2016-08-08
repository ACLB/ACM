#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long LL;

int p;

LL arr[110][110];

char str[110];

bool vis[110];


int ans[1100];

void Gauss(int n,int m)
{
    int row = 0,col = 0;

    memset(vis,false,sizeof(vis));

    for(;row<=n && col<m;row++,col++)
    {
        int r = row;

        for(int i = row;i<=n;i++)
        {
            if(arr[row][col]) r = i;
        }

        if(arr[r][col] == 0)
        {
            vis[col] = true;

            row --;

            continue;
        }

        for(int i = row+1;i<=n;i++)
        {
            if(arr[i][col])
            {
                LL x1 = arr[i][col];

                LL x2 = arr[row][col];

                for(int j = col;j<=m;j++)
                {
                    arr[i][j] = ((x2*arr[i][j] - x1*arr[row][j])%p+p)%p;
                }
            }
        }
    }

    for(int i = m-1;i>=0;i--)
    {
        if(vis[i]) continue;

        LL temp = arr[i][m];

        for(int j = m-1;j>i;j--)
        {
            temp = ((temp-ans[j]*arr[i][j])%p+p)%p;
        }

        while(temp%arr[i][i])temp+=p;

        ans[i] = ((temp/arr[i][i])%p+p)%p;
    }
}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %s",&p,str);

        int len = strlen(str);

        for(int i = 1;i<=len;i++)
        {
            int k = 1;

            for(int j = 0;j<len;j++)
            {
                arr[i-1][j] = k;

                k=(k*i)%p;
            }

            if(str[i-1] == '*')
            {
                arr[i-1][len] = 0;
            }
            else
            {
                arr[i-1][len] = str[i-1]-'a'+1;
            }
        }

        memset(ans,0,sizeof(ans));

        Gauss(len-1,len);

        for(int i = 0;i<len;i++)
        {
            if(i) printf(" ");

            printf("%d",ans[i]);
        }

        printf("\n");
    }
    return 0;
}
