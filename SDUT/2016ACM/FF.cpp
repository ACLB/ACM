/*************************************************************************
    > File Name: FF.cpp
    > Author: JueChen
    > Mail: libiao0730@Gmail.com 
    > Created Time: 2016年06月10日 星期五 08时40分51秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL Mod = 1e9+7;

LL Dp[55][55][55][4][55];

int main()
{
	int n1,n2,n3;

	int d1,d2,d3;

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d %d %d %d %d",&n1,&n2,&n3,&d1,&d2,&d3);

		memset(Dp,0,sizeof(Dp));

		for(int i = 1;i<=n1;i++)
		{
			for(int j = 1;j<=n2;j++)
			{
				for(int k = 1;k<=n3;k++)
				{
					for(int s = 1;s<=min(i,d1);s++)
					{
						Dp[i][j][k][0][s] = Dp[i][j][k][0][s]+Dp[i-s][j][k][0][s-1])%Mod+Dp[i-s][j][k][1][]
					}
				}
			}
		}
	}

	return 0;
}
