#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
using namespace std;
const int INF = 0x3f3f3f3f;
bool vis[55][55];
bool Vis[1100];
int Map[1100][1100];
int pre[50][50];
int sum[1100];
int S,T,n,m,num;
int Dis[1100];
int mp[55][55];
int Dir[][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool Judge(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}
void dfs(int x,int y){
    vis[x][y] = true; pre[x][y] = T;
    num++; 
    for(int i =0;i<8;i++){
        int Fx = x + Dir[i][0];
        int Fy = y + Dir[i][1];
        if(Judge(Fx,Fy) && !vis[Fx][Fy] && mp[Fx][Fy] == mp[x][y]) dfs(Fx,Fy);
    }
}
void SPFA(){
    memset(Vis,false,sizeof(Vis));
    for(int i = S;i<=T;i++) Dis[i] = INF;
    Dis[S] = 0;
    queue<int>Q;
    Q.push(S);
    Vis[S] = true;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i = S; i <= T; i++){
            if(Dis[i] > Dis[u] + Map[u][i]) {
                Dis[i] = Dis[u] + Map[u][i];
                if(!Vis[i]){
                    Vis[i] = true;
                    Q.push(i);
                }
            }
        }
        Vis[u] = false;
    }
}
int main(){
    ww("data1.out");
    rr("data1.in");
    while(~scanf("%d %d",&n,&m)){
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                scanf("%d",&mp[i][j]); 
        memset(vis,false,sizeof(vis));
        memset(sum,0,sizeof(sum));
        T = 1; 
        for(int i = 0;i < n; i++){
            for(int j = 0 ;j < m; j++){
                if(vis[i][j]) continue;
                num = 0;
                dfs(i,j);
                sum[T++] = num;
            }
        }
        S = 0;
        for(int i = S;i<=T;i++) 
            for(int j = S;j<=T;j++)
                Map[i][j] = INF;
        for(int i =0 ;i<n;i++){
            Map[S][pre[i][0]] = 0;
            Map[pre[i][0]][S] = sum[pre[i][0]];
            Map[T][pre[i][m-1]] = 0;
            Map[pre[i][m-1]][T] = sum[pre[i][m-1]];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m;j++){
                for(int k = 0;k < 8;k++){
                    int Fx = i+Dir[k][0];
                    int Fy = j+Dir[k][1];
                    if(Judge(Fx,Fy)){
                        Map[pre[i][j]][pre[Fx][Fy]] = min(Map[pre[i][j]][pre[Fx][Fy]],sum[pre[i][j]]);
                        Map[pre[Fx][Fy]][pre[i][j]] = min(Map[pre[Fx][Fy]][pre[i][j]],sum[pre[Fx][Fy]]);
                    }
                }
            }
        }
        SPFA();
        printf("%d\n",Dis[T]);
    }
    return 0;
}
