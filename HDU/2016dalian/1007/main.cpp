#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    LL n,m;
    while(~scanf("%lld %lld",&n,&m)) {
        n = ceil(1.0*n/2)*floor(1.0*n/2);
        if(n<=m) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
