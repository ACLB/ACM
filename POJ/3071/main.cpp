#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
#define clc(x,d) memset(x,d,sizeof(x))
#define long long LL

using namespace std;

const int Max = 1e6+100;
const int Mod = 1e9+7;
const double Pi = acos(-1.0);
const double eps = 1e-6;
double p[200][200];
double dp[8][200];
int n;
int main() {
    while(~scanf("%d",&n)&&n!=-1) {
        for(int i = 0;i<(1<<n);i++) {
            for(int j = 0;j<(1<<n);j++) 
                scanf("%lf",&p[i][j]);
        }
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<(1<<n);i++) dp[0][i] = 1;
        for(int i =  1;i <= n; i++) {
            for(int j = 0;j<(1<<n);j++) {
                int t = j>>(i-1);
                if(t&1) {
                    for(int k = t*(1<<(i-1))-1;k>=(t-1)*(1<<(i-1));k--) {
                        dp[i][j] += dp[i-1][j]*dp[i-1][k]*p[j][k];
                    }
                }
                else {
                    for(int k = (t+1)*(1<<(i-1));k<(t+2)*(1<<(i-1));k++) {
                        dp[i][j] += dp[i-1][j]*dp[i-1][k]*p[j][k];
                    }
                }
            }
        }
        int Id  = 0;
        for(int i = 0;i<(1<<n);i++){
            if(dp[n][i] > dp[n][Id]) Id = i;
        }
        printf("%d\n",Id+1);
    }
    return 0;
}
