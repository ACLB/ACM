#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5+100;
vector<int>E[Max];
int tp[Max],Du[Max];
int du[Max],an[Max];
bool vis[Max];
int n,m;
bool Check(int s) {
    memset(vis,false,sizeof(vis));
    for(int i = 1;i<=n;i++) du[i] = Du[i];
    for(int i  =1;i<s;i++) {
        for(int j = 0; j<E[tp[i]].size();j++) du[E[tp[i]][j]]--;
        vis[tp[i]] = true;
    }
    int ans = n+1;
    for(int i = 1;i<=n;i++) {
        if(du[i] == 0 && !vis[i]) {
            if(i>tp[s]) {
                ans = min(ans,i);
            }
        }
    }
    return ans != n+1;
}
int Search() {
    int l  =1,r = n;
    int ans = -1;
    while(l<=r) {
        int mid = (l+r)>>1;
        if(Check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r  =mid-1;
    }
    return ans;
}
void TP(int st) {
    priority_queue<int ,vector<int>,greater<int> >Q;
    for(int i = 1;i<=n;i++) if(du[i] == 0 && !vis[i]) Q.push(i);
    while(!Q.empty()) {
        int u = Q.top(); Q.pop();
        vis[u] = true;
        an[st++] = u;
        for(int i = 0;i<E[u].size();i++) {
            du[E[u][i]] --;
            if(!du[E[u][i]] && !vis[E[u][i]]) Q.push(E[u][i]);
        }
    }
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
    int ans = Search();
    if(ans == -1) {
        printf("%d\n",-1);
    }
    else {
        memset(vis,false,sizeof(vis));
        for(int i = 1;i<=n;i++) du[i] = Du[i];
        for(int i  =1;i<ans;i++) {
            for(int j = 0; j<E[tp[i]].size();j++) du[E[tp[i]][j]]--;
            an[i] = tp[i]; vis[tp[i]] = true;
        }
        int s = n+1;
        for(int i = 1;i<=n;i++) {
           if(du[i] == 0 && !vis[i]) {
               if(i>tp[ans]) s = min(s,i);
           } 
        }
        an[ans] = s; vis[s] = true;
        for(int i = 0;i<E[s].size();i++) du[E[s][i]]--;
        TP(ans+1);
        for(int i = 1;i<=n;i++) {
            if(i!=1) printf(" ");
            printf("%d",an[i]);
        }
        printf("\n");
    }
    return 0;
}
