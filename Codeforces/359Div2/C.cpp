/*************************************************************************
  > File Name: C.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年06月27日 星期一 16时21分58秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool vis[10];


bool Judge(int n ,int len)
{
	int sum = 0;

	while(n)
	{
		if(vis[n%7])
		{
			return false;
		}

		vis[n%7] = true;

		n/=7;

		sum++;
	}

	for(int i = sum;i<len;i++)
	{
		if(vis[0]) return false;

		vis[0] = true;
	}

	return true;
}

int n,m;

int main()
{
	cin>>n>>m;

	int len1 = 1 ,len2 = 1;

	int nn = n,mm = m;

	for(int i = 7;i<n;i*=7) len1++;

	for(int i = 7;i<m;i*=7) len2++;

	int ans  = 0 ;

	if(len1+len2 <= 7)
	{
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				memset(vis,false,sizeof(vis));

				if((i == j) || (!Judge(i,len1)) || (!Judge(j,len2))) continue;

				ans++;
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}
