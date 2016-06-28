/*************************************************************************
  > File Name: B.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com
  > Created Time: 2016年06月27日 星期一 15时47分13秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int a[110];

int main()
{
	int n;

	cin>>n;

	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}

	for(int i = n;i >= 1; i--)
	{
		for(int j = 1;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);

				printf("%d %d\n",j,j+1);
			}
		}
	}

	return 0;
}
