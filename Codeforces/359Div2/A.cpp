/*************************************************************************
  > File Name: A.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年06月27日 星期一 15时41分06秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n;

LL m,data;

char op[2];

int main()
{
	cin>>n>>m;


	int sum = 0 ;

	while(n--)
	{
		cin>>op>>data;

		if(op[0] == '+')
		{
			m+=data;
		}
		else 
		{
			if(m>=data)
			{
				m-=data;
			}
			else
			{
				sum++;
			}
		}
	}

	cout<<m<<" "<<sum<<endl;

	return 0;
}
