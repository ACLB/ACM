/*************************************************************************	
  > File Name: A.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年06月23日 星期四 09时37分18秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,data;

	int ans = 0 ;

	cin>>n;

	for(int i = 1;i<=n;i++)
	{
		cin >>data;

		if(data == 1 || data == n)
		{
			ans = max(ans,max(i,n-i+1));
		}
	}

	cout<<ans-1<<endl;
	return 0;
}
