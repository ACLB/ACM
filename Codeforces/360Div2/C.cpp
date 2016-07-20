/*************************************************************************
  > File Name: C.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年07月02日 星期六 10时09分43秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<int>E[100100];

int n,m;

int u,v;

bool vis[110110];

vector<int> ans[2];

int type[110100];

bool  op ;

void dfs(int u,int fa,int st)
{
	vis[u] = true;

	ans[st].push_back(u);

	type[u] = st;

	for(int i = 0;i<E[u].size();i++)
	{
		if(E[u][i] == fa) continue;

		if(vis[E[u][i]])
		{
			if(type[u] == type[E[u][i]])
			{
				op = true;

				return ;
			}
			else continue;
		}

		dfs(E[u][i],u,(st+1)%2);
	}
}

int main()
{
	scanf("%d %d",&n,&m);

	for(int i = 0;i<m;i++)
	{
		scanf("%d %d",&u,&v);

		E[u].push_back(v);

		E[v].push_back(u);
	}

	memset(vis,false,sizeof(vis));

	memset(type,-1,sizeof(type));

	op  = false;

	for(int i = 1;i<=n;i++)
	{
		if(op) break;

		if(!vis[i])
		{
			dfs(i,-1,0);
		}
	}

	if(op) printf("-1\n");
	else
	{
		printf("%d\n",ans[0].size());

		for(int i = 0;i<ans[0].size();i++)
		{
			if(i) printf(" ");

			printf("%d",ans[0][i]);
		}
		printf("\n");
		printf("%d\n",ans[1].size());

		for(int i = 0;i<ans[1].size();i++)
		{
			if(i) printf(" ");

			printf("%d",ans[1][i]);
		}
		printf("\n");
	}


	return 0;
}
