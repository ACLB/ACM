#include <bits/stdc++.h>
#define fread(x) freopen(x,"r,",stdin)
#define fwrite(x) freopen(x,"w",stdout)
using namespace std;
const int Max = 8100;
int a[Max];
int cnt[Max*2];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++) {
        memset(cnt,0,sizeof(cnt));
        int temp = n;
        cnt[temp]++;
        for(int j = i-1;j>=1;j--) {
            if(a[j] >a[i]) temp++;
            else if(a[j]<a[i]) temp--;
            cnt[temp] ++;
        }
        int ans = cnt[n];
        temp = n;
        for(int j = i+1;j<=n;j++) {
            if(a[j]>a[i]) temp--;
            else if(a[j]<a[i]) temp++;
            ans +=cnt[temp];
        }
        if(i!=1) printf(" ");
        printf("%d",ans);
    }
    printf("\n");
    return 0;
}
