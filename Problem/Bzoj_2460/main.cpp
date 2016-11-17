#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 1100;
typedef long long LL;
struct node {
    LL num; int val;
    bool operator < (const node &a)const {
        return val>a.val;
    }
}p[maxn];
LL Ga[maxn];
int n;
int main() {
    while(~scanf("%d",&n)) {
        memset(Ga,0,sizeof(Ga));
        for(int i = 0;i<n;i++) scanf("%lld %d",&p[i].num,&p[i].val);
        sort(p,p+n);
        int ans = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<=60;j++) {
                if((p[i].num>>j)&1) {
                    if(Ga[j]) p[i].num^=Ga[j];
                    else {
                        Ga[j] = p[i].num;
                        break;
                    }
                }
            }
            if(p[i].num) ans+=p[i].val;
        }
        printf("%d\n",ans);
    }
    return 0;
}
