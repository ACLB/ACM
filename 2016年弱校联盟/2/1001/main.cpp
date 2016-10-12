#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1100;

int a[maxn];

bool ok(int s) {
    int st =s%10;
    s/=10;
    while(s) {
        if(s%10 == st-1) st = s%10;
        else return false;
        s/=10;
    }
    return true;
}

int main() {
    int n;
    scanf("%d",&n);
    int ans = -1;
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);
    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            if(ok(a[i]*a[j])) ans = max(ans,a[i]*a[j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
