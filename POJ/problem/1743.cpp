#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int Max = 1e5+100;

struct node
{
    int now;

    int next;
}d[Max];// 链表，now表示元素的序号，next表示后继指针。

int val[Max][2]; // 为关键字，x为val[][1],y为val[][2]

int c[Max]; // 储存各元素值在链表d中的手指针。

int Rank[Max]; //储存各后缀的名次。

int SA[Max]; //储存各名次的后缀指针首指针

int pos[Max]; // 储存关键字递增序列中的后缀指针

char s[Max];

void Add_Value(int  u,int v,int i)
{
    d[i].next = c[u];

    c[u] = i;

    d[i].now = v;
}

void Radix_Sort(int l ,int r)
{
    for(int k = l;k>=0;k--)
    {
        memset(c,0,sizeof(c));

        for(int i = r;i>=1;i--)
        {
            Add_Value(val[pos[i]][k],pos[i],i);
        }

        int t = 0;

        for(int i = 1; i <= r;i++)
        {
            for(int j = c[i]; j ;j = d[j].next) pos[++t] = d[j].now;
        }
    }

    int t = 0 ;

    for(int i = 1;i<=r;i++)
    {
        if(val[pos[i]][0]!=val[pos[i-1]][0]||val[pos[i]][1]!=val[pos[i-1]][1]) 
            t++;

        Rank[pos[i]] = t;

    }
}

void GetSuffixArray()
{
    int len = strlen(s+1);

    int t = 1;
    
    while(t/2 <= len)
    {
        for(int i = 1;i<=len ;i++)
        {
            val[i][0] = Rank[i];

            val[i][1] = ((i+t/2) <=len ? Rank[i+t/2]:0);

            pos[i] = i;
        }

        Radix_Sort(1,len);

        t *= 2;

        for(int i = 1;i<=len;i++)
        {
            if(i != 1) printf(" ");

            printf("%d",Rank[i]);
        }
        printf("\n");
    }

    for(int i = 1;i<=len;i++)
    {
        SA[Rank[i]] = i;
    }
}

int main()
{

    while(~scanf("%s",s+1))
    {
        GetSuffixArray();
    }
    return 0;
}
