#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5+100;
int dp[2][30][2];
char str[1000000];
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int len = strlen(str);
        bool op =0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<len;i++)
        {
            int j = str[i]-'a';
                 if(str[i] - 'a' == j) {
                     if(dp[!op][j][0] == -1) 
                     {
                         dp[op][j][0] = 0;
                         dp[op][j][1] = 1;
                     }
                     if(dp[op][str[i]-'a'][0]< dp[!op][j][0]+1) 
                     {
                         dp[op][str[i]-'a'][0] = dp[!op][j][0]+1;
                         dp[op][str[i]-'a'][1] = dp[!op][j][1]+1;
                     }
                     else if(dp[op][str[i]-'a'][0] == dp[!op][j][0]+1) 
                     {
                         dp[op][str[i]-'a'][1] = max(dp[op][str[i]-'a'][1],dp[!op][j][1]+1);
                     }
                 }
            for(j =0;j<26;j++) 
            {
                if( j== str[i]-'a') continue;
                if(dp[!op][j][0] == -1) continue;
                if(dp[op][str[i]-'a'][0]<dp[!op][j][0]) {
                         dp[op][str[i]-'a'][0] = dp[!op][j][0];
                         dp[op][str[i]-'a'][1] = dp[!op][j][1]+1;
                     }
                     else if(dp[op][str[i]-'a'][0] == dp[!op][j][0]) {
                         dp[op][str[i]-'a'][1] = max(dp[op][str[i]-'a'][1],dp[!op][j][1]+1);
                     }

                dp[op][j][0]  =dp[!op][j][0];
                dp[op][j][1] = dp[!op][j][1];
            }
            op =!op;
        }
        op =!op;
        int Mi = 0,sum = 0;
        for(int i = 0;i<26;i++) {
            if(Mi<dp[op][i][0]) {
                Mi = dp[op][i][0];
                sum = dp[op][i][1];
            }
            else if(Mi ==dp[op][i][0])  sum = max(sum,dp[op][i][1]); 
        }
        printf("%d\n",sum);
    }
    return 0;
}
