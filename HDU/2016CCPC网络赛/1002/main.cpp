#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Max = 2000;

const int Mod =  1000000007;

int vis[Max+100];

int pr[Max];

LL b[300];

int arr[400][400];

void Get()
{
    pr[0] = 0;

    memset(vis,false,sizeof(vis));

    for(int i = 2;i<=Max;i++)
    {
        if(!vis[i])
        {
            pr[++pr[0]] = i;

            for(int j = i+i;j<=Max;j+=i)
            {
                vis[j] = true;
            }
        }
    }
}

void build(int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 1;j<=pr[0];j++)
        {
            if(b[i]%pr[j] == 0)
            {
                int num = 0;

                while(b[i]%pr[j] ==0)
                {
                    b[i]/=pr[j];

                    num++;
                }

                arr[j-1][i] = num%2;
            }
        }
    }
}

int Gauss(int n,int m)
{
    int num = 0;

    int row = 0,col = 0;

    for(;row<=n&&col<m;row++,col++)
    {
        int r = row;

        for(int i = row+1;i<=n;i++) if(arr[i][col]) r= i;

        if(arr[r][col] ==0)
        {
            num++;

            row --;

            continue;
        }

        for(int i = col;i<=m;i++) swap(arr[row][i],arr[r][i]);

        for(int i = row+1;i<=n;i++)
        {
            if(arr[i][col] ==0 )continue;

            for(int j = col;j<=m;j++)
            {
                arr[i][j] ^=arr[row][j];
            }
        }
    }

    for(int i = row;i<m;i++) if(arr[i][col]) return -1;
    return num;
}

LL Pow(LL n,LL m)
{
    LL ans = 1;

    while(m)
    {
        if(m%2)
        {
            ans = (ans*n)%Mod;
        }
        n = (n*n)%Mod;

        m>>=1;
    }

    return ans;
}

int main()
{
    int T,z =1;

    int n;

    Get();

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        memset(arr,0,sizeof(arr));

        for(int i = 0;i<n;i++) scanf("%I64d",&b[i]);

        build(n);

        int ans = Gauss(pr[0],n);

        printf("Case #%d:\n",z++);

        if(ans == -1)
        {
            printf("0\n");
        }
        else printf("%I64d\n",((Pow(2,ans)-1)%Mod+Mod)%Mod);

    }
    return 0;
}
