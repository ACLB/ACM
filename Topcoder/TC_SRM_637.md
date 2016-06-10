#### TopCoder SRM 637 Div2 A

> 题意：两个人玩游戏，每一出的数大的人得一分，现在给你两个出数的顺序，判断第一个人的得分。

```c++
#include <bits/stdc++.h>

using namespace std;

class GreaterGameDiv2
{
	public :
	
	int calc(vector <int> snuke, vector <int> sothe)
	{
		int sum = 0;
		
		int n = snuke.size();
		
		for(int i = 0;i<n;i++)
		{
			sum  += (snuke[i]>sothe[i]?1:0);
		}
		
		return sum;
	}
};
```



#### TopCoder SRM 637 Div2 B



> 题意：给你一个2*n的矩阵，每个小格子是'.'或者'#','.'表示是白的格子，'#'表示黑色格子，问最多可以将白的格子涂黑是的还存在一条从左到右只有白色的格子组成的路径（可以上下移动）。
>
> 思路：共有两个起点，从每一个起点开始，BFS到第n列的最少经过白色格子的数量。表明这条路径是不可以涂的，那么将其他的白色的格子的数量就是答案。

```c++
#include <bits/stdc++.h>

using namespace std;

struct node
{
	int x,y,d;
	
	node(){}
	
	node(int _x,int _y,int _d):x(_x),y(_y),d(_d){}
};

int Dir[][2] = {{0,1},{1,0},{-1,0}};

class PathGameDiv2
{	
	public:
	
	int ans ,n;
	
	bool vis[3][110];
	
	vector <string> s;
	
	bool Judge(int x,int y)
	{
		if(x>=0&&x<2&&y>=0&&y<n&&s[x][y]!='#'&&!vis[x][y]) return true;
		
		return false;
	}
	
	void bfs(int x,int y)
	{
	
		memset(vis,false,sizeof(vis));
		
		queue<node>Q;
		
		Q.push(node(x,y,1));
		
		node u,v;
		
		vis[x][y] = true;
		
		while(!Q.empty())
		{
			u = Q.front();
			
			Q.pop();
			
			if(u.y == n-1)
			{
				ans = min(ans,u.d);
			}
			
			for(int i = 0;i<3;i++)
			{
				v.x = Dir[i][0] + u.x;
				
				v.y = Dir[i][1] + u.y;
				
				v.d = u.d + 1;
				
				if(Judge(v.x,v.y))
				{
					vis[v.x][v.y] = true;
					
					Q.push(v);
				}
			}
		}
		
	} 
	
	int calc(vector <string> board)
	{
		s = board;
		
		n = s[0].size();
		
		ans = 2*n+1;
		
		int sum = 0;
		
		if(s[0][0] == '.')
		{
			bfs(0,0);
		}
		
		if(s[1][0] == '.')
		{
			bfs(1,0);
		}
		
		
		for(int i = 0;i<2;i++)
		{
			for(int j = 0;j<n;j++)
			{
				if(s[i][j] == '#')
				{
					sum++;
				}
			}
		}
		
		return 2*n-ans - sum;
	}
};
```



#### TopCoder SRM 637 Div2 C



> 题意：给你一个矩阵，每一个小格子中有一个字母，相邻的相同字母的为一个区域，相邻是指一个格子的八个方向。每一次都可以将一个区域涂成红色，问最少涂多少个格子使得从上到下没有路径，即涂上颜色的格子不能走，是不是使得不存在一条路径连接第一行和最后一行的需要涂的最少的格子的数量。
>
> 思路：刚看到这道题的时候一脸懵逼，后来看到其他人的博客，才发现自己好弱。首先我们将不同的区域找出来，那么相邻的区域之间可以相互的连接，同时如何使得从上到下没有路径，那么就是存在一条路径从左到右被涂上颜色，那么我们就可以将题意转化一下，首先将区域编号，缩为一个点，点权为区域中点的数量，相邻的区域连边，那么我们就可以得到一个图。在这个图中，我们要的是左边的区域到右边区域最小的路径点权和。那么问题就变为求最短路的问题啦，建立两个虚拟的点S,T,将左边的点所在的区域和S建立边，T和最右边的点所在的区域建立边。我们定义边权为以某点为起点的点权。最后的答案就是从S到T的最短路的边权和。

```c++
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

bool vis[110][110];
	
bool Vis[300];
	
int Map[300][300];
	
int pre[300][300];
	
int sum[300];
	
int S,T,n,m,num;
	
int Dis[300];
	
vector<string>str;
	
int Dir[][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

class ConnectingGameDiv2
{
	public:

	
	bool Judge(char c, int x, int y)
	{
		if(x >=0 && x < n && y >= 0 && y < m && str[x][y] == c && !vis[x][y]) return true;
		
		return false;
	}
	bool Judge(int x, int y)
	{
		if(x >= 0 && x < n && y >= 0 && y < m) return true;
		
		return false;
	}
	
	void dfs(char c,int x,int y)// 给区域编号
	{
		vis[x][y] = true;
		
		pre[x][y] = T;
		
		num++;
		
		for(int i =0;i<8;i++)
		{
			int Fx = x + Dir[i][0];
			
			int Fy = y + Dir[i][1];
			
			if(Judge(c, Fx, Fy))
			{
				dfs(c,Fx,Fy);
			}
		}
	}
	
	void SPFA()
	{
		memset(Vis,false,sizeof(Vis));
		
		memset(Dis,INF,sizeof(Dis));
		
		Dis[S] = 0;
		
		queue<int>Q;
		
		Q.push(S);
		
		Vis[S] = true;
		
		while(!Q.empty())
		{
			int u = Q.front();
			
			Q.pop();
			
			for(int i = S; i <= T; i++)
			{
				if(Dis[i] > Dis[u] + Map[u][i])
				{
					Dis[i] = Dis[u] + Map[u][i];
					
					if(!Vis[i])
					{
						Vis[i] = true;
						
						Q.push(i);
					}
				}
			}
			
			Vis[u] = false;
		}
		
		
	}

	int getmin(vector <string> board)
	{
		str  = board;
		
		n = str.size();
		
		m = str[0].size();
		
		memset(vis,false,sizeof(vis));
		
		S = 0; T = 1;
		
		for(int i = 0;i < n; i++)
		{
			for(int j = 0 ;j < m; j++)
			{
				if(vis[i][j]) continue;
				
				num = 0;
				
				dfs(str[i][j],i,j);
				
				sum[T++] = num;
			}
		}
		
		memset(Map,INF,sizeof(Map));
		
		for(int i =0 ;i<n;i++)
		{
			Map[S][pre[i][0]] = 0;
			
			Map[pre[i][0]][S] = sum[pre[i][0]];
			
			Map[T][pre[i][m-1]] = 0;
			
			Map[pre[i][m-1]][T] = sum[pre[i][m-1]]; 
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0 ; j < m;j++)
			{
				for(int k = 0;k < 8;k++)
				{
					int Fx = i+Dir[k][0];
					
					int Fy = j+Dir[k][1];
					
					if(Judge(Fx,Fy))
					{
						Map[pre[i][j]][pre[Fx][Fy]] = min(Map[pre[i][j]][pre[Fx][Fy]],sum[pre[i][j]]);
						
						Map[pre[Fx][Fy]][pre[i][j]] = min(Map[pre[Fx][Fy]][pre[i][j]],sum[pre[Fx][Fy]]);
					}
				}
			}
		}
		
		SPFA();
		
		return Dis[T];
	}
};
```
