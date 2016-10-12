#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <list>
#include <limits>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
using namespace std;
const int Mod = 7;
const double eps = 1e-8;
const double Pi = acos(-1.0);
int Get(char *s) {
    if(strcmp(s,"MON") == 0) return 0;
    if(strcmp(s,"TUE") == 0) return 1;
    if(strcmp(s,"WED") == 0) return 2;
    if(strcmp(s,"THU") == 0) return 3;
    if(strcmp(s,"FRI") == 0) return 4;
    if(strcmp(s,"SAT") == 0) return 5;
    if(strcmp(s,"SUN") == 0) return 6;
    return 0;
}
char s[10],t[10];
int ma[350][350];
int ans[350];
bool vis[350];
int Gauss(int n,int m) {
    memset(ans,0,sizeof(ans));
    memset(vis,false,sizeof(vis));
    int row = 0,col = 0;
    for(;row<=n && col<m;row++,col++) {
        int r = row;
        for(int i = row+1;i<=n;i++) if(ma[i][col]) r = i;
        if(!ma[r][col]) {
            vis[col] = true;
            row -- ;
            continue;
        }
        for(int i = col;i<=m;i++)swap(ma[row][i],ma[r][i]);
        for(int i = row+1;i<=n;i++) {
            if(!ma[i][col]) continue;
            int x1 = ma[row][col]; int x2 = ma[i][col];
            for(int j = col;j<=m;j++) ma[i][j] = ((x1*ma[i][j]-x2*ma[row][j])%Mod+Mod)%Mod;
        }
    }
    for(int i = row;i<=n;i++) if(ma[i][m]) return -1;
    if(row<m) return 1;
    for(int i = m-1;i>=0;i--) {
        if(vis[i]) continue;
        int temp = ma[i][m];
        for(int j = i+1;j<m;j++) temp = ((temp-ans[j]*ma[i][j])%Mod+Mod)%Mod;
        while(temp%ma[i][i]) temp+=Mod;
        ans[i] = ((temp/ma[i][i])%Mod+Mod)%Mod;
        if(ans[i]<3) ans[i]+=Mod;
    }
    return 0;
}
int main(){
    int n,m,k,ind;
    while(~scanf("%d %d",&n,&m) && (n || m)) {
        memset(ma,0,sizeof(ma));
        for(int i = 0;i<m;i++) {
            scanf("%d %s %s",&k,s,t);
            ma[i][n] = ((Get(t)-Get(s)+1)%Mod+Mod)%Mod;
            for(int j = 0;j<k;j++) {
                scanf("%d",&ind);
                ma[i][ind-1] = (ma[i][ind-1]+1)%Mod;
            }
        }
        int an = Gauss(m-1,n);
        if(an == -1) printf("Inconsistent data.\n");
        else if(an == 1) printf("Multiple solutions.\n");
        else {
            for(int i =0;i<n;i++) {
                if(i) printf(" "); printf("%d",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
