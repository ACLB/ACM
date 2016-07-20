#include <bits/stdc++.h>

using namespace std;

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
    return 0;
}
