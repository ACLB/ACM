#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long LL;
const LL INF =  0x3f3f3f3f3f3f3f3f;
const int maxn  = 1234;
int n,m;
vector<pair<int,LL> >E[maxn];
LL val[maxn];
LL dis[maxn];
int q[maxn*20][2];
LL ans[maxn*20];
bool vis[maxn];
void spfa(int s) {
    for(int i =1; i<=n; i++) dis[i] = INF,vis[i] = false;
    queue<int>Q;
    Q.push(s);
    dis[s] = 0 ;
    vis[s] = true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i<E[u].size(); i++) {
            int v = E[u][i].first;
            if(val[v] > val[s]) continue;
            if(dis[v] > dis[u] + E[u][i].second) {
                dis[v] = dis[u] + E[u][i].second;
                if(!vis[v]) {
                    Q.push(v);
                    vis[v] = true;
                }
            }
        }
        vis[u] = false;
    }
}
int main() {
    int x,y; LL z;
    while(~scanf("%d %d",&n,&m) && (n+m)) {
        for(int i = 1;i<=n; i++ ) E[i].clear();
        for(int i = 1; i<=n; i++) scanf("%lld",&val[i]);
        for(int i = 1; i<=m; i++) {
            scanf("%d %d %lld",&x,&y,&z);
            E[x].push_back(make_pair(y,z));
            E[y].push_back(make_pair(x,z));
        }
        scanf("%d",&m);
        for(int i = 1; i<=m; i++) {
            scanf("%d %d",&q[i][0],&q[i][1]);
            ans[i] = INF;
        }
        for(int i = 1; i<=n; i++) {
            spfa(i);
            for(int j = 1; j<=m; j++) {
                ans[j] = min(ans[j],dis[q[j][0]]+dis[q[j][1]] + val[i]);
            }
        }
        for(int i = 1; i<=m; i++) {
            if(ans[i] >= INF) ans[i] = -1;
            printf("%lld\n",ans[i]);
        }
        printf("\n");

    }
    return 0;
}
/*
6 7
1 2 3 4 5 6
1 2 1
2 3 2
3 4 3
4 5 4
1 5 5
2 5 2
1 4 3
5
1 4
2 3
1 5
3 5
1 6
2 1
10 20
1 2 5
1
1 2
0 0
*/

