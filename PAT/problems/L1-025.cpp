#include <bits/stdc++.h>

using namespace std;

char s[110];

int main()
{
    gets(s);

    int len = strlen(s);

    bool flag = false;

    int a = 0,b = 0;

    int num = 0;

    for(int i = 0;i<len;i++)
    {
        if(s[i] >= '0' && s[i]<='9')
        {
            if(num && b!=-1)
            {
                b = b*10+s[i]-'0';
            }
            else if(num ==0 && a!=-1)
                a = a*10+s[i]-'0';
        }
        else
        {
            if(s[i] == ' ')
            {
                if(num) b=-1;
                else num++;
            }
            else
            {
                if(num) b = -1;
                else a = -1;
            }
        }
    }

    if(a<=0 || a>1000)
    {
        printf("? ");
    }
    else printf("%d ",a);


    if(b<=0 ||b>1000)
    {
        printf("+ ?");
    }
    else printf("+ %d",b);

    if(a<= 0 || a>1000 || b<=0 || b>1000)
    {
        printf("= ?\n");
    }
    else printf("= %d\n",a+b);

    return 0;
}
