#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[30];
LL dp[30][5];
void GetBit(LL s) {
    a[0] = 0;
    while(s) {
        a[++a[0]] = s%10;
        s/=10;
    }
}
LL dfs(int pos,bool limit,int status) {
    if(pos == 0) {
        if(status == 2 ||status == 3) return 1;
        else return 0;
    }
    if(!limit && dp[pos][status]) return dp[pos][status] ;
    int end = limit?a[pos]:9;
    LL ans = 0;
    for(int i = 0;i<=end;i++) {
        if(!status) {
            if(!i) ans += dfs(pos-1,0,0);
            else {
                if(i&1) ans+=dfs(pos-1,limit&& i == end,1);
                else ans+=dfs(pos-1,limit && i==end,3);
            }
        }
        else {
            if(status == 1) if(i&1) ans+=dfs(pos-1,limit && i == end,2);
            else if(status == 2) {
                if(i&1) ans+=dfs(pos-1,limit && i == end,1);
                else ans+=dfs(pos-1,limit && i==end, 3);
            }
            else if(status == 3) {
                if(i&1) ans +=dfs(pos-1,limit && i== end,1);
                else ans+=dfs(pos-1,limit && i==end,4);
            }
            else if(status == 4) if(!(i&1)) ans+=dfs(pos-1,limit && i==end,3);
        }
    } 
    return dp[pos][status] = ans;
}
LL solve(LL s) {
    GetBit(s);
    memset(dp,0,sizeof(dp));
    return dfs(a[0],1,0);
}
int main() {
    LL l,r;
    int T,z=1;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld %lld",&l,&r);
        printf("Case #%d: %lld\n",z++,solve(r)-solve(l-1));
    }
    return 0;
}
