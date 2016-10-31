#include <bits/stdc++.h>

using namespace std;

const int maxn = 30100;

int pre[maxn];
int sum[maxn];
int num[maxn];
int Find(int x) {
    if(pre[x] == x) {
        return x;
    }
    else {
        int Fa = pre[x];
        int s = Find(Fa);
        sum[x]+=sum[Fa];
        pre[x] = s;
        return s;
     }
}

void Union(int x,int y) {
    int Fx = Find(x);
    int Fy = Find(y);
    if(Fx!=Fy) {
        sum[Fx] = num[Fy];
        num[Fy] += num[Fx];
        pre[Fx] = Fy;
    }
}

int main(){
    int m;
    char op[2];
    int u,v;
    while(~scanf("%d",&m)) {
        for(int i = 0;i<maxn;i++) pre[i] = i,num[i] = 1,sum[i] = 0;
        while(m--) {
            scanf("%s",op);
            if(op[0] == 'M') {
                scanf("%d %d",&u,&v);
                Union(u,v);
            }
            else {
                scanf("%d",&u);
                Find(u);
                printf("%d\n",sum[u]);
            }
        }
    }
    return 0;
}
