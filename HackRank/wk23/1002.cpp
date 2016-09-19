#include <bits/stdc++.h>
using namespace std;
char str[55][55];
int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
struct node {
    int x,y;
    int step ;
    node(){}
    node(int _x,int _y,int _step):x(_x),y(_y),step(_step) {}
};
int n;
bool vis[55][55];
bool ok(node a) {
    if(a.x >=1 && a.x <= n &&a.y>=1 && a.y<=n && str[a.x][a.y] == '.' && !vis[a.x][a.y]) return true;
    return false;
}
int Get(int x,int y) {
    int ans = min(min(x-1,y-1),min(n-x,n-y));
    if(ans == 0) return 0;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            if(str[i][j] == '*') {
                int s = floor(sqrt((x-i)*(x-i)+(y-j)*(y-j)));
                if(s*s == (x-i)*(x-i)+(y-j)*(y-j)) s --;
                ans = min(ans,s);
            }
        }
    }
    return ans;
}
int main() {
    scanf("%d",&n);
    for(int i =1;i<=n;i++) scanf("%s",str[i]+1);
    int ans =0;
    for(int i = 1;i<=n;i++) {
        for(int j =1;j<=n;j++) {
            if(str[i][j] == '.'){
                ans = max(ans,Get(i,j));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
