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
int zh[300][300],top;
int num[300];
int a[300];
int p[300];
bool vis[300];
void dfs(int u) {
    if(!vis[u]) {
        vis[u] = true;
        zh[top][num[top]++] = a[u];
        dfs(a[u]);
    }
}
char str[300];
char s[300];
int main() {
    while(~scanf("%d",&n) && n) {
        for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
        memset(vis,false,sizeof(vis));
        top  = 0 ;
        for(int i = 1;i<=n;i++) {
            if(!vis[i]) {
                vis[i] = true;
                num[top] = 0;
                zh[top][num[top]++] = a[i];
                dfs(a[i]);
                top++;
            }
        }
        int k;
        while(~scanf("%d",&k) && k) {
            gets(str);
            int len = strlen(str);
            for(int i = len;i<=n;i++) str[i] = ' ';
            str[n+1] = '\0';
            for(int i = 0;i<top;i++) {
                for(int j = 0;j<num[i];j++) {
                    s[zh[i][(j+k)%num[i]]] = str[zh[i][j]];
                }
            }
            s[n+1] = '\0';
            printf("%s\n",s+1);
        }
        printf("\n");
    }
    cout<<"---"<<endl;
    return 0;
}
