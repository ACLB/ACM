
include <bits/stdc++.h>
using namespace std;
int main() {
    int n,q;
    scanf("%d",&q);
    while(q--) {
        scanf("%d",&n);
        if(n&1) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
