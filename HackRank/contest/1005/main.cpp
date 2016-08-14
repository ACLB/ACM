#include <bits/stdc++.h>

using namespace std;
const int Max = 3*1e5;

int s[Max];

int len;

int next[Max];

char op[3];

int main()
{
    int n,data;

    next[0] = -1;

    scanf("%d",&n);

    len = 0;


    while(n--)
    {
        scanf("%s",op);

        if(op[0] == '+')
        {
            scanf("%d",&data);

            s[len++] = data;
            next[len] = 0;

            int t = next[len-1];

            while(t!=-1)
            {
                if(s[t+1] == data && t+1<len-1)
                {
                    next[len] = t+1;

                    break;
                }
                t = next[t];

            }

        }
        else
        {
            len--;
        }

        if(next[len] == 0) printf("0\n");
        else {
            printf("%d\n",next[len]+1);
        }


    }
    return 0;
}
