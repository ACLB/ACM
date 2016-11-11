#include <bits/stdc++.h>

using namespace std;
const int maxn = 550;
int a[maxn],b[maxn];
int n,k;
bool ok() {
    int num = 0,sum = 0,st = 0;
    for(int i = 0;i<n;i++) num+=a[i];
    for(int i = 0;i<k;i++) sum+=b[i];
    if(sum!=num) return false;
    num =0;sum =0;
    for(int i =0 ;i<n;i++) {
        sum+=a[i];
        if(sum>=b[st]) {
            sum = 0;
            st ++;
        }
    }
    if(sum>=b[st]) st++;
    if(st!=k) return false;
    int l = 0;
    sum =0 ,st = 0;
    for(int i = 0;i<n;i++) {
        sum+=a[i];
        if(sum>=b[st]) {
            int len = i - l+1;

        }
    }
}
int main() {
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i = 0;i<m;i++) scanf("%d",&b[i]);
    if(ok()) {

    }
    return 0;
}
