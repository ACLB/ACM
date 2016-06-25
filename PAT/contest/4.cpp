
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

char s[501000];
int main()
{
    gets(s);

    int len = strlen(s);

    len --;

    bool flag =false;

    while(len >= 0 && s[len] == ' ') len--;

    for(int i = len;i>=0;)
    {
        int j = i;

        while(j>=0 && s[j]!=' ')
        {
            j--;
        }

        i = j;

        j++;

        if(flag) printf(" ");
        else flag =true;

        while(j<=len && s[j] != ' ')
        {
            printf("%c",s[j]);

            j++;
        }

        j = i;

        while(j>=0 && s[j] == ' ') j--;

        i = j;
    }

    printf("\n");

    return 0;
}
