#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100100];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++) {
        scanf("%lld",&a[i]);
    }
    for(int i = 0;i<n-1;i++) {
        if(i) printf(" ");
        printf("%lld",a[i]+a[i+1]);
    }
    printf(" %lld\n",a[n-1]);
    return 0;
}
