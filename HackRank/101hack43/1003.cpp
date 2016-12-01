#include <bits/stdc++.h>

using namespace std;
const int maxn = 330;
int n,m;
int a[maxn][maxn];
int b[maxn];
int main() {
    scnf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++) 
        for(int j = 1;j<=m;j++) scanf("%d",&a[i][j]);
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            a[i][j]+=a[i][j-1];
        }
    }
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            int L = 
        }
    }
    return 0;
}
