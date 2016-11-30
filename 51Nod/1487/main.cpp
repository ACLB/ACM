#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int dir[11][2];
char val[110][110];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&n,&m,&k);
        for(int i =0 ;i<n;i++)
            scanf("%s",val[i]);
        for(int i= 0;i<k;i++) scanf("%d %d",&dir[i][0],&dir[i][1]);

    }
    return 0;
}
