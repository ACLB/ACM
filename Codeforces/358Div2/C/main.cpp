#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n;

LL va[100100];

vector<pair<LL,LL>>Tr[100100];

LL sum[100100];

LL num[100100];

void DFS(int u)
{
    num[u] = 1;

    for(auto s : Tr[u])
    {
        sum[s.first] = sum[u] + s.second;

        DFS(s.first);

        num[u]+=num[s.first];


    }
}

int ans;

multiset<LL>M;

void dfs(int u)
{
    if(sum[u] - *M.begin() > va[u]) ans += num[u];
    else
    {
        for(auto s : Tr[u])
        {
            M.insert(sum[u]);

            dfs(s.first);

            M.erase(sum[u]);
        }
    }
}

int main()
{
    LL u,w;

    cin>>n;

    for(int i = 1;i<=n;i++) cin>>va[i];

    for(int i = 2;i<=n;i++) cin>>u>>w,Tr[u].push_back(make_pair(i,w));

    sum[1] = 0; DFS(1);

    M.insert(0); ans = 0;

    dfs(1);

    cout<<ans<<endl;

    return 0;
}
