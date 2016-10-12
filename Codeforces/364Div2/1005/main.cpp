#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
int main()
{
=======
<<<<<<< HEAD
int main()
{
=======
typedef long long LL;

const int Max = 210000;

vector<int>E[Max];

bool vist[Max],vis[Max];

int n,k;

LL ans;

int num[Max];

void dfs(int u,int fa)
{
    if(vist[u])
    {
        num[u]++;
    }


    vis[u] = true;

    int Mi = 0;

    for(int i = 0;i<E[u].size();i++)
    {
        if(E[u][i] == fa) continue;

        dfs(E[u][i],u);

        Mi+=num[E[u][i]];

        ans += min(k*2-num[E[u][i]],num[E[u][i]]);
    }

    num[u]+=Mi;


}

int main()
{

    scanf("%d %d",&n,&k);

    int u,v;

    for(int i = 0;i<k*2;i++)
    {
        scanf("%d",&u);

        vist[u] = true;
    }

    for(int i = 0;i<n-1;i++)
    {
        scanf("%d %d",&u,&v);

        E[u].push_back(v);

        E[v].push_back(u);
    }

    ans =0;

    for(int i = 1;i<=n;i++)
    {
        if(vist[i] &&!vis[i])
        {
            dfs(i,-1);
        }
    }

    cout<<ans<<endl;

>>>>>>> e0a5ae877837cf03b24e96e02237c6251abde0bb
>>>>>>> origin/master
    return 0;
}
