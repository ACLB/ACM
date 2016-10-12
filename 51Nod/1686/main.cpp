#include <bits/stdc++.h>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
using namespace std;
typedef long long LL;
const int Max = 1e6;
LL arr[Max],a[Max];
int Ls[Max];
int n,k;
int num[Max];
bool ok(int s) {
    memset(num,0,sizeof(num));
    LL nu = 0; int L = 1;
    for(int i = 1;i<=n;i++ ){
        num[Ls[i]]++;
        if(num[Ls[i]] > s) {
            while(num[Ls[i]]> s) {
                nu+=(n-i+1);
                num[Ls[L++]]--;
            }
        }
        if(nu >= k) return false;
    }
    return nu<=k;
}
int Solve() {
    int L = 1,R = n,ans =  1;
    while(L<=R) {
        int mid = (L+R)>>1;
        if(ok(mid)) {
            ans = mid;
            R = mid-1;
        }
        else L = mid+1; 
    }
    return ans;
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i =1 ; i<=n;i++) {
        scanf("%lld",&arr[i]);
        a[i] = arr[i];
    }
    sort(arr+1,arr+n+1);
    arr[0] = 1;
    for(int i = 2;i <= n;i++) if(arr[arr[0]] != arr[i]) arr[++arr[0]] = arr[i];
    for(int i = 1;i <= n;i++) Ls[i] = lower_bound(arr+1,arr+arr[0]+1,a[i])-arr;
    printf("%d\n",Solve());
    return 0;
}
