/*************************************************************************
    > File Name: miana.cpp
    > Author: JueChen
    > Mail: libiao0730@Gmail.com 
    > Created Time: 2016年06月02日 星期四 14时07分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

typedef struct node
{
	LL s;
	 
	int d;

	bool operator < (const node &a)const
	{
		return s == a.s?d<a.d:s<a.s;
	}
}S;

S A[210000];

int main()
{
	int n;

	LL l,r;

	scanf("%d",&n);


	int num = 0;

	for(int i = 0 ;i<n;i++)
	{
		scanf("%lld %lld",&l,&r);

		A[num].s = l; A[num++].d = 1;

		A[num].s = r; A[num++].d = -1;

	}

	sort(A,A+num);

	int ans = 0;

	int sum =0 ;

	for(int i =0 ; i<num;i++)
	{
		sum+=A[i].d;

		ans = max(ans,sum);
	}

	printf("%d\n",ans);
	return 0;
}
