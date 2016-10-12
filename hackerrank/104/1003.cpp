#include <bits/stdc++.h>
#define ww(x) freopen(x,"w",stdout)
#define rr(x) freopen(x,"r",stdin)
using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double Pi = acos(-1.0);
const int Max = 1e5+100;
vector<int>E[Max];
int n,m;
int Du[Max];
int tp[Max];
int ans[Max];
bool vis[Max];
bool dfs(int st,bool pp) {
    if(st>n) return false;
    int num =n+1;
    for(int i = 1;i<=n;i++) {
        if(Du[i] == 0&&!vis[i]) {
            if(pp) {
                num = min(i,num);
                continue;
            }
            else if(i>tp[st]) num = min(i,num);
        }
    }
    if(pp) {
        ans[st] = num; vis[num] = true;
        for(int i = 0;i<E[num].size();i++) Du[E[num][i]]--;
        dfs(st+1,pp);
        return true;
    }
    for(int i = 0;i<E[tp[st]].size();i++) {
        Du[E[tp[st]][i]]--;
    }
    vis[tp[st]] = true;
    bool flag = dfs(st+1,pp);
    if(flag) {
        ans[st] = tp[st];
        vis[tp[st]] = false;
        return true;
    }
    else {
        if(num == n+1) {
            ans[st] = tp[st] ;
            vis[tp[st]] = false;
            for(int i = 0;i<E[tp[st]].size();i++)  Du[E[tp[st]][i]]++;
            return false;
        }
        else {
            for(int i = 0;i<E[tp[st]].size();i++)  Du[E[tp[st]][i]]++;
            vis[tp[st]] = false;
            ans[st] = num; 
            vis[num] = true;
            for(int i= 0;i<E[num].size();i++) Du[E[num][i]]--;
            dfs(st+1,true);
            vis[num] = false;
            return true;
        }
    }
    return false;
}
int main() {
    int u,v;
    memset(Du,0,sizeof(Du));
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++) {
        scanf("%d %d",&u,&v);
        E[u].push_back(v);
        Du[v]++;
    }
    for(int i = 1;i<=n;i++) scanf("%d",&tp[i]);
    memset(vis,false,sizeof(vis));
    int flag = dfs(1,false);
    if(flag){
        for(int i = 1;i<=n;i++) {
            if(i != 1) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}
