/*************************************************************************
    > File Name: K.cpp
    > Author: JueChen
    > Mail: libiao0730@Gmail.com 
    > Created Time: 2016年06月09日 星期四 18时32分11秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

char s[11000];

int main()
{
	int T;

	scanf("%d",&T);

	getchar();

	while(T--)
	{
		gets(s);

		int len = strlen(s);

		for(int i = 0;i<len;)
		{
			if(s[i] == ' ') printf("%c",s[i++]);

			else 
			{
				while(s[i] != ' '&&i<len) i++;

				for(int j = i-1;j>=0;j--)
				{
					if(s[j] ==' ')break;

					printf("%c",s[j]);
				}
			}
		}

		printf("\n");
	}
	return 0;
}
