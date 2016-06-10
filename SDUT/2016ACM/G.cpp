/*************************************************************************
    > File Name: G.cpp
    > Author: JueChen
    > Mail: libiao0730@Gmail.com 
    > Created Time: 2016年06月09日 星期四 18时20分21秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int	T;

	LL n;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%lld",&n);

		if(n%2) printf("0\n");
		else 
		{
			int s = 0 ;
			while(n)
			{
				if(n%2) s++;

				n/=2;
			}

			LL ans = (LL(pow(3,s))-3)/6;

			printf("%lld\n",ans);
		}
	}
	return 0;
}
