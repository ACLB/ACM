#include <bits/stdc++.h>

using namespace std;
char str[55][55];
int n,m,k;
struct node {
    int x,y,k;
    bool operator  < (const node &b) const {
        return k>b.k;
    }
}a[110000];

int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool vis[55][55];
int num;
bool dfs(int x,int y) {
    num++;
    bool flag = true;
    vis[x][y] = true;
    for(int i = 0;i<4;i++) {
        int Fx = x+dir[i][0];
        int Fy = y+dir[i][1];
        if(Fx < 0 || Fx >= n|| Fy<0 ||Fy >=m) {
                flag = false;
                continue;
        }
        if(str[Fx][Fy]!='*' && !vis[Fx][Fy])
            if(!dfs(Fx,Fy)) flag = false;
    }
    return flag;
}
void dfs1(int x,int y) {
    str[x][y] = '*';
    vis[x][y] = true;
     for(int i = 0;i<4;i++) {
        int Fx = x+dir[i][0];
        int Fy = y+dir[i][1];
        if(Fx < 0 || Fx >= n|| Fy<0 ||Fy >=m) continue;
        if(str[Fx][Fy]!='*' && !vis[Fx][Fy])  dfs1(Fx,Fy);
    }
}
int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0 ;i<n;i++) scanf("%s",str[i]);
    int top = 0;
    memset(vis,false,sizeof(vis));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(str[i][j] == '.' && !vis[i][j]) {
                num = 0;
                if(dfs(i,j)) {
                    a[top].k = num;
                    a[top].x = i;
                    a[top].y = j;
                    top++;
                }
            }
        }
    }
    sort(a,a+top);
    int ans = 0;
    memset(vis,false,sizeof(vis));
    for(int i = top-1;i>=k;i--) {
        dfs1(a[i].x,a[i].y);
        ans+=a[i].k;
    }
    printf("%d\n",ans);
    for(int i = 0;i<n;i++) printf("%s\n",str[i]);
    return 0;
}
