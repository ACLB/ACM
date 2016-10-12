#include <bits/stdc++.h>

using namespace std;

const int Max = 110000;

const int Mod =  1000000007;

int Next[Max];

char s[Max],t[Max];

bool vis[Max];

void GetNext()
{
    int len = strlen(s);

    int i = 0,j = -1;

    Next[0] = -1;

    while(i<len)
    {
        if(j == -1 || s[i] == s[j])
        {
            i++;

            j++;

            Next[i] = j;
        }
        else j = Next[j];
    }
}

void PP()
{
    GetNext();

    int len1 = strlen(s);

    int len2 = strlen(t);

    memset(vis,false,sizeof(vis));

    int i = 0 ,j = 0;

    while(i<len1)
    {
        if(j==-1 ||s[i]==t[j])
        {
            i++;

            j++;
        }
        else j = Next[j];

        if(j>=len2)
        {
            vis[i] = true;

            j = Next[j];
        }
    }

}

int dp[Max];
int main()
{
    int T;

    scanf("%d",&T);

    for(int z =1;z<=T;z++)
    {
        scanf("%s",s);

        scanf("%s",t);

        PP();

        memset(dp,0,sizeof(dp));

        dp[0] = 1;

        int len = strlen(s);

        int len2 = strlen(t);

        for(int i = 1;i<=len;i++)
        {
            dp[i] = dp[i-1];

            if(vis[i])
                dp[i] = (dp[i]+dp[i-len2])%Mod;
        }

        printf("Case #%d: %d\n",z,dp[len]);
    }
    return 0;
}
