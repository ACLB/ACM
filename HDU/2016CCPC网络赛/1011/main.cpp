#include <bits/stdc++.h>

using namespace std;

const int Max = 1e5+100;

bool vis[30];

char s[Max];

int main()
{
    int T;

    scanf("%d",&T);

    for(int z = 1;z<=T;z++)
    {
        scanf("%s",s);

        int len = strlen(s);

        memset(vis,false,sizeof(vis));

        int ans = 0;

        for(int i = 0 ;i<len;i++)
        {
            if(vis[s[i]-'a']) continue;
            else
            {
                ans++;

                vis[s[i]-'a']  = true;
            }
        }

        printf("Case #%d: %d\n",z,ans);
    }

    return 0;
}
