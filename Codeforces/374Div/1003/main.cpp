#include <bits/stdc++.h>

using namespace std;

const int maxn = 5555;
const int INF = 0x3f3f3f3f;

int n,m,t;
int dp[maxn][maxn];
int pre[maxn][maxn];
vector<pair<int,int> >E[maxn];

void dfs(int u,int num,int val,int fa) {
    if(dp[u][num] <= val) return ;
    dp[u][num] = val; pre[u][num] = fa;
    for(int i = 0;i<E[u].size();i++) {
        if(val + E[u][i].second <=t) {
            dfs(E[u][i].first,num+1,val+E[u][i].second,u);
        }
    }
}
stack<int>st;
void out(int u,int num) {
    st.push(u);
    if(pre[u][num] == -1) {
        printf("%d\n",st.size());
        bool op = false;
        while(!st.empty()) {
            if(op) printf(" ");
            else op = true;
            printf("%d",st.top());
            st.pop();
        }
        printf("\n");
        return ;
    }
    out(pre[u][num],num-1);
}

int main() {
    int u,v,w;
    scanf("%d %d %d",&n,&m,&t);
    memset(dp,INF,sizeof(dp));
    memset(pre,-1,sizeof(pre));
    for(int i = 0;i<m;i++) {
        scanf("%d %d %d",&u,&v,&w);
        E[u].push_back(make_pair(v,w));
    }
    dfs(1,1,0,-1);
    for(int i = n;i>=2;i--) {
        if(dp[n][i] <= t) {
            out(n,i);
            break;
        }
    }
    return 0;
}
