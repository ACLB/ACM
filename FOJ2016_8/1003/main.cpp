#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int Max = 110000;
LL a[Max];
int n,m;
LL Get(LL s){
    while(s%2) {
        s/=2;
    }
    return s/2;
}
int Lowbit(int x) { return x&(-x);}

void upd(int x,LL s) {
    while(x<=n) {
        a[x]^=s;
        x+=Lowbit(x);
    }
}
LL qu(int x) {
    LL ans = 0;
    while(x>0) {
        ans^=a[x];
        x-=Lowbit(x);
    }
    return ans;
}
int main(){
    int st,l,r; LL x;
    while(~scanf("%d %d",&n,&m)) {
        memset(a,0,sizeof(a));
        for(int i = 1;i<=n;i++) {
            scanf("%I64d",&x);
            upd(i,Get(x));
        }
        while(m--) {
            scanf("%d %I64d %d %d",&st,&x,&l,&r);
            LL ans = qu(st)^qu(st-1);
            upd(st,ans); upd(st,Get(x));
            ans = qu(r)^qu(l-1);
            if(ans) printf("daxia\n");
            else printf("suneast\n");
        }
    }
    return 0;
}
