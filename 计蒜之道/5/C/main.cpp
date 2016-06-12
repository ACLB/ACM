#include <bits/stdc++.h>

using namespace std;

char s[11000];

int main()
{
    bool flag = false;

    scanf("%s",s);

    int len = strlen(s);

    if(len == 1) flag = true;

    else if(s[0] == s[len-1] && (s[0] == '\"'||s[0] == '\'' ))
    {
        for(int i = 1; i<len-1; i++)
        {
            if(s[i]>='a' && s[i] <= 'z') continue;

            if(s[i] == '\\' && i == len-2) flag = true;

            if(s[i] == '\\' && s[i+1] == '\\')
            {
                i++;

                continue;
            }

            if(s[i] == '\\' && (s[i+1]>='a'&&s[i+1]<='z'))
            {
                flag = true;

                break;
            }

            if(s[i] == '\\' && (s[i+1] == '\''||s[i+1] == '\"'))
            {
                i++;

                continue;
            }

            if((s[i] == '\'' && s[0] == '\'') || (s[i] == '\"' && s[0] == '\"'))
            {
                flag = true;
                break;
            }
        }
    }
    else flag = true;

    if(flag) printf("No\n");

    else printf("Yes\n");

    return 0;
}
