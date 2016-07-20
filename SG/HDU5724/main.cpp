#include <bits/stdc++.h>

using namespace std;

int Sg[(1<<20)+10];

bool mex[21];

int GetSg(int s)
{
    memset(mex,false,sizeof(mex));

    for(int i = 0;i<20;i++)
    {
        if((1<<i)&s)
        {
            for(int j = i-1;j>=0;j--)
            {
                if(((1<<j)&s) == 0)
                {
                    mex[Sg[((1<<i)^s)^(1<<j)]] = true;

                    break;
                }
            }
        }
    }

    for(int i  = 0;i<=20;i++)
    {
        if(!mex[i]) return i;
    }
}

int main()
{
    Sg[0] = 0;

    for(int i = 1;i<(1<<20);i++)
    {
        Sg[i] = GetSg(i);

    }

    int T,n,m,st;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        int ans = 0;

        for(int i = 0;i<n;i++)
        {
            scanf("%d",&m);

            int num = 0;

            for(int j = 0;j<m;j++)
            {
                scanf("%d",&st);

                num = (num^(1<<(20-st)));

            }

            ans ^=Sg[num];
        }

        if(ans)
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }

    return 0;
}
