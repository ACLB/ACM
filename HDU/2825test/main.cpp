#include <bits/stdc++.h>
using namespace std;
const int mod = 20090717;
const int maxn = 120;
typedef long long LL;
int tr[maxn][26],top;
int fail[maxn];
char str[maxn];
int n,m,k;
int flag[maxn];
int dp[26][maxn][1<<10];
void insert(char *s,int k){
    int x=0;
    for(int i=0; s[i]; ++i){
        int y=s[i]-'a';
        if(tr[x][y]==0) tr[x][y]=++top;
        x=tr[x][y];
    }
    flag[x]|= 1<<k;
}
void GetFail(){
    memset(fail,0,sizeof(fail));
    queue<int> Q;
    for(int i=0; i<26; ++i){
        if(tr[0][i]) Q.push(tr[0][i]);
    }
    while(!Q.empty()){
        int x=Q.front(); Q.pop();
        for(int i=0; i<26; ++i){
            if(tr[x][i]) {
                Q.push(tr[x][i]);
                fail[tr[x][i]]=tr[fail[x]][i];
                flag[tr[x][i]]|=flag[tr[fail[x]][i]];
            }
            else tr[x][i]=tr[fail[x]][i];
        }
    }
}
int cnt(int s){
    int ans=0;
    for(int i=0; i<m; ++i){
        if((s>>i)&1) ++ans;
    }
    return ans;
}
int main(){
    while(~scanf("%d %d %d",&n,&m,&k) && (n||m||k)){
        top=0;
        memset(tr,0,sizeof(tr));
        memset(flag,0,sizeof(flag));
        for(int i=0; i<m; ++i){
            scanf("%s",str);
            insert(str,i);
        }
        GetFail();
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for(int i=0; i<n; ++i){
            for(int j=0; j<=top; ++j){
                for(int s=0; s<(1<<m); ++s){
                    if(dp[i][j][s]==0) continue;
                    for(int t=0; t<26; ++t){
                        (dp[i+1][tr[j][t]][s|flag[tr[j][t]]]+=dp[i][j][s])%=mod;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<=top; ++i){
            for(int j=0; j<(1<<m); ++j){
                if(cnt(j)<k) continue;
                (ans+=dp[n][i][j])%=mod;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
