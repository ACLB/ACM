#include <bits/stdc++.h>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
using namespace std;
typedef long long LL;
int a[10];
int main() {
    int sum = 0,da;
    for(int i = 0 ;i < 5; i++) scanf("%d",&a[i]);
    for(int i = 0 ;i < 5; i++) {
        scanf("%d",&da);
        sum+=min(((da-a[i])%10+10)%10,(((a[i]-da)%10+10)%10));
    }
    printf("%d\n",sum);
    return 0;
}
