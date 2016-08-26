#include <bits/stdc++.h>
using namespace std;
int a[100],b[100];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);
    int sum =0,num = 0;
    for(int i = 0;i<n;i++) scanf("%d",&b[i]),sum+=b[i],num+=(a[i]*b[i]);
    printf("%.1f\n",num*1.0/sum);
    return 0;
}
