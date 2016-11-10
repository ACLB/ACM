#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n,l[maxn],r[maxn];
int main() {
    int numl =0 ,numr=0;
    scanf("%d",&n);
    for(int i = 0 ;i<n;i++) {
        scanf("%d %d",&l[i],&r[i]);
        numl+=l[i];
        numr+=r[i];
    }
    int ans = 0 ,sum = 0;
    for(int i = 0;i<n;i++) {
        if(sum<abs(numl-l[i]+r[i]-(numr-r[i]+l[i]))-abs(numr-numl)) {
            sum=abs(numl-l[i]+r[i]-(numr-r[i]+l[i]))-abs(numr-numl);
            ans = i+1;
        }

    }
    printf("%d\n",ans);
    return 0;
}
