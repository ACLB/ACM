#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
typedef long long LL;
int main() {
    int n;
    LL ans;
    scanf("%d",&n);
    ans = n;
    for(int i = 3;i<=n;i++) ans = (ans*i)%mod;
    printf("%lld\n",ans);
    return 0;
}
