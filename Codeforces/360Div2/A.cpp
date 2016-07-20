/*************************************************************************
  > File Name: A.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年07月01日 星期五 08时27分53秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int n,m;

char s[110];

int main()
{
	cin>>n>>m;

	int ans = 0;

	int sum = 0;

	for(int i = 0;i<m;i++)
	{
		scanf("%s",s);


		bool flag = false;

		for(int j = 0 ;j<n;j++)
		{
			if(s[j]!='1')
			{
				flag = true;

				break;
			}
		}

		if(!flag)
		{
			sum = 0 ;
		}
		else 
		{
			sum++;

			ans = max(ans,sum);
		}

	}

	cout<<ans<<endl;

	return 0;
}
