#include <bits/stdc++.h>

using namespace std;
const int maxn = 550;
int a[maxn];
int b[maxn];
int main(){
    int  n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0 ;i<n;i++) scanf("%d",&a[i]);
    int sum = 0;
    for(int i = 1;i<n;i++) {
        b[i] = k-a[i]-a[i-1]-b[i-1]>=0?k-a[i]-b[i-1]-a[i-1]:0;
        sum+=b[i];
    }
    printf("%d\n",sum);
    for(int i = 0;i<n;i++) {
        if(i) printf(" ");
        printf("%d",a[i]+b[i]);
    }
    printf("\n");
    return 0;
}
