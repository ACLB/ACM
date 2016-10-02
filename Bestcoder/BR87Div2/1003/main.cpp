#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <stack>
#include <functional>
#include <vector>
#include <algorithm>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
using namespace std;

typedef long long LL;
const int mod = 1e9+7;
const double pi = acos(-1.0);
const double eps = 1e-9;
const double e = exp(1.0);
const int maxn = 1e6+100;
int a[1001];
int n,m;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i  = 0;i<n;i++) scanf("%d",&a[i]);
        set<int>st;
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++)
                st.insert(__gcd(a[i],a[j]));
        }
        bool op = false;
        for(set<int>::iterator it = st.begin();it != st.end();it++) {
            if(op) printf(" ");
            else op  = true;
            printf("%d",*it);
        }
        printf("\n");

    }
    return 0;
}
