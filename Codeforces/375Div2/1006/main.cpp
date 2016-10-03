#include <bits/stdc++.h>

using namespace std;
const int maxn = 210000;
vector<int>E[maxn];
vector<int>Ee[maxn];
bool vis[maxn];
int s,t,ds,dt;
int pre[maxn];
void dfs(int u,int num) {
    pre[u] =  num;
    vis[u] = true;
    for(int i = 0; i<E[u].size(); i++) {
        if(E[u][i]!=s && E[u][i]!=t &&! vis[E[u][i]]) {
            dfs(E[u][i],num);
            Ee[u].push_back(E[u][i]);
        }
    }
}
int Find(int x) {
    return pre[x] == -1?x:pre[x] = Find(pre[x]);
}
int main() {
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i = 1; i<=m; i++) {
        scanf("%d %d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    scanf("%d %d %d %d",&s,&t,&ds,&dt);
    memset(vis,false,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    int num = 0;
    for(int i  =1; i<n; i++) {
        if(i!=s && i!=t && !vis[i]) dfs(i,++num);
    }
    pre[s] = ++num;
    pre[t] = ++num;
    map<int,int>mp;
    map<int,int>mpp;
    printf("----\n");
    for(int i = 0; i<E[s].size(); i++) {
        mp[Find(E[u][i])] = 1;
    }
    int sum1 = 0;
    for(int i = 0; i<E[t].size(); i++) {
        if(sum1 == dt) break;
        if(!mp[Find(E[t][i])] && !mpp[Find(E[t][i])]) {
            mpp[Find(E[t][i])] = true;
            Ee[t].push_back(E[t][i]);
            sum1++;
        }
    }
    for(int i = 0; i<E[t].size(); i++) {
        if(sum1 == dt) break;
        if(mp[Find(E[t][i])] && !mpp[Find(E[t][i])]) {
            mpp[Find(E[t][i])] = true;
            Ee[t].push_back(E[t][i]);
            sum1++;
        }
    }
    int sum2 = 0;
    for(int i = 0; i<E[s].size(); i++) {
        if(sum2 == ds) break;
        if(!mpp[Find(E[s][i])]) {
            Ee[s].push_back(E[s][i]);
            sum2++;
        }
    }
    if(sum2 + sum1 == num) {
        printf("Yes\n");
        for(int i = 1; i<=n; i++) {
            for(int j = 0; j<Ee[i].size(); j++) printf("%d %d\n",i,E[i][j]);
        }
    } else printf("No\n");



    return 0;
}
