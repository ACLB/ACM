#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int MaxN = 350;

const int Mod = 7;

int arr[MaxN][MaxN];

char s[5],t[5];

bool vis[MaxN];

int a[MaxN] ;

int ans[MaxN];

int GetNum(char *str)
{
    if(strcmp(str,"MON")==0) return 0;

    if(strcmp(str,"TUE") ==0) return 1;

    if(strcmp(str,"WED")==0) return 2;

    if(strcmp(str,"THU")==0) return 3;

    if(strcmp(str,"FRI")==0) return 4;

    if(strcmp(str,"SAT")==0) return 5;

    if(strcmp(str,"SUN") ==0 )return 6;

    return 0;
}

int Gauss(int n,int m)
{
    memset(vis,false,sizeof(vis));

    int row ,col;

    a[0] = 0;

    for(row = 1,col = 1;row <=n && col <m ;row++,col++)
    {
        int r = row;

        for(int i = row;i<=n;i++)
        {
            if(arr[i][col]) r = i;
        }
        if(arr[r][col] ==0)
        {
            vis[col] = true;

            a[++a[0]] = col;

            row --;

            continue;
        }

        for(int i = col;i<=m;i++)
        {
            swap(arr[row][i],arr[r][i]);
        }

        for(int i = row+1;i<=n;i++)
        {
            if(arr[i][col])
            {
                int x1 = arr[row][col];

                int x2 = arr[i][col];

                for(int j = col;j<=m;j++)
                {
                    arr[i][j] = (((x1*arr[i][j]-x2*arr[row][j])%Mod+Mod)%Mod);
                }
            }
        }
    }

    for(int i = row;i<=n;i++) if(arr[i][m]) return -1;

    if(row<m) return -2;

    memset(ans,0,sizeof(ans));

    for(int i = m-1;i>=1;i--)
    {
        if(vis[i]) continue;

        int temp = arr[i][m];

        for(int j = m-1;j>i;j--)
        {
            temp= (((temp-ans[j]*arr[i][j])%Mod+Mod)%Mod);
        }

        while(temp%arr[i][i]) temp+=Mod;

        ans[i] = (((temp/arr[i][i])%Mod+Mod)%Mod);

        if(ans[i] < 3) ans[i]+=Mod;
    }

    return 1;
}

int main()
{
    int n,m,num,st;

    while(~scanf("%d %d",&n,&m) && (n+m))
    {
        memset(arr,0,sizeof(arr));

        for(int i =1;i<=m;i++)
        {
            scanf("%d %s %s",&num,s,t);

            arr[i][n+1] = (((GetNum(t)-GetNum(s)+1)%Mod+Mod)%Mod);

            for(int j =1;j<=num;j++)
            {
                scanf("%d",&st);

                arr[i][st] = (arr[i][st]+1)%Mod;
            }

        }

        int ant = Gauss(m,n+1);

        if(ant == -1)
        {
            printf("Inconsistent data.\n");
        }
        else if(ant == -2)
        {
            printf("Multiple solutions.\n");
        }
        else if(ant ==1)
        {
            for(int i = 1;i<=n;i++)
            {
                if(i != 1) printf(" ");

                printf("%d",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
