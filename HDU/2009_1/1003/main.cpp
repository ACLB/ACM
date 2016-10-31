#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

int n;
int G[maxn][maxn];
int row[maxn];
bool vis[maxn];

int dfs(int s) {
    for(int i = 1; i<=n; i++) {
        if(G[s][i] && !vis[i]) {
            vis[i] = true;
            if(!row[i] || dfs(row[i])) {
                row[i] = s;
                return 1;
            }
        }
    }
    return 0;
}
vector<pair<int,int> >vi;
int main() {
    while(~scanf("%d",&n)) {
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) scanf("%d",&G[i][j]);
        }
        memset(row,0,sizeof(row));
        int ans = 0;
        for(int i = 1; i<=n; i++) {
            memset(vis,false,sizeof(vis));
            ans+=dfs(i);

        }
        if(ans<n) {
            printf("-1\n");
        } else {
            vi.clear();
            for(int i = 1; i<=n; i++) {
                int j =1;
                for(; j<=n&&row[j]!=i; j++);
                if(i==j)continue;
                vi.push_back(make_pair(i,j));
                swap(row[i],row[j]);
            }
            printf("%d\n",vi.size());
            for(int i = 0; i<vi.size(); i++) printf("C %d %d\n",vi[i].first,vi[i].second);
        }
    }
    return 0;
}
