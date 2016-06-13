/*************************************************************************
    > File Name: E.cpp
    > Author: JueChen
    > Mail: libiao0730@Gmail.com 
    > Created Time: 2016年06月09日 星期四 17时33分09秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

char M[110][110];

int main()
{
	int T;

	int n,m;

	scanf("%d",&T);

	while(T--)
	{
		int ans = 0;
		scanf("%d %d",&n,&m);

		for(int i = 0;i<n;i++)
			scanf("%s",M[i]);

		for(int i = 0;i<n;i++)
		{

			for(int j = 0;j<m;j++)
			{
				if(M[i][j] == '#') continue;

				int num  =0;
				if(i>0&&M[i-1][j] =='#') num++;

				if(j>0&&M[i][j-1] == '#') num++;

				if(i<n-1&&M[i+1][j] =='#') num++;

				if(j<m-1&&M[i][j+1] == '#') num++;

				if(num == 1) ans++;
			}
		}
		for(int i = 0;i<m;i++)
		{
			if(M[0][i] == '#') ans++;

			if(M[n-1][i] == '#') ans++;
		}

		for(int i = 0;i<n;i++)
		{
			if(M[i][0] == '#') ans++;

			if(M[i][m-1] == '#') ans++;
		}

		printf("%d\n",ans);
	}
	return 0;
}
