#include <bits/stdc++.h>
using namespace std;
int n;
long long  a[550][550];
bool ok() {
    long long sum1 = 0,sum2 = 0;
    for(int i =0;i<n;i++) {
        sum1+=a[0][i];
    }
    for(int i = 0;i<n;i++) {
        sum2 = 0;
        for(int j = 0;j<n;j++) sum2+=a[i][j];
        if(sum1!=sum2) return false;
    }
    for(int i = 0;i<n;i++) {
        sum2 = 0;
        for(int j = 0;j<n;j++) sum2+=a[j][i];
        if(sum1!=sum2) return false;
    }
    sum2 = 0;
    for(int i = 0;i<n;i++) sum2+=a[i][i];
    if(sum1 !=sum2) return false;
    sum2 = 0;
    for(int i = 0;i<n;i++) sum2+=a[i][n-1-i];
    if(sum1!=sum2) return false;
    return true;
}
int main() {
    scanf("%d",&n);
    int x,y;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            scanf("%I64d",&a[i][j]);
            if(a[i][j] == 0) {
                x = i,y = j;
            }
        }
    }
    if(n == 1) printf("1\n");
    else {
        long long  sum  = 0;
        for(int i = 0;i<n;i++) {
            if(i!=x) {
                for(int j = 0;j<n;j++) {
                    sum+=a[i][j];
                }
                break;
            }
        }
        long long  sum1 = 0;
        for(int i = 0;i<n;i++) {
            if(i!=y) sum1+=a[x][i];
        }
        a[x][y] = sum-sum1;
        if(a[x][y]<=0) printf("-1\n");
        else {
            if(ok()) printf("%I64d\n",a[x][y]);
            else printf("-1\n");
        }
    }
    return 0;
}
