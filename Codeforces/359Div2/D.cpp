/*************************************************************************
  > File Name: D.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年06月27日 星期一 16时45分55秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int Max = 300100;

vector<int>E[Max];

int pre[Max],Big[Max],num[Max];

int ans[Max];

void dfs1(int u)
{
	num[u] = 1; 
	
	Big[u] = 0;

	for(int i = 0 ;i<E[u].size();i++)
	{
		pre[E[u][i]] = u;

		dfs1(E[u][i]);

		num[u]+=num[E[u][i]];

		Big[u] = max(Big[u],num[E[u][i]]);

	}
}

bool Judge(int u,int v)
{
	if(num[v]*2>=num[u]) return true;

	return false;
}

void dfs2(int u)
{
	if(num[u] == 1)
	{
		ans[u] = u;

		return ;
	}

	int M = 0;

	for(int i = 0;i<E[u].size();i++)
	{
		dfs2(E[u][i]);

		if(num[E[u][M]]<num[E[u][i]])
		{
			M = i;
		}
	}

	int c = ans[E[u][M]];

	while(!Judge(u,c))
	{
		c = pre[c];
	}

	ans[u] = c;
}

int main()
{
	int n,q,u;

	scanf("%d %d",&n,&q);

	for(int i = 2;i<=n;i++)
	{
		scanf("%d",&u);

		E[u].push_back(i);
	}
	
	pre[1] = 1;

	dfs1(1);

	dfs2(1);

	for(int i = 0;i<q;i++)
	{
		scanf("%d",&u);

		printf("%d\n",ans[u]);
	}

	return 0;
}
