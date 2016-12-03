#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in.in","r",stdin);
    freopen("out1.out","w",stdout);
    int n;
    while(~scanf("%d",&n)) {
        int ans = 0;
        for(int i = 1;i<=n;i++) {
            for(int j = i+1;j<=n;j++) {
                for(int k = 1;k<=n;k++) {
                
                    if(k*i<n && (n-k*i)%j == 0) ans++;
                }
            }
        }
        printf("%d = %d\n",n,ans);
    }
    return 0;
}
