#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
#define LL long long

using namespace std;

const int Max = 1e6+100;
const double Pi = acos(-1.0);
const double eps = 1e-8;

int n,m,d,k;
void Multi(LL a[],LL b[],LL ans[]) {
    LL z[1100];
    memset(z,0,sizeof(z));
    for(int i =0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            if(i>=j) z[i] = (z[i]+ (a[j]*b[i-j])%m)%m;
            else z[i] = (z[i]+(a[j]*b[i-j+n])%m)%m;
        }
    }
    for(int i = 0;i<n;i++) ans[i] = z[i];
}
LL s[1100];
LL a[1100];
LL b[1100];
void Pow() {
    while(k) {
        if(k&1) {
            Multi(b,s,b);
        }
        k>>=1;
        Multi(s,s,s);
    }
}
int main() {
    while(~scanf("%d %d %d %d",&n,&m,&d,&k)) {
        for(int i = 0;i<n;i++) scanf("%lld",&a[i]);
        memset(s,0,sizeof(s));
        memset(b,0,sizeof(b));
        b[0] = 1;
        for(int i = 0;i<=d;i++) s[i] = 1;
        for(int i = n-1;i>=n-d;i--)s[i] = 1;
        Pow();
        Multi(a,b,a);
        for(int i = 0;i<n;i++) {
            if(i) printf(" ");
            printf("%lld",a[i]);
        }
        printf("\n");
    }
    return 0;
}
