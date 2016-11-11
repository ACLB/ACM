#include <bits/stdc++.h>

using namespace std;

int n;
long long da;
int main() {
    
    while(~scanf("%d",&n)) {
        int ans = 0;
        for(int i = 0;i<n;i++){
            scanf("%lld",&da);
            while(da) {
                if(da%16 == 1){
                    da/=16;
                    if(da%16 == 6) {
                        da/=16;
                        ans++;
                    }
                }
                else da/=16;
            }
        }
        printf("%d\n",ans);
    }    
    return 0;
}
