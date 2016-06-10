/*************************************************************************
    > File Name: C.cpp
    > Author: JueChen
    > Mail: libiao0730@Gmail.com 
    > Created Time: 2016年06月09日 星期四 16时52分40秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

struct node
{
	int v,w,next;
}E[22000];

int Head[1100],top;

int dis[1100];

int ff[1100][2],num;

bool vis[1100];

void Init()
{
	memset(Head,-1,sizeof(Head));

	memset(dis,INF,sizeof(dis));

	memset(vis,false,sizeof(vis));

	top = 0; num = 0;
}

void AddEdge(int u,int v,int w)
{
	E[top].v = v; E[top].w = w;

	E[top].next = Head[u];

	Head[u] = top++;
}

void SPFA(int s)
{
	vis[s] = true;

	dis[s] = 0;

	queue<int>Q;

	Q.push(s);

	while(!Q.empty())
	{
		int u = Q.front();

		Q.pop();

		for(int i = Head[u];i!=-1;i = E[i].next)
		{
			if(dis[E[i].v]> dis[u] + E[i].w)
			{
				dis[E[i].v] = dis[u] + E[i].w;

				if(!vis[E[i].v])
				{
					vis[E[i].v] = true;

					Q.push(E[i].v);
				}
			}
		}

		vis[u] = false;
	}
}

int main()
{	
	int T;

	int n,m;

	int u,v,w;

	scanf("%d",&T);

	while(T--)
	{
		Init();

		scanf("%d %d",&n,&m);

		for(int i = 0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);

			AddEdge(v,u,w);

			if(u == 0)
			{
				ff[num][0] = v;

				ff[num++][1] = w;
			}
		}

		SPFA(n+1);

		if(dis[0] == INF) printf("-1\n");
		else 
		{
			int ans = -1;
			for(int i = 0;i<num;i++)
			{

				if(dis[ff[i][0]]+ff[i][1] == dis[0])
				{
					if(ans == -1) ans = ff[i][0];

					else ans = min(ans,ff[i][0]);
				}
			}

			printf("%d\n",ans == n+1?0:ans);
		}
	}
	return 0;
}
