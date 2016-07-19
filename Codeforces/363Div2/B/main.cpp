#include <bits/stdc++.h>

using namespace std;

char s[1100][1100];

int x[1100];

int  y[1100];
int n,m;
bool Check()
{
    for(int i =0; i<n; i++)
        for(int j = 0; j<m; j++)
            if(s[i][j] == '*') return false;

    return true;
}

int main()
{



    scanf("%d %d",&n,&m);

    for(int i = 0; i<n; i++)
    {
        scanf("%s",s[i]);

        for(int j = 0; j<m; j++)
        {
            if(s[i][j] == '*')
            {
                x[i]++;

                y[j]++;
            }
        }
    }


    int X = 0,Y = 0;
    int num = 0;
    for(int i = 0; i<n; i++)
    {
        if(num<x[i])
        {
            num = x[i];

            X = i;
        }
    }
    num = 0;
    for(int i = 0; i<m; i++)
    {
        if(num<y[i])
        {
            num = y[i];

            Y = i;
        }
    }


    for(int k = 0; k<n; k++)
    {
        s[k][Y] = '.';
    }

    for(int k = 0; k<m; k++)
    {
        s[X][k] = '.';
    }


    bool ans = Check();
    if(ans)
        printf("YES\n%d %d\n",X+1,Y+1);
    else printf("NO\n");
    return 0;
}
