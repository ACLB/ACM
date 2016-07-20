#include <bits/stdc++.h>

using namespace std;

int n,m;

int pre[33000];

int num[33000];

int Find(int x)
{
    if(pre[x] == 0) return x;

    int Fx = pre[x];

    num[Fx] += num[x] ;

    num[x] = 0;


    return pre[x] = Find(Fx);

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
    scanf("%d %d",&n,&m);

    for(int i = 1;i<=n;i++)
    {
        num[i] = 1;
    }

    int u,v;
    for(int i = 1;i <= m ;i++)
    {
        scanf("%d",&u);

        for(int j = 1;j<=u;j++)
        {
            scanf("%d",&v);

            Union(v,n+i);
        }
    }

    int ans = 0;
    
    for(int i = 1;i<=n+m;i++)
    {
        Find(i);
        ans = max(ans,num[i]);
    }

    printf("%d\n",ans);
    return 0;
}
