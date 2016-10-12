#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
int main()
{
=======
typedef long long LL;

const int Max = 110000;

bool x[Max];

bool y[Max];

int main()
{
    int n,m;

    scanf("%d %d",&n,&m);

    int u,v;

    LL ans1 = 0,ans2= 0;

    LL sum = 1LL*n*n;

    for(int i = 0;i<m;i++)
    {
        scanf("%d %d",&u,&v);

        if(!x[u]) ans1++;

        if(!y[v]) ans2 ++;

        x[u] = true;

        y[v]  = true;

        cout<<sum-(ans1*n+ans2*(n-ans1))<<endl;

    }


>>>>>>> origin/master
    return 0;
}
