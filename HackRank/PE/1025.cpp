#include <bits/stdc++.h>
using namespace std;
int a[5][5500];
int ans[5500];
int main() {
    memset(ans,-1,sizeof(ans));
    ans[1] = 1;
    a[1][0] = 1; a[1][1] = 1;
    a[2][0] = 1; a[2][1] = 1;
    for(int i = 3;;i++) {
        int st = 0;
        a[3][0]= min(a[1][0],a[2][0]);
        for(int j = 1;j<=a[3][0];j++) {
            st = st+a[1][j]+a[2][j];
            a[3][j] = st%10;
            st/=10;
        }
        for(int j = min(a[1][0],a[2][0])+1;j<=a[2][0];j++) {
            st+=a[2][j];
            a[3][++a[3][0]] = st%10;
            st/=10;
        }
        if(st) a[3][++a[3][0]] = st;
        if(ans[a[3][0]] == -1) ans[a[3][0]] = i;
        if(a[3][0] > 5000) break;
        for(int j =0;j<=a[2][0];j++) a[1][j] = a[2][j];
        for(int j =0;j<=a[3][0];j++) a[2][j] = a[3][j];
    }
    int T,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
