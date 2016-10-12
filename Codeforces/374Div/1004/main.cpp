#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5;
struct node {
    LL a;
    int id;
    bool operator < (const node &b) const {
        return abs(a)>abs(b.a);
    }
}p[maxn*2];
bool cmp(node a,node b) {
    return a.id<b.id;
}
int main() {
    int n,k,x; node da;
    scanf("%d %d %d",&n,&k,&x);
    bool op = false;
    priority_queue<node>Q;
    for(int i = 0;i<n;i++) {
        scanf("%lld",&da.a);
        da.id = i;
        Q.push(da);
        if(da.a<0) op = !op;
    }
    while(k--) {
        da = Q.top() ; Q.pop();
        if(da.a < 0) {
            if(op) {
                da.a-=x;
            }
            else da.a +=x;
            if(da.a >= 0) op=!op;
            Q.push(da);
        }
        else {
            if(op) {
                da.a+=x;
            }
            else da.a-=x;
            if(da.a < 0) op=!op;
            Q.push(da);
        }
    }
    int num = 0;
    while(!Q.empty()) {
        p[num++] = Q.top(); Q.pop();
    }
    sort(p,p+n,cmp);
    for(int i = 0;i<n;i++) {
        if(i) printf(" ");
        printf("%lld",p[i].a);
    }
    printf("\n");
    return 0;
}
