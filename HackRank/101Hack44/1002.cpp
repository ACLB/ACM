#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+100;
int vis[maxn];
void Get() {
    memset(vis,1,sizeof(vis));
    vis[0] = vis[1] = 0;
    for(int i = 2;i<maxn;i++) {
        if(vis[i]) {
            for(int j = i+i;j<maxn;j+=i) vis[j] = 0;
        }
    }
    for(int i = 0;i<maxn;i++) vis[i] = vis[i]+vis[i-1];
}
int main() {
    Get();
    int n,T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        if(vis[n]&1) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
