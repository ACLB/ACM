/*************************************************************************
    > File Name: J.cpp
    > Author: JueChen
    > Mail: libiao0730@Gmail.com 
    > Created Time: 2016年06月09日 星期四 18时48分52秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int sum1,sum2,sum3;

char s1[10],s2[10];

int main()
{
	int n,m;

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&n,&m);

		sum1 = sum2 = sum3 = 0;

		int num =  0;
		for(int i = 0 ;i<n;i++)
		{
			scanf("%s %s",s1,s2);

			if(s1[0] =='C') continue;

			if(s1[0] == 'M')
			{
				sum2++;
			}
			else if(s1[0] == 'B')
			{
				sum1+=2;

				num++;
			}
			else if(s1[0] == 'O')
			{
				sum1+=2;

				sum3++;

				num++;
			}

		}

		int sum = sum2*2*num+sum1+sum3*(n-1);

		if(sum>=m) printf("Mrghllghghllghg!\n");
		else printf("Tell you a joke, the execution of Paladin.\n");
	}
	return 0;
}
