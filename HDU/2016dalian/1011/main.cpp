#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
typedef long long LL;
LL uni[maxn*3];
int tr[maxn*3];
vector<int>mp[maxn];
map<LL,int>Map;
int n,m;
bool vis[maxn];
LL k,sum;
int a[maxn];
void Init() {
    for(int i = 1;i<=n;i++) mp[i].clear();
    memset(tr,0,sizeof(tr)); sum = 0;
    memset(vis,false,sizeof(vis));
    Map.clear();
}
int lowbite(int x) {
    return (x&(-x));
}
LL qu(int x) {
    LL ans = 0;
    while(x>0) {
        ans+=tr[x];
        x-=lowbite(x);
    }
    return ans;
}
void add(int x,int d) {
    while(x<=m) {
        tr[x]+=d;
        x+=lowbite(x);
    }
}
void dfs(int u) {
    sum+=qu(Map[k/a[u]]);
    add(Map[a[u]],1);
    for(int i = 0;i<mp[u].size();i++) {
        dfs(mp[u][i]);
    }
    add(Map[a[u]],-1);
}
int main(){
    int T,u,v;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %lld",&n,&k);
        Init(); m = 0;
        for(int i = 1;i<=n;i++) {
            scanf("%d",&a[i]);
            uni[++m] = k/a[i];
            uni[++m] = a[i];
        }
        sort(uni+1,uni+m+1);
        uni[0] = 1;
        Map[uni[1]] = 1;
        for(int i = 2;i<=m;i++)
        {
            if(uni[uni[0]]!= uni[i]) {
                uni[++uni[0]] = uni[i];
                Map[uni[i]] = uni[0];
            }
        }
        m = uni[0];
        for(int i = 1;i<n;i++) {
            scanf("%d %d",&u,&v);
            mp[u].push_back(v);
            vis[v] = true;
        }
        for(int i = 1;i<=n;i++) {
            if(!vis[i]) {
                dfs(i);
                break;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
