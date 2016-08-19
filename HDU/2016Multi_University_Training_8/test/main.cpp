#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Mod =  772002;
int dp[30][1<<9];
int cnt[1<<9],ans;
bool vis[10][10];
int pos[30][2];
char mp[10][10];
int n,m;
int dirx[] = {-1,-1,0,1,1, 1, 0,-1,0};
int diry[] = { 0, 1,1,1,0,-1,-1,-1,0};
bool Ju(int x,int y) {return (x>=0&&x<n&&y>=0&&y<m);}
bool ok() {
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(mp[i][j]=='X') {
                for(int k = 0; k<8; k++) {
                    if(Ju(i+dirx[k],j+diry[k]) && mp[i+dirx[k]][j+diry[k]] == 'X') return false;
                }
            }
        }
    }
    return true;
}
LL cal() {
    int num = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++)
            if(mp[i][j] == 'X') {
                pos[num][0] = i;
                pos[num++][1] = j;
            }
    }
    int bt = 1<<num;
    memset(cnt,0,sizeof(cnt));
    for(int k =0; k<bt; k++) {
        memset(vis,false,sizeof(vis));
        for(int i = 0; i<num; i++) {
            if((1<<i)&k) continue;
            vis[pos[i][0]][pos[i][1]] = true;
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                bool op = false;
                for(int s = 0 ; s < 9; s++) {
                    if(Ju(i+dirx[s],j+diry[s]) && vis[i+dirx[s]][j+diry[s]]) {
                        op = true;
                        break;
                    }
                }

                if(!op) {
                    cnt[k]++;
                }
            }
        }
    }

    dp[0][0] = 1;
    for(int i = 1; i<=n*m; i++) {
        for(int j = 0; j<bt; j++) {
            dp[i][j] = (dp[i-1][j]*max(cnt[j]-i+1,0))%Mod;
            for(int k = 0; k<num; k++) {
                if((1<<k) & j) {
                    dp[i][j] = (dp[i][j]+dp[i-1][j-(1<<k)])%Mod;
                }
            }
        }
    }
    return dp[n*m][bt-1];
}

void dfs(int x,int y,int cnt) {
    if(x == n) {
        if(cnt &1) cnt = -1;
        else cnt = 1;
        ans = ((ans+cal()*cnt)%Mod+Mod)%Mod;
        return ;
    }
    if(y==m) {
        dfs(x+1,0,cnt);
        return ;
    }
    dfs(x,y+1,cnt);
    if(mp[x][y] == '.') {
        for(int k = 0; k<8; k++)
            if(Ju(x+dirx[k],y+diry[k]) && mp[x+dirx[k]][y+diry[k]] == 'X') return ;
        mp[x][y] = 'X';
        dfs(x,y+1,cnt+1);
        mp[x][y] ='.';
    }
}
int main() {
    //freopen("out.out","w",stdout);
    int z = 1;
    while(~scanf("%d %d",&n,&m)) {
        for(int i = 0; i<n; i++) scanf("%s",mp[i]);
        printf("Case #%d: ",z++);
        if(!ok()) {
            printf("0\n");
            continue;
        }
        ans = 0;
        dfs(0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
