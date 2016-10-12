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
const double eps = 1e-8;
const double Pi = acos(-1.0);
double ma[30][30];
char str[1100];
int n;
void dfs(int &st,double *a) {
    double b[30];
    int cnt = 0;
    while(str[st]!=')') {
        if(str[st] >='a' && str[st]<='z') {
            a[str[st]-'a'] += 1;
            cnt++;st++;
        }
        else if(str[st] == ' ') st++;
        else if(str[st] == '-'){
            st++; double num = 0;
            while(str[st]>='0' && str[st]<='9') {
                num = num*10+str[st]-'0'; st++;
            }
            cnt++;
            a[n] -=num;
        }
        else if(str[st]>='0' && str[st]<='9') {
            double num = 0;
            while(str[st]>='0' && str[st]<='9') {
                num = num*10+str[st]-'0';
                st++;
            }
            cnt++;
            a[n]+=num;
        }
        else if(str[st] == '('){
            st++;
            memset(b,0,sizeof(b));
            dfs(st,b); cnt++;
            for(int i = 0;i<=n;i++) a[i]+=b[i];
        }
    }
    if(cnt)
        for(int i = 0;i<=n;i++) a[i]/=cnt;
    st++;
}
double ans[30];
bool vis[30];
int dbcmp(double s) {
    if(fabs(s) < eps) return 0;
    return s>0?1:-1;
}
int Gauss(int n,int m) {
    memset(ans,0,sizeof(ans));
    memset(vis,true,sizeof(vis));
    int row = 0,col = 0;
    for(;row<=n&&col<m;row++,col++) {
        int r = row;
        for(int i = row+1;i<=n;i++)  if(fabs(ma[i][col]) > fabs(ma[r][col])) r = i;
        if(dbcmp(fabs(ma[r][col])) == 0) {
            row --; continue;
        }
        for(int i = col;i<=m;i++) swap(ma[r][i],ma[row][i]);
        for(int i = row+1;i<=n;i++) {
            if(dbcmp(fabs(ma[i][col]))) {
                double s = ma[i][col]/ma[row][col];
                for(int j = col;j<=m;j++) ma[i][j] = ma[i][j] - ma[row][j]*s;
            }
        }
     }
     for(int i = row;i<=n;i++) if(dbcmp(fabs(ma[i][m]))) return -1;
     if(row <=n) {
        for(int i = row-1;i>=0;i--) {
            int num = 0,fr;
            for(int j =0 ;j<m;j++) {
                if(fabs(ma[i][j]) >eps && vis[j]) {
                    num++;
                    fr = j;
                }
            }
            if(num >1) continue;
            double temp = ma[i][m];
            for(int j = 0;j<m;j++)
                if(fabs(ma[i][j])>eps && j!=fr) temp-=ans[j]*ma[i][j];
            ans[fr] = temp/=ma[i][fr];
            vis[fr] = false;
        }
        return 1;
     }
     for(int i = m-1;i>=0;i--) {
        double temp = ma[i][m];
        for(int j = i+1;j<m;j++) temp-=ma[i][j]*ans[j];
        ans[i] = temp/ma[i][i];
     }
     return 0;
}
int main(){
    int z  =1;
    while(~scanf("%d",&n) && n) {
        getchar();
        memset(ma,0,sizeof(ma));
        for(int i = 0 ;i<n;i++) {
            gets(str);
            int st = 0;
            while(str[st]!='(') st++;
            st++;
            dfs(st,ma[i]);
            ma[i][n] = -ma[i][n];
            ma[i][i]--;
        }
        int an = Gauss(n-1,n);
        printf("Game %d\n",z++);
        for(int i = 0;i<n;i++) {
            printf("Expected score for %c ",i+'a');
            if(an == -1) printf("undefined\n");
            else {
                if(an ==0) printf("= %.3f\n",ans[i]);
                else {
                    if(vis[i]) printf("undefined\n");
                    else printf("= %.3f\n",ans[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
