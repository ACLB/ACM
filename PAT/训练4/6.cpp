#include <bits/stdc++.h>

using namespace std;

char s[11][11];
 int n;

char c[30];
bool Judge()
{
    for(int i = 1;i<=2*n;i++)
    {
        for(int j = 1;j<=2*n;j++)
        {
            if(s[i][j]!='*') return false;
        }
    }
    return true;
}
int main()
{


    scanf("%d",&n);

    getchar();

    for(int i = 1;i<=2*n;i++)
    {
        gets(c);

        int m = strlen(c);

        int k =1;
        for(int j = 0;j<m;j++)
        {
            if(c[j]!=' ')
            {
                s[i][k++] = c[j];
            }
        }
    }

    int m;

    scanf("%d",&m);

    int x1,y1,x2,y2;

    int ans = 0;
    for(int i = 0;i<m;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        if(ans>=3 || Judge()) continue;

        if(s[x1][y1] == s[x2][y2])
        {
            s[x1][y1] = s[x2][y2] = '*';

            if(Judge())
            {
                printf("Congratulations!\n");

                continue;
            }

            for(int k = 1;k<=2*n;k++)
            {
                for(int j = 1;j<=2*n;j++)
                {
                    if(j != 1) printf(" ");
                    printf("%c",s[k][j]);
                }

                printf("\n");
            }
        }
        else
        {
            ans++;

            if(ans >=3)
            {
                printf("Game Over\n");
            }
            else printf("Uh-oh\n");
        }
    }
    return 0;
}
