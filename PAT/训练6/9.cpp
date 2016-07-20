#include <bits/stdc++.h>

using namespace std;

int pre[1100];

int Du[1100];

int Find(int x)
{
    return pre[x] == 0?x:pre[x] = Find(pre[x]);
}

void Union(int x,int y)
{
    int Fx = Find(x);

    int Fy = Find(y);

    if(Fx!=Fy) pre[Fx] = Fy;
}

int main()
{
    int n,m,u,v;

    cin>>n>>m;

    for(int i = 0;i<m;i++)
    {
        cin>>u>>v;

        Union(u,v);

        Du[u]++;

        Du[v]++;
    }

    bool flag = false;
    int num = 0;
    for(int i = 1;i<=n;i++)
    {
        if(!pre[i]) num++;
    }

    if(num>1) flag = true;

    num= 0;
    for(int i =1;i<=n;i++)
    {
        if(Du[i]%2!=0) num++;
    }

    if(num) flag = true;

    if(flag) cout<<0<<endl;

    else cout<<1<<endl;

    return 0;
}
