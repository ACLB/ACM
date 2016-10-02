#include <bits/stdc++.h>
#define ww(x) freopen(x,"w",stdout)
#define rr(x) freopen(x,"r",stdin)
using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double Pi = acos(-1.0);
const int Max = 1e6+1000;
int h[27];
char str[110];
int main() {
    for(int i = 0 ;i<26;i++) scanf("%d",&h[i]);
    scanf("%s",str);
    int len = strlen(str);
    int s = 0;
    for(int i =0 ;i<len;i++) s = max(s,h[str[i]-'a']);
    printf("%d\n",s*len);
    return 0;
}

