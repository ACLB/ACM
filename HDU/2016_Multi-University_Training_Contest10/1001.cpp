#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Max =  110000;
LL a[Max];
int main() {
    int n,m,T;
    int x1,y1,x2,y2;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
        while(m--) {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1>x2) {
                swap(x1,x2);swap(y1,y2);
            }
            double ans = 0;
            if(y1<x2) {
                int len = (y1-x1+1)+(y2-x2+1);
                if(len%2 ==0) {
                    len/=2;
                    if(x1+len-1<=y1) {
                        ans+=a[x1+len-1];
                    }
                    else ans+=a[x2+(len-(y1-x1+1))-1];
                    len++;
                    if(x1+len-1<=y1) {
                        ans+=a[x1+len-1];
                    }
                    else ans+=a[x2+(len-(y1-x1+1))-1];
                    ans/=2;
                }
                else {
                    len=(len+1)/2;
                    if(x1+len-1<=y1) {
                        ans+=a[x1+len-1];
                    }
                    else ans+=a[x2+(len-(y1-x1+1))-1];
                }
            }
            else {
                int l = max(x2,x1);int r = min(y1,y2);
                int L = min(x1,x2); int R = max(y1,y2);
                int len = (max(y1,y2)-min(x1,x2)+1+(r-l+1));

                if(len%2 ==0) {
                    len/=2; int s = len;
                    if(L+s-1<l) {
                        ans+=a[L+s-1];
                    }
                    else {
                        s -= (l-L);
                        s = (s+1)/2;
                        if(l+s-1<=r) ans+=a[l+s-1];
                        else {
                            s= len-(l-L)-(r-l+1)*2;

                            ans+=a[r+s];
                        }
                    }
                    len++; s = len;
                    if(L+s-1<l) {
                        ans+=a[L+s-1];
                    }
                    else {
                        s -= (l-L);
                        s = (s+1)/2;
                        if(l+s-1<=r) ans+=a[l+s-1];
                        else {
                            s= len-(l-L)-(r-l+1)*2;

                            ans+=a[r+s];
                        }
                    }

                    ans/=2;
                }
                else {
                
                    len=(len+1)/2; int s = len;
                    if(L+s-1<l) {
                        ans+=a[L+s-1];
                    }
                    else {
                        s -= (l-L);
                        s = (s+1)/2;
                        if(l+s-1<=r) ans+=a[l+s-1];
                        else {
                            s= len-(l-L)-(r-l+1)*2;

                            ans+=a[r+s];
                        }
                    }
                }
            }
            printf("%.1f\n",ans);
        }
    }
    return 0;
}
