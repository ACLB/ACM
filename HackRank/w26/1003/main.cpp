#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
int pri[maxn];
bool vis[maxn];
void Get() {
    memset(vis,false,sizeof(vis));
    pri[0] = 0;
    for(int i = 2;i<maxn;i++) {
        if(!vis[i]) {
            pri[++pri[0]] = i;
            for(int j = i;j<maxn;j+=i) vis[j] = true;
        }
    }
}
bool Ok(int s) {
    for(int i = 1;i<=pri[0] && pri[i]<s;i++) {
        if(s%pri[i] == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    Get();
    int n,m;
    scanf("%d %d",&n,&m);
    memset(vis,false,sizeof(vis));
    for(int i = n;i<=m;i++) {
        vis[i-n] = Ok(i);
    }
    int ans =0;
    for(int i = 0;i<=m-n;i++) {
        if(vis[i] && vis[i+2]) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
