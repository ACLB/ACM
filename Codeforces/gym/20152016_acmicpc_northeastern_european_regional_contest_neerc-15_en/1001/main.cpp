#include <bits/stdc++.h>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
using namespace std;
typedef long long LL;
const LL maxn = 1e6+100;

bool visx[maxn],visy[maxn];

int main() {
    fread("adjustment.in");
    fwrite("adjustment.out");
    LL n,q,c;
    char op[2];
    scanf("%I64d %I64d",&n,&q);
    memset(visx,false,sizeof(visx));
    memset(visy,false,sizeof(visy));
    LL sum = (1LL+n)*n/2;
    LL row = 0,col = 0;
    LL numr =0,numc = 0;
    while(q--) {
    scanf("%s %I64d",op,&c);
        LL ans = 0;
        if(op[0] == 'R') {
            if(!visx[c])  {
                ans = 1LL*c*(n-numc)+sum-col;
                row+=c;
                numr++;
                visx[c] = true;
            }
        } else {
            if(!visy[c]) {
                ans = 1LL*c*(n-numr)+sum-row;
                col += c;
                numc++;
                visy[c] = true;
            }
        }
        printf("%I64d\n",ans);
    }

    return 0;
}
