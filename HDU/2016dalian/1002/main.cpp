#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 101000;
const int maxm = 100100;
int arr[maxn];
int rm[maxn][30];
map<int,int>fg;
int n,m;
int ans[maxm];
int Tr[maxn];
struct node {
    int l,r;
    int Id;
    bool operator < (const node &a) const {
        return r<a.r;
    }
}p[maxm];
struct Node {
    int l,r,g;
    bool operator <(const Node &a) const {
        return r<a.r;
    }
}sec[maxn*30];
int top;
void GetRMQ() {
    for(int i = 1;i<=n;i++) rm[i][0] = arr[i];
    for(int i = 1;(1<<i)<=n;i++) {
        for(int j = 1;(j+(1<<i)-1)<=n;j++) {
            rm[j][i] = __gcd(rm[j][i-1] ,rm[j+(1<<(i-1))][i-1]);
        }
    }
}
int Query(int L,int R) {
    int k = (int)(log((R-L+1)*1.0)/log(2.0));
    return __gcd(rm[L][k],rm[R-(1<<k)+1][k]);
}
void GetSection() {
    for(int i =1;i<=n;i++) {
        int st = i;
        while(st>=1) {
            int g = Query(st,i);
            sec[top].l = st; sec[top].r = i; sec[top++].g = g;
            int  l = 1,r = st,ans;
            while(l<=r) {
                int mid = (l+r)>>1;
                int d = Query(mid,i);
                if(d>=g) {
                    r = mid-1;
                    ans = mid;
                }
                else l = mid+1;
            }
            st = ans-1;
        }
    }
}
int lowbite(int x) {
    return x&(-x);
}
void add(int x,int d) {
    while(x<=n) {
        Tr[x]+=d;
        x+=lowbite(x);
    }
}
int qu(int x) {
    int ans = 0;
    while(x > 0) {
        ans+=Tr[x];
        x-=lowbite(x);
    }
    return ans;
}

int main(){
    while(~scanf("%d %d",&n,&m)) {
        for(int i = 1;i<=n;i++) scanf("%d",&arr[i]);
        GetRMQ();
        for(int i =1;i<=m;i++) {
            scanf("%d %d",&p[i].l,&p[i].r);
            p[i].Id = i;
        }
        sort(p+1,p+m+1);top = 0;
        GetSection();
        sort(sec,sec+top);
        memset(Tr,0,sizeof(Tr));
        fg.clear();
        for(int i = 1,j = 0;i<=m;i++) {
            while(j<top && sec[j].r <=p[i].r) {
                if(fg[sec[j].g]) {
                    add(fg[sec[j].g],-1);
                }
                fg[sec[j].g] = sec[j].l;
                add(fg[sec[j].g],1);
                j++;
            }
            ans[p[i].Id] = qu(p[i].r)-qu(p[i].l-1);
        }
        for(int i = 1;i<=m;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
