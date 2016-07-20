/*************************************************************************
  > File Name: D.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年06月23日 星期四 10时33分02秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node
{
	int z,x,y,num;

	node(){}

	node(int _z,int _x,int _y,int _num):z(_z),x(_x),y(_y),num(_num){}
}op;

char mp[5][1100][1100];

char Ch[200];

int sx,sy,tx,ty;

int n,m;

bool vis[5][1100][1100];

int Dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool Dir_U(char c )
{
	if(c == '+' || c == '|' || c == '^' || c == 'L' || c== 'R' || c == 'D') return true;

	return false;
}

bool Dir_D(char c)
{
	if(c == '+' || c == '|' || c == 'v' || c == 'L' || c== 'R' || c == 'U') return true;

	return false;
}

bool Dir_L(char c)
{
	if(c == '+' || c == '-' || c == '<' || c == 'D' || c== 'R' || c == 'U') return true;

	return false;
}

bool Dir_R(char c)
{
	if(c == '+' || c == '-' || c == '>' || c == 'L' || c== 'D' || c == 'U') return true;

	return false;
}

bool Judge(int z,int x,int y)
{
	if((z>=0&&z<4) && (x >= 0 && x < n) && (y >= 0 && y < m) && !vis[z][x][y] && mp[z][x][y] != '*') return true;

	return false;
}

int BFS()
{
	memset(vis,false,sizeof(vis));

	queue<op>Q;

	Q.push(op(0,sx,sy,0));

	vis[0][sx][sy] = true;

	while(!Q.empty())
	{
		op u = Q.front(); Q.pop();

		op v;

		if(u.x == tx && u.y == ty)
		{
			return u.num;
		}

		for(int i = 0;i <=4;i++)
		{
			if(i<4)
			{
				v.z = u.z;

				v.x = u.x+Dir[i][0]; 

				v.y = u.y+Dir[i][1];

				v.num = u.num+1;
			}
			else 
			{
				v = u;

				v.z=(v.z+1)%4;

				v.num++;
			}

			if(i == 0 && Judge(v.z,v.x,v.y) && Dir_U(mp[u.z][u.x][u.y]) && Dir_D(mp[v.z][v.x][v.y]))
			{
				Q.push(v);

				vis[v.z][v.x][v.y] = true;
			}
			else if(i == 1 && Judge(v.z,v.x,v.y) && Dir_D(mp[u.z][u.x][u.y]) && Dir_U(mp[v.z][v.x][v.y]))
			{
				Q.push(v);

				vis[v.z][v.x][v.y] = true;
			}
			else if(i == 2 && Judge(v.z,v.x,v.y) && Dir_L(mp[u.z][u.x][u.y]) && Dir_R(mp[v.z][v.x][v.y]))
			{
				Q.push(v);

				vis[v.z][v.x][v.y] = true;
			}
			else if(i == 3 && Judge(v.z,v.x,v.y) && Dir_R(mp[u.z][u.x][u.y]) && Dir_L(mp[v.z][v.x][v.y]))
			{
				Q.push(v);

				vis[v.z][v.x][v.y] = true;
			}
			else if(i == 4 && Judge(v.z,v.x,v.y))
			{
				Q.push(v);

				vis[v.z][v.x][v.y] = true;
			}
		}
	}

	return -1;

}

int main()
{
	Ch['+'] = '+';

	Ch['-'] = '|';

	Ch['|'] = '-';

	Ch['>'] = 'v';

	Ch['^'] = '>';

	Ch['<'] = '^';

	Ch['v'] = '<';

	Ch['L'] = 'U';

	Ch['R'] = 'D';

	Ch['U'] = 'R';

	Ch['D'] = 'L';

	Ch['*'] = '*';

	scanf("%d %d",&n,&m);

	for(int i = 0;i<n;i++)
		scanf("%s",mp[0][i]);

	for(int k = 1; k < 4;k++)
	{
		for(int i = 0;i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				mp[k][i][j] = Ch[mp[k-1][i][j]];
			}
		}
	}

	scanf("%d %d %d %d",&sx,&sy,&tx,&ty);

	sx--, sy--,tx--, ty-- ;

	if(sx == tx && sy == ty)
	{
		printf("0\n");
	}
	else 
	{
		printf("%d\n",BFS());
	}

	return 0;
}
