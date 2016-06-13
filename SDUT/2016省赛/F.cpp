#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL Mod = 1e9+7;

LL Dp[55][55][55][4];

int d[4];

int main()
{
	int T;

	int n1,n2,n3,d1,d2,d3;

	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d %d %d %d %d %d",&n1,&n2,&n3,&d[1],&d[2],&d[3]);

		memset(Dp,0,sizeof(Dp));

		for(int i = n1;i>=0;i--)
		{
			for(int j = n2;j>=0;j--)
			{
				for(int k = n3;k>=0;k--)
				{
					for(int s = 1;s<=min(i,d[1]);s++)
					{
						if(i == n1 && j == n2 && k == n3)
						{
							Dp[i-s][j][k][0]  = (Dp[i-s][j][k][0]+1)%Mod;
						}

						else 
						{
							Dp[i-s][j][k][0] = ((Dp[i-s][j][k][0]+Dp[i][j][k][1])%Mod+Dp[i][j][k][2])%Mod;
						}
					}
					for(int s = 1;s<=min(j,d[2]);s++)
					{
						if(i == n1 && j == n2 && k == n3)
						{
							Dp[i][j-s][k][1]  = (Dp[i][j-s][k][1]+1)%Mod;
						}

						else 
						{
							Dp[i][j-s][k][1] = ((Dp[i][j-s][k][1]+Dp[i][j][k][0])%Mod+Dp[i][j][k][2])%Mod;
						}
					}
					for(int s = 1;s<=min(k,d[3]);s++)
					{
						if(i == n1 && j == n2 && k == n3)
						{
							Dp[i][j][k-s][2]  = (Dp[i][j][k-s][2]+1)%Mod;
						}

						else 
						{
							Dp[i][j][k-s][2] = ((Dp[i][j][k-s][2]+Dp[i][j][k][0])%Mod+Dp[i][j][k][1])%Mod;
						}
					}
				}
			}
		}

		LL ans = 0;

		ans = ((Dp[0][0][0][0]+Dp[0][0][0][1])%Mod+Dp[0][0][0][2])%Mod;

		printf("%lld\n",ans);
	}
	return 0;
}
