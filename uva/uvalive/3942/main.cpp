#include <bits/stdc++.h>

using namespace std;

const int maxn = 310000;
const int maxm = 123;
const int mod = 20071027;

struct node {
    bool op;
    int next[26];
} trie[maxm*4000];

int top;
char str[maxm];
char c[maxn];
int Creat() {
    memset(trie[top].next,-1,sizeof(trie[top].next));
    trie[top].op = false;
    return top++;
}
void Build(int root) {
    int len = strlen(str);
    int st ;
    for(int i = 0; i<len; i++) {
        st = str[i]-'a';
        if(trie[root].next[st] == -1) trie[root].next[st] = Creat();
        root = trie[root].next[st];
    }
    trie[root].op = true;
}
int dp[maxn];
int n,m;
int dfs(int root,int index) {
    int ans = 0;
    for(int i = index; i<m; i++) {
        int st = c[i]-'a';
        if(trie[root].next[st] == -1) return ans;
        root = trie[root].next[st];
        if(trie[root].op) (ans +=dp[i+1])%=mod;
    }
    return ans;
}
int main() {
    int z = 1;
    while(~scanf("%s",c)) {
        top = 0;
        scanf("%d",&n);
        int root = Creat();
        for(int i = 0; i<n; i++) {
            scanf("%s",str);
            Build(root);
        }
        memset(dp,0,sizeof(dp));
        m = strlen(c);
        dp[m] = 1;
        for(int i = m -1; i>=0; i--) {
            (dp[i] += dfs(root,i))%=mod;
        }
        printf("Case %d: %d\n",z++,dp[0]);
    }
    return 0;
}
