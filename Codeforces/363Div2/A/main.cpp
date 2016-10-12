#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
const int INF = 0x3f3f3f3f;

char s[230000];

int  a[230000];

int main()
{
    int n,data;

    scanf("%d",&n);

    scanf("%s",s);


    int ans = INF;

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);

        if(!i) continue;

        if(s[i]=='L' && s[i-1] == 'R')
        {
            ans  = min(ans,(a[i]-a[i-1])/2);
        }
    }
    if(ans == INF) ans = -1;

    printf("%d\n",ans);
=======
char s[1100][1100];

int x[1100],y[1100];

int main()
{
    int n,m;

    int X = -1 ,Y = -1;

    int sum = 0 ;

    scanf("%d %d",&n,&m);

    for(int i = 0;i<n;i++)
    {
        scanf("%s",s[i]);
        for(int j = 0;j<m;j++)
        {
            if(s[i][j] == '*')
            {
                x[i] ++;
                y[j]++;
                sum++;
            }
        }
    }
    for(int i = 0 ;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(sum == (x[i] + y[j] - (s[i][j] == '*'?1:0)))
            {
                X = i+1;

                Y = j+1;
                break;
            }
        }
    }


    if(X != -1)
    {
        printf("YES\n%d %d\n",X,Y);
    }
    else printf("NO\n");
>>>>>>> 0cb576ae3a1f15ec03ffe131c0c1cc7dd0222900
    return 0;
}
