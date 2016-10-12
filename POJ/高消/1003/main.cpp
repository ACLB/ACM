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
typedef long long LL;
const int Mod = 4;
const double eps = 1e-6;
const double Pi = acos(-1.0);
LL ma[110][110];
LL p;
char str[110];
LL ans[110];
bool vis[110];
void Gauss(int n,int m) {
    memset(ans,0,sizeof(ans));
    memset(vis,false,sizeof(vis));
    int row = 0,col = 0;
    for(;row<=n&& col<m;row++,col++) {
        int r = row;
        for(int i = row+1;i<=n;i++) if(ma[i][col]) r = i;
        if(!ma[r][col]) {
            vis[col] = true;
            row--;
            continue;
        }
        for(int i = col;i<=m;i++) swap(ma[row][i],ma[r][i]);
        for(int i = row+1;i<=n;i++) {
            if(!ma[i][col]) continue;
            LL x1 = ma[row][col];
            LL x2 = ma[i][col];
            for(int j = col;j<=m;j++) ma[i][j] = ((x1*ma[i][j]-x2*ma[row][j])%p+p)%p;
        }
    }
    for(int i = m-1;i>=0;i--) {
        if(vis[i]) continue;
        LL temp = ma[i][m];
        for(int j = i+1;j<m;j++) temp = ((temp-ans[j]*ma[i][j])%p+p)%p;
        while(temp%ma[i][i]) temp+=p;
        ans[i] = ((temp/ma[i][i])%p+p)%p;
    }
}
void Init() {
    scanf("%I64d %s",&p,str);
    memset(ma,0,sizeof(ma));
    int len = strlen(str);
    for(int i = 1;i<=len;i++) {
        int po  = 1;
        for(int j = 0;j<len;j++) {
            ma[i-1][j] = po;po = (po*i)%p;
        }
        if(str[i-1] == '*') ma[i-1][len] = 0;
        else ma[i-1][len] = str[i-1]-'a'+1;
    }
    Gauss(len-1,len);
    for(int i = 0;i<len;i++) {
        if(i) printf(" ");
        printf("%I64d",ans[i]);
    }
    printf("\n");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) {Init();}
    return 0;
}
