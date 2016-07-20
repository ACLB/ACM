#include <bits/stdc++.h>

using namespace std;

char s[1100];

int main()
{
    gets(s);

    int len = strlen(s);

    for(int i = 0;i<len;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i] = (25-(s[i]-'A'))+'A';
        }
    }

    cout<<s<<endl;

    return 0;
}
