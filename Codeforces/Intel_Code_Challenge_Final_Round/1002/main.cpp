#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[30][30];

bool ok(int s) {
    int ans = 0;
    for(int i = 1; i<=m; i++) {
        if(a[s][i]!=i) {
            ans++;
        }
    }
    if(ans ==0 || ans == 2) return true;
    return false;
}

int main() {
    scanf("%d %d",&n,&m);
    bool op = false;
    for(int i =0; i<n; i++) {
        for(int j = 1 ; j<=m; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 1; i<=m; i++) {
        for(int j = i; j<=m; j++) {
            bool flag = false;
            for(int k = 0; k<n; k++) {
                swap(a[k][i],a[k][j]);
                if(!ok(k)) flag = true;
            }
            for(int k = 0; k<n; k++) {
                swap(a[k][i],a[k][j]);
            }
            if(flag) continue;
            else op = true;
        }
    }
    if(op) printf("YES\n");
    else printf("NO\n");
    return 0;
}
