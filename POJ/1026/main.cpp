#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int zh[300],top;
int a[300];
int p[300];
bool vis[300];
void dfs(int u) {
    for(int i = 1;i<=n;i++) {
       if(a[i] == u && !vis[i]) {
           vis[i] = true;
           p[i] = top;
           dfs(i);
       }
    }
}
char str[300];
int main() {
    while(~scanf("%d",&n) && n) {
        for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
        memset(vis,false,sizeof(vis));
        top  = 0 ;
        for(int i = 1;i<=n;i++) {
            if(!vis[i]) {
                vis[i] = true;
                zh[top] = 1;
                p[i] = top;
                dfs(i);
                top++;
            }
        }
        int k;
        while(~scanf("%d",&k) && k) {
            gets(str);
            int len = strlen(str);
            for(int i = len;i<n;i++) str[i] = ' ';
            str[n] = '\0';
            for(int i = 0;i<n;i++) {
                int s = i;
                for(int j = 0;j<(k%zh[p[i+1]];j++) {
                        s = [i];
                }
            }
        }
    }
    return 0;
}
