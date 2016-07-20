#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long LL;

char s[11000000];

int  a[11000000];

int T;

int main()
{
    scanf("%d",&T);

    while(T--)
    {
        scanf("%s",s);

        int len = strlen(s);

        int num = 0;

        int Min = 10;

        for(int i = 0;i<len;i++)
        {
            if(s[i] != '0') num++;

            if(s[i] != '0')
            {
                Min = min(Min,s[i] - '0');
            }
        }

        if(num <2 || len <2)
        {
            printf("Uncertain\n");
        }
        else
        {

            bool flag = false;

            sort(s,s+len);

            int n = 0;

            int st = Min;

            for(int i = 0,j = 0;i<len;i++)
            {
                if(s[i] - '0' == st)
                {
                    if(!flag)
                    {
                        flag = true;

                        continue;
                    }
                }

                a[j] = s[i]-'0';

                a[j] += Min;

                if(a[j]>=10)
                {
                    a[j] -= 10;

                    Min = 1;
                }
                else Min = 0;

                j++;

                n = max(n,j);
            }

            if(Min)
            {
                printf("%d",Min);
            }

            for(int i = n-1;i>=0;i--)
            {
                printf("%d",a[i]);
            }

            printf("\n");
        }
    }
    return 0;
}
