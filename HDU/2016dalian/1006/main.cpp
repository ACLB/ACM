#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
    int n,T;
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d",&n);
            for(int i = 1 ;i<=n;i++) {
                scanf("%d",&a[i]);
            }
            sort(a+1,a+n+1);
            int sum = 0;
            bool flag = false;
            for(int i = 1;i<=n;i++) {
                sum+=a[i];
                if(sum<(i*(i-1))) {
                    flag = true;
                    break;
                }
            }
            if(flag || sum!=(n*(n-1))) printf("F\n");
            else printf("T\n");
        }
    }
    return 0;
}
