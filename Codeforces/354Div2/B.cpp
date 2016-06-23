/*************************************************************************
  > File Name: B.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年06月23日 星期四 09时56分41秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

double  Dp[11][11];

int main()
{
	int n,t;

	cin>>n>>t;

	memset(Dp,0,sizeof(Dp));

	Dp[1][1] = t;

	for(int i = 1;i<n;i++)
	{
		for(int j = 1;j<=i;j++)
		{
			if(Dp[i][j]<1) continue;

			Dp[i+1][j] += (Dp[i][j]-1)/2;

			Dp[i+1][j+1] += (Dp[i][j]-1)/2;
		}
	}

	int ans = 0;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=i;j++)
			if(Dp[i][j] >= 1) ans++;
	cout<<ans<<endl;
	return 0;
}
