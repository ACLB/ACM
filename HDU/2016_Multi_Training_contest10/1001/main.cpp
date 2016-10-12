#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Max =  110000;
LL a[Max];
int main(){
    int n,m;
    int l1,r1,l2,r2;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        for(int i = 1;i<=n;i++) scanf("%I64d",&a[i]);
        while(m--) {
            scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
            if(l1>l2) {
                swap(l1,l2); swap(r1,r2);
            }
            double ans = 0;
            if(r1<l2) {
                int len = r1-l1+1+r2-l2+1;

                if(len %2 == 0) {
                    len /=2;
                    if(l1+len-1<=r1) ans+=a[l1+len-1];
                    else ans+=a[l2+(len-(r1-l1+1))-1];
                    len++;
                    if(l1+len-1<=r1) ans+=a[l1+len-1];
                    else ans+=a[l2+(len-(r1-l1+1))-1];
                    ans/=2;
                }
                else {
                    len = (len/2+1);
                    if(l1+len-1<=r1) ans+=a[l1+len-1];
                    else ans+=a[l2+(len-(r1-l1+1))-1];
                }
            }
            else {
                if(r1>=l2&&r1<=r2) {
                    int l = max(l1,l2); int r = min(r1,r2);
                    int len = r2-l1+1+r-l+1;
                    if(len %2 ==0) {
                        len/2;
                        if(l1+len-1<l) {
                            ans+=a[l1+len-1];
                        }
                        else {
                            int s = (len-(l-l1+1)+1)/2; int t =
                            if(l+s-1<=r) {
                                ans+=a[s];
                            }
                            else {

                            }
                        }
                    }
                }
                else {

                }
            }
            printf("%.1f\n",ans);
        }
    }
    return 0;
}
