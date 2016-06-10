/*************************************************************************
    > File Name: A.cpp
    > Author: JueChen
    > Mail: libiao0730@Gmail.com 
    > Created Time: 2016年06月09日 星期四 16时23分34秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;

	int n,m;

	cin>>T;

	while(T--)
	{
		cin>>n>>m;

		cout<< (n/m+(n%m?1:0)) <<endl;
	}
	return 0;
}
