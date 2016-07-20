/*************************************************************************
  > File Name: D.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年07月02日 星期六 11时19分25秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n,m,lcm,k,c;

LL GCD(LL a,LL b)
{
	return b == 0?a:GCD(b,a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;

	lcm = 1;

	for(int i = 0;i<n;i++)
	{
		cin>>c;

		if(!lcm) continue;

		lcm = (c*lcm)/GCD(lcm,c);

		lcm%=m;
	}
	if(lcm) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}
