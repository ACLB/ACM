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
const int Mod = 2;
const double eps = 1e-6;
const double Pi = acos(-1.0);
int ma[50][50];
void Init() {
    memset(ma,0,sizeof(ma));
    for(int i = 0;i<5;i++) {
        for(int j = 0;j<6;j++) {
            if(i) ma[i*6+j][(i-1)*6+j] = 1;
            if(j) ma[i*6+j][i*6+j-1] = 1;
            if(i<4) ma[i*6+j][(i+1)*6+j] = 1;
            if(j<5) ma[i*6+j][i*6+j+1] =1;
            ma[i*6+j][i*6+j] = 1;
        }
    }
}
bool vis[50];
int ans[50];
void Gauss(int n,int m) {
    int row = 0,col = 0;
    memset(vis,false,sizeof(vis));
    memset(ans,0,sizeof(ans));
    for(;row <=n && col < m;row++,col++) {
        int r = row;
        for(int i = row+1;i<=n;i++) if(ma[i][col]) r = i;
        if(ma[r][col] == 0) {
            row--;
            vis[col] = true;
            continue;
        }
        for(int i = col;i <= m;i++) swap(ma[row][i],ma[r][i]);
        for(int i = row+1;i<=n;i++) {
            if(ma[i][col]) {
                for(int j = col;j<=m;j++) ma[i][j] ^=ma[row][j];
            }
        }
    }
    for(int i = m-1;i>=0;i--) {
        if(vis[i]) continue;
        int temp = ma[i][m];
        for(int j = i+1;j<m;j++) {
            temp = ((temp-ma[i][j]*ans[j])%Mod+Mod)%Mod;
        }
        while(temp%ma[i][i]) temp+=2;
        ans[i] = ((temp/ma[i][i])%Mod+Mod)%Mod;
    }
}
int main(){
    int T,op,z = 1;
    scanf("%d",&T);
    while(T--) {
        Init();
        for(int i = 0;i<5;i++){
            for(int j = 0;j<6;j++) {
                scanf("%d",&op);
                ma[i*6+j][30] = op;
            }
        }
        Gauss(29,30);
        printf("PUZZLE #%d\n",z++);
        for(int i = 0;i<5;i++) {
            for(int j = 0;j<6;j++) {
                if(j) printf(" ");
                printf("%d",ans[i*6+j]);
            }
            printf("\n");
        }
    }
    return 0;
}
