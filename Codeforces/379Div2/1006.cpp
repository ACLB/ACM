#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 1e5;
int n;
LL a[maxn*2],b[maxn*2];
LL ans[maxn*2];
bool flag;
int main() {
    scanf("%d",&n); flag = false;
    for(int i = 0;i<n;i++)scanf("%I64d",&a[i]);
    for(int i = 0;i<n;i++)scanf("%I64d",&b[i]);
    ans[0] = 0;
    for(int i = 1;i<n;i++) {
        if((a[i]+b[i]-a[i-1]-b[i-1])%n) {
            flag = true;
            break;
        }
        else {
            ans[i] = ans[i-1]+(a[i]+b[i]-a[i-1]-b[i-1])/n;
        }
    }
    if(n==1 &&(a[0] != b[0])) flag = true;
    LL sum=0;
    for(int i = 0;i<n;i++) sum+=ans[i];
    if((a[0]+b[0]-sum)%(2*n)) {
        flag = true;
    }
    else sum = (a[0]+b[0]-sum)/(2*n);
    if(flag) printf("-1\n");
    else {
        for(int i= 0 ;i<n;i++) {
            if(i) printf(" ");
            printf("%I64d",ans[i]+sum);
        }
        printf("\n");
    }
    return 0;
}
