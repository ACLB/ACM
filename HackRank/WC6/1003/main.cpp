#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[500][500];
int main() {
    int T,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i = 0;i<2*n;i++) {
            for(int j = 0;j<2*n;j++) {
                scanf("%d",&a[i][j]);
            }
        }
        LL sum = 0;
        for(int i = 0;i<n;i++) 
            for(int j = 0;j<n;j++)
                sum+=max(max(a[i][j],a[i][2*n-j-1]),max(a[2*n-i-1][j],a[2*n-i-1][2*n-j-1]));
        printf("%lld\n",sum);
    }
    return 0;
}
