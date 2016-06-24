/*************************************************************************
  > File Name: 3411.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年06月24日 星期五 11时39分46秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

typedef struct node
{
	int c,p,r;
}Ro;

Ro R[150];

int n,m;

int u,v;

vector<pair<int,int> >E[110];

int visp[110],visr[110];

int ans;

void dfs(int u,int len)
{
	if(len>ans)
	{
		return ;
	}
	if(u == n)
	{
		ans = min(ans,len);

		return ;
	}
	for(int i = 0;i<E[u].size();i++)
	{
		if(visr[E[u][i].second]<m)
		{
			visr[E[u][i].second]++;

			if(!visp[R[E[u][i].second].c])
			{
				visp[E[u][i].first] ++;

				dfs(E[u][i].first,len+R[E[u][i].second].r);
			}
			else
			{
				visp[E[u][i].first] ++;

				dfs(E[u][i].first,len+R[E[u][i].second].p);
			}

			visr[E[u][i].second]--;

			visp[E[u][i].first] --;

		}
	}
}

int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		for(int i = 1;i<=n;i++)
		{
			E[i].clear();
		}

		for(int i = 0;i<m;i++)
		{
			scanf("%d %d",&u,&v);

			scanf("%d %d %d",&R[i].c,&R[i].p,&R[i].r);

			E[u].push_back(make_pair(v,i));
		}

		memset(visp,0,sizeof(visp));

		memset(visr,0,sizeof(visr));

		visp[1] = 1;

		ans = INF;

		dfs(1,0);

		if(ans == INF)
		{
			printf("impossible\n");
		}
		else printf("%d\n",ans);
	}
	return 0;
}
