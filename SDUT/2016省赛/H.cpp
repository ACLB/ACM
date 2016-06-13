/*************************************************************************
    > File Name: H.cpp
    > Author: JueChen
    > Mail: libiao0730@Gmail.com 
    > Created Time: 2016年06月09日 星期四 18时15分12秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int l,r;
}e[11111];

int top;

char s[11111];

char c[11111][1111];

char op[11111];

int main()
{
	int T;

	scanf("%d",&T);

	while(T--)
	{
		memset(s,0,sizeof(s));

		int pos = 0;

		top = 0;

		scanf("%s",op);

		while(1)
		{
			scanf("%s",op);

			int len = strlen(op);

			int num = 0,i = 0;

			for(i = 0;i < len; i++)
			{
				if(op[i] != '[')
					c[top][i] = op[i];
				else break;
			}

			c[top][i] = '\0';

			for(i++ ;i < len; i++)
			{
				if(op[i] == ']') break;
				num = num * 10 + op[i] -'0';
			}

			e[top].l = pos;

			e[top].r = pos+num;

			pos+=num;

			top++;

			char ss = getchar();

			if(ss == '\n') break;
		}
		while(1)
		{
			scanf("%s",op);
			
			if(op[0] == 'r')
			{
				scanf("%s",op);

				break;
			}

			if(op[0] == 'c') 
			{
				scanf("%s", op);

				for(int i = 0;i < top; i++)
				{
					if(strcmp(op,c[i]) == 0)
					{
						for(int j = e[i].l ; j < pos; j++)
						{
							if(s[j] == '\0') break;

							printf("%c",s[j]);
						}

						printf("\n");

						break;
					}
				}
			}
			else if(op[0] == 'g')
			{
				scanf("%s",op);

				for(int i = 0 ;i < top; i++)
				{
					if(strcmp(op,c[i]) == 0)
					{
						gets(op);

						int len = strlen(op);

						int k = 1,j;

						//while(op[k] == ' ' && k < len) k++;

						for( j = e[i].l ; j < e[i].r && k < len; j++, k++)
						{
							s[j] = op[k];
						}

						if(j < e[i].r)
						{
							s[j] = '\0';
						}

						break;
					}
				}
			}
		}
	}

	return 0;
}
