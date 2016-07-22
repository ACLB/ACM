#include <bits/stdc++.h>

using namespace std;

const int Max = 1e5+100;

char s[Max],p[5500];

int main()
{
    int T,n,m;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&m);

        scanf("%s",s);

        scanf("%s",p);

        for(int i = 0;i<n;i++)
        {
            if(i>n-m)
            {
                printf("0");

                continue;
            }

            bool op = false;
            for(int j = 0;j<m;j++)
            {
                if(s[i+j] == p[j]) continue;

                if(j == m-1)
                {
                    if(s[i+j] == p[j])
                        continue;

                    else
                    {
                        op = true;

                        break;
                    }
                }

                if(s[i+j]==p[j+1] && s[i+j+1] == p[j])
                {
                    j++;
                }
                else
                {
                    op = true;
                    break;
                }
            }

            if(op) printf("0");
            else printf("1");
        }

        printf("\n");
    }

    return 0;
}
