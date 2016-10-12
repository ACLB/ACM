#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int INF= 0x3f3f3f3f;
int main(){
    int T;
    int n,da;
    scanf("%d",&T);
    while(T--) {
        int ans = -INF ,sum = 0;
        scanf("%d",&n);
        for(int i = 0;i<n;i++) {
            scanf("%d",&da);
            sum+=da;
            ans = max(ans,sum);
            if(sum<0) sum = 0;

        }
        printf("%d\n",ans);
    }
    return 0;
}
