#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m;
char str[1100][1100];
int x,y,x2,y2;
int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool vis[1100][1100];
int dis[1100][1100];
bool ok(int x,int y) {
    return (x>=0&&x<n&&y>=0&&y<m);
}

struct node {
    int x,y,step;
    node(){}
    node(int _x,int _y,int _step):x(_x),y(_y),step(_step){}
    bool operator < (const node &a)const {
        return step > a.step;
    }
};
int bfs() {
    memset(vis,false,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    priority_queue<node>Q;
    dis[x][y] = 0;
    vis[x][y] = true;
    Q.push(node(x,y,0));
    while(!Q.empty()) {
        node u = Q.top(); Q.pop();
        node v;
        vis[u.x][u.y] = false;
        for(int i = 0;i<4;i++) {
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            if(ok(v.x,v.y)) {
                int st = str[v.x][v.y] == 'X'?0:1;
                if(dis[v.x][v.y] > dis[u.x][u.y]+st) {
                    dis[v.x][v.y] = dis[u.x][u.y]+st;
                    v.step = u.step+st;
                    if(!vis[v.x][v.y])
                    {
                        vis[v.x][v.y] = true;
                        Q.push(v);
                    }
                }
            }
        }
    }
    return dis[x2][y2];
}
int main(){
    while(~scanf("%d %d",&n,&m)&&(n+m)) {
        for(int i = 0 ;i<n;i++) {
            scanf("%s",str[i]);
        }
        scanf("%d %d %d %d",&x,&y,&x2,&y2);
        x--;y--;x2--;y2--;
        int ans = bfs();
        printf("%d\n",ans);
    }
    return 0;

}
