#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
using namespace std;
typedef long long LL;
const LL Mod = 1e9+7;
const double Pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int a[110];
char str[110];
int  main() {
    int T,k,x;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&x,&k);
        scanf("%s",str);
        int sum = 0;
        for(int i = 0;i<x-1;i++) {
            scanf("%d",&a[i]);

            if(str[i] == 'G'){
                continue;
            }
            else sum+=a[i];
        }
        if(sum>=k) printf("Meghana is Happy :)\n");
        else printf("Tihor is Sad :(\n");

    }
    return 0;
}
