#include <bits/stdc++.h>

using namespace std;
int a[4],b[4];
int main() {
    for(int i = 0;i<3;i++) scanf("%d",&a[i]);
    for(int i = 0;i<3;i++) scanf("%d",&b[i]);
    int ans1 = 0,ans2 = 0;
    for(int i = 0;i<3;i++) {
        if(a[i]>b[i])ans1++;
        if(b[i]>a[i])ans2++;
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}
