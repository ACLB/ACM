#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 222;
const int INF = 0x3f3f3f3f;
char str[maxn][maxn];
int dis[maxn][maxn];
int n,m;
int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool vis[maxn][maxn];
struct node {
    int x,y,step;
    node() {}
    node(int _x,int _y,int _step):x(_x),y(_y),step(_step) {}
};
void dfs1() {
    memset(dis,INF,sizeof(dis));
    queue<node>Q;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(str[i][j] == '$') {
                Q.push(node(i,j,0));
                dis[i][j]  =0;
            }
        }
    }
    while(!Q.empty()) {
        node u  =Q.front();
        Q.pop();
        node v;
        for(int i = 0; i<4; i++) {
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            v.step = u.step + 1;
            if(v.x>=0 &&v.x < n && v.y>=0 && v.y <m && str[v.x][v.y]!='#' && dis[v.x][v.y] > v.step) {
                dis[v.x][v.y] = v.step;
                Q.push(v);
            }
        }
    }
}
bool dfs2() {
    memset(vis,false,sizeof(vis));
    queue<node>Q;
    for(int i = 0; i<n; i++) {
        for(int j =0 ; j<m; j++) {
            if(str[i][j] == '@') {
                Q.push(node(i,j,0));
                vis[i][j] = true;
                break;
            }
        }
    }
    while(!Q.empty()) {
        node  u = Q.front();
        node v;
        Q.pop();
        if(str[u.x][u.y] == '%') return true;
        for(int i = 0; i<4; i++) {
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            v.step = u.step + 1;
            if(v.x>=0 &&v.x < n && v.y>=0 && v.y <m && str[v.x][v.y]!='#' && dis[v.x][v.y] > v.step && !vis[v.x][v.y]) {
                vis[v.x][v.y] = true;
                Q.push(v);
            }
        }
    }
    return false;

}
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i<n; i++) scanf("%s",str[i]);

    dfs1();
    if(dfs2()) printf("Yes\n");
    else printf("No\n");
    return 0;
}
