#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int H[1100][1100];

int s[1110],d[1110];

int S[1100];

int main()
{

    int n;

    scanf("%d",&n);

    for(int i = 1; i<=n; i++)
    {
        scanf("%d",&H[i][0]);

        for(int j = H[i][0]; j>=1; j--)
        {
            scanf("%d",&H[i][j]);
        }
    }

    int Q;

    scanf("%d",&Q);

    int x,a,y,b;

    while(Q--)
    {
        scanf("%d %d %d %d",&x,&a,&y,&b);

        int i,j,k,ss;

        for(i = H[x][0], j = 1; i>=1&&j<=a; i--,j++)
        {
            s[j] = H[x][i];
        }
        H[x][0] = i+b;

        for(j = 1,k = H[y][0],ss = H[x][0]; j<=b&&k>=1; j++,k--,ss--)
        {
            H[x][ss] =H[y][k];
        }

        H[y][0] = k;

        for(j = a; j>=1; j--)
        {
            H[y][++H[y][0]]  = s[j];
        }

        int ans = 100000000;

        for(int i =1; i<=n; i++)
        {
            S[i] = i;
        }
        do
        {
            int ant = 0,sum = 0;

            for(int i = 1; i<=n; i++)
            {
                for(int j = H[S[i]][0]; j>=1; j--)
                {
                    if(ant + sum < H[S[i]][j])
                    {
                        ant = H[S[i]][j]-sum;
                    }
                    sum++;
                }
            }
            ans = min(ans,ant);
        } while(next_permutation(S+1,S+n+1));
        printf("%d\n",ans);
    }

    return 0;
}
