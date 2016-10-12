#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int Max =  110000;
int n,m;
vector<int>E[Max];
LL w[Max],sum,ans;
void Init() {
    sum = 0;
    for(int i = 1;i<=n;i++) E[i].clear();
}
void Input(){
    int u,v;
    for(int i = 1; i<=n;i++) scanf("%I64d",&w[i]),sum+=w[i];
    for(int i = 0;i<m;i++) {
        scanf("%d %d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    ans = sum;
}
LL Abs(LL a) {return a>0?a:-a;}
LL dfs(int u,int fa) {
    LL s = 0;
    for(int i = 0;i<E[u].size();i++) {
        if(E[u][i] == fa) continue;
        LL t= dfs(E[u][i],u);
        ans = min(ans,Abs(sum-2*t));
        s+=t;
    }
    s+=w[u];
    return s;
}
void Solve() {
    dfs(1,0);
    printf("%I64d\n",ans);
}
int main(){
    int z  =1;
    while(~scanf("%d %d",&n,&m) &&(n||m)) {
        Init();
        Input();
        printf("Case %d: ",z++);
        Solve();
    }
    return 0;
}
