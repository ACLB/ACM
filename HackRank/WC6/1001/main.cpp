#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5+100;
int n,k;
int a,sum,da;
int main() {
    scanf("%d %d",&n,&k);
    sum  = 0 ;
    for(int i = 0;i<n;i++) {
        scanf("%d",&a);
        if(i != k) sum+=a;
    }
    scanf("%d",&da);
    sum/=2;
    if(sum<da) printf("%d\n",da- sum);
    else printf("Bon Appetit\n");
    return 0;
}
