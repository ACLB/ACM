#include <bits/stdc++.h>
using namespace std;
const int Max = 3000;
int a[Max];
int main() {
    int n;
    scanf("%d",&n);
    int sum = 0;
    double ans1,ans2;
    int ans3;
    for(int i = 0;i<n;i++) scanf("%d",&a[i]),sum+=a[i];
    ans1 = sum*1.0/n;
    sort(a,a+n);
    if(n%2 == 1) {
        ans2 = a[n/2];
    }
    else ans2 = (a[n/2-1]+a[n/2])*1.0/2;

    int num = 0,st = a[0];
    int an = 1;
    for(int i =1;i<n;i++) {
        if(st == a[i]) an++;
        else {
            if(num<an) {
                num = an;
                ans3 = st;
            }
            st = a[i];
            an = 1;
        }
    }
    if(num<an) {
        num = an;
        ans3 = st;
    }
    printf("%.1f\n%.1f\n%d\n",ans1,ans2,ans3);
    return 0;
}
