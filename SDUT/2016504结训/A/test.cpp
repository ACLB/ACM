#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <ctime>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#define LL long long
#define Pr pair<int,int>
#define fread(ch) freopen(ch,"r",stdin)
#define fwrite(ch) freopen(ch,"w",stdout)

using namespace std;
const int INF = 0x3f3f3f3f;
const int msz = 10000;
const int mod = 1e9+7;
const double eps = 1e-8;

int dir[][8] = {{ 0, 0, 1,-1, 1,-1, 1,-1},
				{ 1,-1, 0, 0, 1,-1,-1, 1}};

int dis[1100];
int eg[1100][1100];
int mp[50][50];
bool vis[1100];
int id[50][50];
int val[1100];
int tp,n,m;
int s,t;

bool in(int x,int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs(int x,int y)
{
	queue <Pr> q;
	q.push(Pr(x,y));
	id[x][y] = tp;
	int c = mp[x][y];
	Pr p;

	val[tp] = 0;
	int xx,yy;
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		x = p.first;
		y = p.second;
		val[tp]++;

		for(int i = 0; i < 8; ++i)
		{
			xx = x+dir[0][i];
			yy = y+dir[1][i];

			if(!in(xx,yy) || id[xx][yy] || mp[xx][yy] != c) continue;
			q.push(Pr(xx,yy));
			id[xx][yy] = tp;
		}
	}
	tp++;
}

int Dijkstra()
{
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
	int u;
	dis[s] = 0;

	while(1)
	{
		u = -1;
		for(int i = s; i <= t; ++i)
			if(!vis[i] && (u == -1 || dis[i] < dis[u])) u = i;

		//printf("*%d %d\n",u,dis[u]);
		if(u == t) return dis[u];
		vis[u] = 1;

		for(int i = s; i <= t; ++i)
		{
			if(!vis[i] && dis[i] > dis[u]+eg[u][i])
			{
				dis[i] = dis[u]+eg[u][i];
			}
		}
	}
}

int main()
{
	fread("data1.in");
	fwrite("out.out");

	while(~scanf("%d%d",&n,&m))
	{
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%d",&mp[i][j]);

		memset(id,0,sizeof(id));
		tp = 1;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(id[i][j]) continue;
				bfs(i,j);
			}
		}

		int xx,yy;
		s = 0;
		t = tp;
		memset(eg,INF,sizeof(eg));

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				//printf("%d %d %d %d\n",i,j,id[i][j],val[id[i][j]]);
				if(j == 0) eg[s][id[i][j]] = min(eg[s][id[i][j]],val[id[i][j]]);
				else if(j == m-1) eg[id[i][j]][t] = min(eg[id[i][j]][t],0);

				for(int k = 0; k < 8; ++k)
				{
					xx = i+dir[0][k];
					yy = j+dir[1][k];
					//printf("%d %d->%d %d\n",i,j,xx,yy);
					if((!in(xx,yy)) || id[i][j] == id[xx][yy]) continue;
					//printf("%d %d %d\n",id[i][j],id[xx][yy],val[id[xx][yy]]);
					eg[id[i][j]][id[xx][yy]] = min(eg[id[i][j]][id[xx][yy]],val[id[xx][yy]]);
				}
			}
		}

		//for(int i = s; i <= t; ++i)
		//{
		//	//printf("%d\n",i);
		//	for(int j = s; j <= t; ++j)
		//	{
		//		if(j != s) putchar(' ');
		//		printf("%d",eg[i][j]);
		//	}
		//	puts("");
		//}
		printf("%d\n",Dijkstra());
	}

	return 0;
}



/**************************************
	Problem id	: SDUT OJ C 
	User name	: zxw140208刘子祥 
	Result		: Wrong Answer 
	Take Memory	: 1268K 
	Take Time	: 40MS 
	Submit Time	: 2016-08-24 20:50:53  
**************************************/
