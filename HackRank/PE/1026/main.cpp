#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5;
bool vis[Max];
int ans[11000];
int ok(int n) { 
    memset(vis,false,sizeof(vis));
    int num = 0;
    vis[0] = true;
    int s = 1;
    while(!vis[s]) {
        vis[s] = true;
        num++;
        if(s>=n) s = s%n;
        s =s*10;
    }
    return num;
}
int main() {
    int T,n;
    ans[0] = 0;
    for(int i = 1;i<=10000;i++) {
        ans[i] = max(ans[i-1],ok(i));
    }
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
