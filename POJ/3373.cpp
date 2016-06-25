/*************************************************************************
  > File Name: 3373.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年06月25日 星期六 13时20分04秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

char strn[110];

int k;

int Dp[110][11000];

int main()
{

	while(~scanf("%s",strn))
	{
		scanf("%d",&k);

		int len = strlen(strn);

		memset(Dp,0,sizeof(Dp));

		for(int i = 0;i<10;i++)
		{
			if( i != strn[len-1] - '0')
			{
				Dp[0][i%k] = 1;
			}
			else Dp[0][i%k] = 0;
		}
	}

	return 0;
}
