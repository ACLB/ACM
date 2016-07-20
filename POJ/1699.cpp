/*************************************************************************
  > File Name: 1699.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年06月24日 星期五 10时22分52秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

char str[11][22];

int mp[11][11];

bool vis[11];

int n,ans;

int add(int s,int t)
{
	int len1 = strlen(str[s]);

	int len2 = strlen(str[t]);

	for(int i = 0,j;i<len1;i++)
	{
		for(j = 0;j<len2 &&i+j<len1;j++)
		{
			if(str[s][i+j] !=str[t][j]) break;
		}

		if(i+j == len1) return len2-j;
	}

	return len2;
}

void DFS(int u,int num,int len)
{
	if(len > ans) return ;

	if(num == n)
	{
		ans = min(ans,len);

		return ;
	}

	for(int i = 0;i<n;i++)
	{
		if(!vis[i])
		{
			vis[i] = true;

			DFS(i,num+1,len+mp[u][i]);

			vis[i] = false;
		}
	}
}

int main()
{
	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&n);

		for(int i = 0;i<n;i++)
			scanf("%s",str[i]);

		for(int i = 0;i<n;i++)
			for(int j =0;j<n;j++)
				mp[i][j] = add(i,j);

		memset(vis,false,sizeof(vis));

		ans = 210;

		for(int i = 0;i<n;i++)
		{
			vis[i] = true;

			DFS(i,1,strlen(str[i]));

			vis[i]=false;
		}

		printf("%d\n",ans);
	}

	return 0;
}
