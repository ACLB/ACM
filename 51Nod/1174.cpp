#include <bits/stdc++.h>
using namespace std;
const int Max = 11000;
int rm[Max][15],n,m;
void Rmq() {
    for(int i = 1;(1<<i)<=n;i++) {
        for(int j = 1;(j+(1<<i))-1<=n;j++) {
            rm[j][i] = max(rm[j][i-1],rm[j+(1<<(i-1))][i-1]);
        }
    }
}
int qu(int l,int r) {
    int k = (int)log2(r-l+1);
    return max(rm[l][k],rm[r-(1<<k)+1][k]);
}
int main() {
    int l,r;
    while(~scanf("%d",&n)) {
        for(int i  = 1;i<=n;i++) scanf("%d",&rm[i][0]);
        Rmq();
        scanf("%d",&m);
        while(m--) {
            scanf("%d %d",&l,&r);
            l++,r++;
            printf("%d\n",qu(l,r));
        }
    }
    return 0;
}
