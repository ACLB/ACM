/*************************************************************************
  > File Name: C.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年06月23日 星期四 10时09分10秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

char str[100100];

int main()
{
	int n, k, len;

	scanf("%d %d",&n,&k);

	scanf("%s",str);

	len = strlen(str);

	int  l = 0 ,num = 0,ans = 0;

	for(int i = 0;i<len;i++)
	{
		if(str[i] == 'a')
		{
			num++;
		}

		while(l<=i&&num>k)
		{
			if(str[l] == 'a')
			{
				num --;
			}

			l++;
		}
			
		ans = max(ans,i-l+1);
	}
	
	
	l = 0,  num = 0;

	for(int i = 0;i<len;i++)
	{
		if(str[i] == 'b')
		{
			num++;
		}

		while(l<=i&&num>k)
		{
			if(str[l] == 'b')
			{
				num --;
			}

			l++;
		}
			
		ans = max(ans,i-l+1);
	}
	
	printf("%d\n",ans);

	return 0;
}
