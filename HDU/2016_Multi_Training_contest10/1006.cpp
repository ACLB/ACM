#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#define LL long long
#define Pr pair<LL,LL>
#define zero(x) (((x) >0 ?(x):(-x))<eps)
#define fread(ch) freopen(ch,"r",stdin)
#define fwrite(ch) freopen(ch,"w",stdout)

using namespace std;
const LL INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double  Pi = acos(-1.0);
const LL mod = 1000000007;
const LL Max = 110000;

struct node {
    LL x,y;
    LL l,r;
    LL op;
    bool operator < (const node &a)const {
        if(x==a.x){
            if(op==a.op) return y<a.y;
            else return op>a.op;
        }
        return x<a.x;
    }
} p[Max*5];
LL st[Max*8],s;
LL Tr[Max*8];
LL lowbite(LL x) { return x&(-x);}
void upd(LL x,LL d) {
    while(x<=s) {
        st[x]+=d;
        x+=lowbite(x);
    }
}
LL qu(LL x) {
    LL ans = 0;
    while(x>0) {
        ans+=st[x];
        x-=lowbite(x);
    }
    return ans;
}
int main() {
    LL T,n;
    LL x1,y1,x2,y2;
    scanf("%I64d",&T);
    while(T--) {
        Tr[0 ] =0; LL m = 0;
        scanf("%I64d",&n);
        for(LL i = 0; i<n; i++) {
            scanf("%I64d %I64d %I64d %I64d",&x1,&y1,&x2,&y2);
            if(y1 == y2) {
                p[m].x = min(x1,x2); p[m].y =y1;
                p[m++].op = 1;
                p[m].x = max(x1,x2); p[m].y = y2;
                p[m++].op = -1;
                Tr[++Tr[0]]= y1;
            } else  {
                p[m].x = x1; p[m].y = min(y1,y2);
                p[m].l = min(y1,y2); p[m].r = max(y1,y2);
                p[m++].op = 0;
                Tr[++Tr[0]] = y1;
                Tr[++Tr[0]] = y2;
            }
        }
        sort(Tr+1,Tr+Tr[0]+1);
        sort(p,p+m);
        s = Tr[0]; Tr[0] =1;
        for(LL i =2; i<=s; i++) if(Tr[Tr[0]]!= Tr[i]) Tr[++Tr[0]] = Tr[i];
        s = Tr[0];LL ans =0;
        memset(st,0,sizeof(st));
        for(LL i = 0; i<m; i++) {
            if(p[i].op == 1) {
                LL l = lower_bound(Tr+1,Tr+1+Tr[0],p[i].y)-Tr;
                upd(l,1);
            }
            else if(p[i].op == 0) {
                LL L = lower_bound(Tr+1,Tr+1+Tr[0],p[i].l)-Tr;
                LL R = lower_bound(Tr+1,Tr+1+Tr[0],p[i].r)-Tr;
                ans+=(qu(R)-qu(L-1));
            }
            else {
                LL l = lower_bound(Tr+1,Tr+1+Tr[0],p[i].y)-Tr;
                upd(l,-1);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
