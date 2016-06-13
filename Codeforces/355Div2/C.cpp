#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL Mod = 1e9+7;

LL a[100];

LL ans;

char str[100100];

int main()
{
    for(int i = 0;i<64;i++)
    {
        for(int j = 0;j<64;j++)
        {
            if((i&j)<64)
            {
                a[i&j]++;
            }
        }
    }

    cin>>str;
    
    int len = strlen(str);

    ans = 1;

    for(int  i = 0;i<len;i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            ans = (ans * a[str[i]-'0'])%Mod;
        }
        else if(str[i]>='A' && str[i]<='Z')
        {
            ans = (ans * a[str[i]-'A'+10])%Mod;
        }
        else if(str[i]>='a' && str[i]<='z')
        {
            ans = (ans * a[str[i]-'a'+36])%Mod;
        }
        else if(str[i] == '-') ans = (ans*a[62])%Mod;

        else if(str[i] == '_') ans = (ans * a[63]) %Mod;
    }

    cout<<ans<<endl;
    return 0;
}
