/*************************************************************************
  > File Name: B.cpp
  > Author: JueChen
  > Mail:libiao0730@gmail.com 
  > Created Time: 2016年07月01日 星期五 08时41分55秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

char s[100100];

int main()
{
	scanf("%s",s);

	int len = strlen(s);

	printf("%s",s);
	for(int  i = len-1;i>=0;i--)
	{
		printf("%c",s[i]);
	}

	printf("\n");

	return 0;
}
