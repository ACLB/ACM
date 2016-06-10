/*************************************************************************
    > File Name: LadderMap.cpp
    > Author: JueChen
    > Mail: libiao0730@Gmail.com 
    > Created Time: 2016年06月10日 星期五 09时55分53秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int Max =	550;

const int INF = 0x3f3f3f3f;

struct node
{
	int v,t,w;

	node(){}

	node(int _v,int _t,int _w):v(_v),t(_t),w(_w) {}
};

vector<node>E[Max];

int preT[Max],preD[Max];

int n,m,s,t;

int numT[Max],numD[Max];

int Dis[Max][2],Ti[Max][2];

bool vis[Max];

void SPFAT()
{
	memset(Ti,INF,sizeof(Ti));

	memset(vis,false,sizeof(vis));

	queue<int>Q;

	Ti[s][0] = 0 ;Ti[s][1] = 0;

	Q.push(s);

	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();

		for(int i = 0;i<E[u].size();i++)
		{
			if(Ti[E[u][i].v][0]>Ti[u][0]+E[u][i].t || (Ti[E[u][i].v][0] == Ti[u][0]+ E[u][i].t && Ti[E[u][i].v][1]>Ti[u][1]+1))
			{
				preT[E[u][i].v] = u;

				if(Ti[E[u][i].v][0] > Ti[u][0]+E[u][i].t)
					
					Ti[E[u][i].v][0] = Ti[u][0]+E[u][i].t;

				Ti[E[u][i].v][1] = Ti[u][1] + 1;

				if(!vis[E[u][i].v])
				{
					Q.push(E[u][i].v);

					vis[E[u][i].v] = true;
				}
			}
		}
		vis[u] = false;
	}
}

void SPFAD()
{
	memset(Dis,INF,sizeof(Dis));

	memset(vis,false,sizeof(vis));

	queue<int>Q;

	Dis[s][0] = 0 ;Dis[s][1] = 0;

	Q.push(s);

	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();

		for(int i = 0;i<E[u].size();i++)
		{
			if(Dis[E[u][i].v][0] > Dis[u][0] + E[u][i].w || (Dis[E[u][i].v][0] == Dis[u][0] + E[u][i].w && Dis[E[u][i].v][1] > Dis[u][1] + 1))
			{
				preD[E[u][i].v] = u;

				if(Dis[E[u][i].v][0] > Dis[u][0]+E[u][i].w)
	
					Dis[E[u][i].v][0] = Dis[u][0]+E[u][i].w;

				Dis[E[u][i].v][1] = Dis[u][1] + 1;

				if(!vis[E[u][i].v])
				{
					Q.push(E[u][i].v);

					vis[E[u][i].v] = true;
				}
			}
		}

		vis[u] = false;
	}
}
int main()
{
	int u,v,op,len,ti;

	scanf("%d %d",&n,&m);

	for(int i = 0;i<m;i++)
	{
		scanf("%d %d %d %d %d",&u,&v,&op,&len,&ti);

		E[u].push_back(node(v,ti,len));

		if(!op) 
			E[v].push_back(node(u,ti,len));
	}

	for(int i = 0; i <= n ; i++)
		preT[i] = preD[i] = -1;

	scanf("%d %d",&s,&t);

	SPFAT();

	SPFAD();

	numT[0] = numD[0] = 0;

	int ss = t;

	while(ss != -1)
	{
		numT[++numT[0]] = ss;
		ss = preT[ss];
	}

	ss = t;

	while(ss != -1)
	{
		numD[++numD[0]] = ss;
		ss = preD[ss];
	}

	bool flag = false;

	if(numD[0] != numT[0]) flag = true;
	else
	{
		for(int i = 1;i<=numD[0];i++)
		{
			if(numT[i] != numD[i])
			{
				flag =true;

				break;
			}
		}
	}
	if(flag)
	{
		printf("Time = %d: ",Ti[t][0]);
		
		for(int i = numT[0] ;i >= 1 ;i--)
		{
			if(i != numT[0]) printf(" => ");
			
			printf("%d",numT[i]);
		}
		
		printf("\n");
		
		printf("Distance = %d: ",Dis[t][0]);
		
		for(int i = numD[0] ;i >= 1;i--)
		{
			if(i != numD[0]) printf(" => ");
			
			printf("%d",numD[i]);
		}
		printf("\n");
	}
	else 
	{
		printf("Time = %d; Distance = %d: ",Ti[t][0],Dis[t][0]);
		
		for(int i = numT[0] ;i >= 1;i--)
		{
			if(i != numT[0]) printf(" => ");
			printf("%d",numT[i]);
		}
		printf("\n");
	}
	return 0;
}
