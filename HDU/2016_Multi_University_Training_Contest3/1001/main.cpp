#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL Max = (1LL<<32)-1;

char s[110];

int main()
{
    while(~scanf("%s",s))
    {
        LL ans = 0;

        int len = strlen(s);

        for(int i = 0;i<len;i++)
        {
            ans = ans*10+s[i]-'0';

            if(ans > Max) break;
        }

        if(ans > Max || ans == 0)
        {
            printf("TAT\n");
        }
        else
        {
            int num = 0;

            while(ans >1)
            {
                num++;

                ans = floor(sqrt(ans));
            }

            printf("%d\n",num);
        }
    }
    return 0;
}
