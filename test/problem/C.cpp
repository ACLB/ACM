#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char s[55][55];
int n,m;
int vis[55][55];
struct node{
    int v,w,next;

}E[100100];
int Head[110],top;
void Creat(int u,int v,int w){
    E[top].v = v; E[top].w = w;
    E[top].next = Head[u];
    Head[u] = top++;
}
struct Node{
    int x,y,step;
    Node(){}
    Node(int _x,int _y,int _step):x(_x),y(_y),step(_step){}
};
bool Vis[50][50];
bool Judge(int x,int y){
    if(x>=0 && x<n&&y>=0 &&y<n && s[x][y]!='#' && !Vis[x][y]) return true;
    return false;
}
void bfs(int x,int y){
    memset(Vis,false,sizeof(Vis));
    queue<Node>Q;
    Q.push(Node(x,y,0));
    Vis[x][y] = true;
    while(!Q.empty()){
        Node u = Q.front(); Q.pop();
        if(vis[u.x][u.y]) Creat(vis[x][y],vis[u.x][u.y],u.step);
        Node v;
        for(int i = 0;i<4;i++){
            v.x = u.x+dir[i][0];
            v.y = u.y + dir[i][1];
            if(Judge(v.x,v.y)){
                v.step = u.step+1;
                Vis[v.x][v.y] = true; Q.push(v);
            }
        }
    }
}
int dis[110];
bool vist[110];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d\n",&m,&n);
        int num = 0;
        memset(vis,0,sizeof(vis));
        memset(Head,-1,sizeof(Head));
        top = 0;
        for(int i = 0;i<n;i++){
            gets(s[i]);
            for(int j = 0;j<m;j++){
                if(s[i][j] == 'A' || s[i][j] == 'S'){
                    vis[i][j] = ++num;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(s[i][j] == 'A' || s[i][j] == 'S'){
                    bfs(i,j);
                }
            }
        }
        memset(dis,INF,sizeof(dis));
        for(int i = Head[1];i!=-1;i = E[i].next) dis[E[i].v] = E[i].w;
        memset(vist,false,sizeof(vist));
        vist[1] = true;
        int ans = 0 ;
        for(int i = 1;i<num;i++){
            int Mi = INF,flag;
            for(int j = 1;j<=num;j++){
                if(dis[j]<Mi && !vist[j]){
                    Mi = dis[j];
                    flag = j;
                }
            }
            vist[flag] = true; ans += Mi;
            for(int j = Head[flag];j!=-1;j = E[j].next){
                dis[E[j].v] = min(dis[E[j].v],E[j].w);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
