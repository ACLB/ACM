#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 3000001;
LL sum[maxn];
void GetPhi() {
    sum[1] = 1;
    for(int i = 2;i<maxn;i++) {
        if(!sum[i]) {
            for(int j = i;j<maxn;j+=i) {
              if(!sum[j]) sum[j] = j;
              sum[j] = sum[j]/i*(i-1);
            }
        }
        sum[i]+=sum[i-1];
    }
}

int main(){
    GetPhi();
    int a,b;
    while(~scanf("%d %d",&a,&b)) {
        printf("%lld\n",sum[b]-sum[a-1]);
    }
    return 0;
}
