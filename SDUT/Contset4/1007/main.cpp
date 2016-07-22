#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int Max = 251000;

typedef struct node
{
    int Id;

    node *next[26];
}No;

char s[15],t[15];

int num;

int pre[Max*2];

int deg[Max*2];

No * Creat()
{
    No *p;

    p = new No;

    p->Id = -1;

    for(int i = 0;i<26;i++) p->next[i] = NULL;

    return p;
}

int Build(No * p,char *str)
{
    int len = strlen(str);

    int ne;

    for(int i = 0;i<len;i++)
    {
        ne = str[i]-'a';

        if(p->next[ne] == NULL) p->next[ne] = Creat();

        p = p->next[ne];
    }

    if(p->Id == -1) p->Id = ++num;

    return p->Id;
}

int Find(int x)
{
    return pre[x] == 0?x:pre[x] = Find(pre[x]);
}

void Union(int x,int y)
{
    int Fx = Find(x);

    int Fy = Find(y);

    if(Fx != Fy)
    {
        pre[Fx] = Fy;
    }
}

int main()
{
    No *root;

    root = Creat();

    num = 0;

    memset(pre,0,sizeof(pre));

    memset(deg,0,sizeof(deg));

    while(~scanf("%s %s",s,t))
    {
        int u = Build(root,s);

        int v = Build(root,t);

        deg[u]++;

        deg[v]++;

        Union(u,v);


    }

    int cnt1 = 0;

    int cnt2 = 0;

    for(int i = 1;i<=num;i++)
    {
        if(Find(i)== i)
        {
            cnt1++;
        }

        if(deg[i]%2)
        {
            cnt2++;
        }

        if(cnt1>1 ||cnt2>2) break;
    }
    if(cnt1<=1&&(cnt2 ==0 || cnt2 == 2)) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}
