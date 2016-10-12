#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5+100;
bool vis[Max];
int a[Max];
vector<pair<int,int> >vp[Max];
int main(){
    int n,m,k,u,v,w;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1;i<=m;i++) {
        scanf("%d %d %d",&u,&v,&w);
        vp[u].push_back(make_pair(v,w));
        vp[v].push_back(make_pair(u,w));
    }
    int ans = -1;
    memset(vis,false,sizeof(vis));
    for(int i = 0;i<k;i++) {
        scanf("%d",&a[i]);
        vis[a[i]] = true;
    }
    for(int i = 0;i<k;i++) {
        for(int j = 0;j<vp[a[i]].size();j++) {
            if(vis[vp[a[i]][j].first]) continue;
            ans = ans == -1?vp[a[i]][j].second:min(ans,vp[a[i]][j].second);
        }
    }
    printf("%d\n",ans);
    return 0;
}
