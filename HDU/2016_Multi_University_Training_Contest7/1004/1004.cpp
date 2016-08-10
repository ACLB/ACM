#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int  Max = 1100000;

bool vis[Max];

int num[Max];

void Get()
{
    memset(vis,false,sizeof(vis));

    memset(num,0,sizeof(num));

    for(int i =2;i<Max;i++)
    {
        if(!vis[i])
        {
            for(int j = 1;j*i<Max;j++)
            {
                vis[i] = true;

                num[i*j] +=j;
            }
        }
    }
}

char op[2];


int c[Max][21];

int main()
{

    Get();

    int n,z = 1,data;

    while(~scanf("%d",&n)&&n)
    {
        for(int i =1;i<=n;i++)
        {
            scanf("%s %d",op,&data);
        }
    }
    return 0;
}
