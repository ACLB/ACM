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
const int Mod = 4;
const double eps = 1e-6;
const double Pi = acos(-1.0);
int mat[10][10];
char str[][10] = {
"ABDE",
"ABC",
"BCEF",
"ADG",
"BDEFH",
"CFI",
"DEGH",
"GHI",
"EFHI"
};
void Init() {
    memset(mat,0,sizeof(mat));
    for(int i = 0;i<9;i++) {
        int len = strlen(str[i]);
        for(int j = 0;j<len;j++) {
            mat[str[i][j]-'A'][i] = 1;
        }
    }
}
int ans[15];
bool vis[15];
void Gauss(int n,int m) {
    memset(ans,0,sizeof(ans));
    memset(vis,false,sizeof(vis));
    int row = 0,col = 0;
    for(;row<=n && col<m;row++,col++) {
        int r = row;
        for(int i = row+1;i<=n;i++) if(mat[i][col]) r = i;
        if(!mat[r][col]) {
            row --;
            vis[col] = true;
            continue;
        }
        for(int i = col;i<=m;i++) swap(mat[row][i],mat[r][i]);
        for(int i = row+1;i<=n;i++) {
            if(!mat[i][col]) continue;
            int x1 = mat[row][col];
            int x2 = mat[i][col];
            for(int j = col;j<=m;j++)  mat[i][j] = ((x2*mat[row][j]-x1*mat[i][j])%Mod+Mod)%Mod;
        }
    }
    for(int i = m-1;i>=0;i--) {
        if(vis[i]) continue;
        int temp = mat[i][m];
        for(int j = i+1;j<m;j++) temp = ((temp-ans[j]*mat[i][j])%Mod+Mod)%Mod;
        while(temp%mat[i][i]) temp+=4;
        ans[i] = ((temp/mat[i][i])%Mod+Mod)%Mod;
    }
}
int main(){
    Init();
    for(int i = 0;i<9;i++) {
        scanf("%d",&mat[i][9]);
        mat[i][9] = ((Mod-mat[i][9])%Mod+Mod)%Mod;
    }
    Gauss(8,9);
    bool op = false;
    for(int i =0;i<9;i++) {
        for(int j = 0;j<ans[i];j++) {
            if(op) printf(" ");
            else op = true;
            printf("%d",i+1);
        }
    }
    printf("\n");
    return 0;
}
