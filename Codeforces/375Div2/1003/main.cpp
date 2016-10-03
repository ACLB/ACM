#include <bits/stdc++.h>

using namespace std;

int a[2200];

int has[2200];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int st = n/m;
    queue<int>Q;
    for(int i = 0; i<n; i++) {
        scanf("%d",&a[i]);
        if(a[i]<=m) {
            if(has[a[i]]< st) has[a[i]] ++;
            else Q.push(i);
        } else Q.push(i);
    }
    int ans1 = 0;
    int ans2 = 0;
    int tt = 1;
    while(!Q.empty()) {
        while(has[tt] >=st && tt <=m) tt++;
        if( tt >m) break;
        int u  =Q.front();
        Q.pop();
        a[u] = tt;
        ans2++;
        has[tt] ++;
    }
    ans1 = st;
    printf("%d %d\n",ans1,ans2);
    for(int i = 0; i<n; i++) {
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
