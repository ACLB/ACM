#include<bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
using namespace std;

int main(){
    ww("data1.out");
    rr("data1.in");
    int ans,x1,x2,y1,y2,n;
    while(~scanf("%d",&n)){
        ans = 0;
        while(n--){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            ans += (x2-x1+1) * (y2-y1+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
