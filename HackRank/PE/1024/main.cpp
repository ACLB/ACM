#include <bits/stdc++.h>

using namespace std;

int a[15];

bool vis[15];

int ans[15];

int main()
{
    int T,n;

    scanf("%d",&T);

    a[1] = 1;

    a[2] = 1;
    for(int i = 3;i<=13;i++)
    {
        a[i] = a[i-1]*(i-1);
    }
    while(T--)
    {
        scanf("%d",&n); n--;
        memset(vis,false,sizeof(vis));

        for(int i = 13;i>=1;i--)
        {
            int num = n/a[i]+1; n%=a[i];

            int s = 1;

            for(int j = 1;j<=13;j++)
            {
                if(vis[j]) continue;

                if(s == num)
                {
                    vis[j] = true;

                    ans[i] = j;

                    break;
                }
                s++;
            }
        }

        for(int i = 13;i>=1;i--)
        {
            printf("%c",ans[i]-1+'a');
        }

        printf("\n");
    }
    return 0;
}
