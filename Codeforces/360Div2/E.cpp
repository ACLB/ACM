/*************************************************************************
  > File Name: E.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年07月03日 星期日 09时11分25秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int n,m,s;

bool dp[510][510][510];

vector<int>ans;

int main()
{
	scanf("%d %d",&n,&m);

	dp[0][0][0] = 1;

	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&s);

		for(int j = 0;j<=m;j++)
		{
			for(int k = 0;k<=j;k++)
			{
				dp[i][j][k] = dp[i-1][j][k];

				if(j>=s) dp[i][j][k] |= dp[i-1][j-s][k];

				if(k>=s) dp[i][j][k] |= dp[i-1][j-s][k-s];
			}
		}
	
	}

	for(int i =0;i<=500;i++)
	{
		if(dp[n][m][i]) ans.push_back(i);
	}

	printf("%d\n",ans.size());

	for(int i = 0;i<ans.size();i++)
	{
		if(i) printf(" ");

		printf("%d",ans[i]);
	}

	printf("\n");
	return 0;
}
