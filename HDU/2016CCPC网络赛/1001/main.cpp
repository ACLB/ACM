#include <bits/stdc++.h>

using namespace std;

const int Max = 11000000;

char s[Max];

int main()
{
    int num1,num2;

    int z =1;

    while(~scanf("%s",s))
    {
        int len = strlen(s);

        num1 = 0; num2 = 0;

        for(int i = 0;i<len;i++)
        {
            num1 = num1*10+s[i]-'0';

            num2 = num2*10+s[i]-'0';

            num1%=73;

            num2%=137;
        }

        if(num1 == num2 && num1 == 0) printf("Case #%d: YES\n",z++);
        else printf("Case #%d: NO\n",z++);
    }
    return 0;
}
