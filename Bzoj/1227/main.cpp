#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int Max =  110000;
const LL Mod = 1LL<<31;
struct node {
    LL x,y;
    bool operator < (const node &a)const {
        return (x==a.x)?y<a.y:x<a.x;
    }
} p[Max];
LL c[Max][15],Tr[Max];
LL ux[Max],uy[Max];
int numr[Max],numc[Max];
int num[Max];
LL n,m,k,w;
void Init() {
    c[0][0] = 1;
    for(int i =1; i<Max; i++) {
        c[i][0] =1;
        for(int j = 1; j<=13; j++) c[i][j] =(c[i-1][j]+c[i-1][j-1])%Mod;
    }
}
LL C(LL n, LL m) {
    if(m>n)  return 0;
    return c[n][m];
}
int lowbite(int x) {
    return x&(-x);
}
void upd(int x,LL d) {
    d =(d%Mod+Mod)%Mod;
    while(x<Max) {
        (Tr[x]+=d)%=Mod;
        x+=lowbite(x);
    }
}
LL que(int x) {
    LL ans = 0;
    while(x>0) {
        (ans+=Tr[x])%=Mod;
        x-=lowbite(x);
    }
    return ans;
}
int Lower_bound(int L,int R,LL aim,LL *a) {
    while(L<=R) {
        int mid = (L+R)>>1;
        if(aim == a[mid]) return mid;
        if(a[mid] < aim) L = mid+1;
        else R = mid-1;
    }
    return 0;
}
int main() {
    Init();
    while(~scanf("%lld %lld",&n,&m)) {
        scanf("%lld",&w);
        ux[0] = 0;
        uy[0] = 0;
        for(int i = 0; i<w; i++) {
            scanf("%lld %lld",&p[i].x,&p[i].y);
            ux[++ux[0]] = p[i].x;
            uy[++uy[0]] = p[i].y;
        }
        scanf("%lld",&k);
        sort(p,p+w);
        sort(ux+1,ux+1+ux[0]);
        sort(uy+1,uy+1+uy[0]);
        int s = ux[0];
        ux[0] =1;
        numr[1] =1;
        for(int i = 2; i<=s; i++) {
            if(ux[i]!=ux[ux[0]]) {
                ux[++ux[0]] = ux[i];
                numr[ux[0]] = 1;
            } else numr[ux[0]] ++;
        }
        s = uy[0];
        uy[0] = 1;
        numc[1] =1;
        for(int i = 2; i<=s; i++) {
            if(uy[i]!=uy[uy[0]]) {
                uy[++uy[0]] = uy[i];
                numc[uy[0]] = 1;
            } else numc[uy[0]] ++;
        }
        memset(Tr,0,sizeof(Tr));
        memset(num,0,sizeof(num));
        LL ans = 0;
        LL tep = 1;
        for(int i = 0; i<w; i++) {
            int Fx = Lower_bound(1,ux[0],p[i].x,ux);
            int Fy = Lower_bound(1,uy[0],p[i].y,uy);
            if(!i || p[i].x !=p[i-1].x) tep = 1;
            else tep++;
            if(tep != 1) {
                int Prey =  Lower_bound(1,uy[0],p[i-1].y,uy);
                LL ant = ((C(tep-1,k)*C(numr[Fx]-tep+1,k)%Mod)*((que(Fy-1)-que(Prey))%Mod))%Mod;
                ans = (ans+ant)%Mod;
            }
            upd(Fy,(C(num[Fy]+1,k)*C(numc[Fy]-num[Fy]-1,k))%Mod-(C(num[Fy],k)*C(numc[Fy]-num[Fy],k))%Mod);
            num[Fy]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
