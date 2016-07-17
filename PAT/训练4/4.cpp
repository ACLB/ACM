#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char s[50];

int main()
{
    scanf("%s",s);

    int len =strlen(s);

    for(int i =0 ;i<len;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            printf("$");
        }
        else printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}
