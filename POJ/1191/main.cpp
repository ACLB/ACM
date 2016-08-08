#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int  n;

int a[10][10];

int dp[20][10][10][10][10];

int ok(int x1,int y1,int x2,int y2)
{
    int ans = a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];

    return ans*ans;
}

int dfs(int x1,int y1,int x2,int y2,int num)
{
    if(num == 1)
    {
        return ok(x1,y1,x2,y2);
    }

    if(dp[num][x1][y1][x2][y2]!=-1) return dp[num][x1][y1][x2][y2];

    int temp = INF;

    for(int i = x1;i<x2;i++)
    {
        temp= min(temp,min(dfs(x1,y1,i,y2,num-1)+ok(i+1,y1,x2,y2),dfs(i+1,y1,x2,y2,num-1)+ok(x1,y1,i,y2)));
    }
    for(int i = y1;i<y2;i++)
    {
        temp = min(temp,min(dfs(x1,y1,x2,i,num-1)+ok(x1,i+1,x2,y2),dfs(x1,i+1,x2,y2,num-1)+ok(x1,y1,x2,i)));
    }

    return dp[num][x1][y1][x2][y2]=temp;
}

int main()
{
    int val;

    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));

        memset(dp,-1,sizeof(dp));

        double sum = 0;

        for(int i = 1;i<=8;i++)
        {
            for(int j = 1;j<=8;j++)
            {
                scanf("%d",&val);
                sum+=val;
                a[i][j]=val+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
            }
        }

        sum/=n;

        double ans =dfs(1,1,8,8,n);

        printf("%.3f\n",sqrt(ans/n-sum*sum));
    }
    return 0;
}
