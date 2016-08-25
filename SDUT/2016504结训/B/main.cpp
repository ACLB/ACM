#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
using namespace std;
int sum[110][110];
int num[5][110];
int n,m;
int ans ; 
bool Judge(int ss){
    int sum1= 0,sum2 = 0,sum3 = 0,sum0 = 0;
    int pos = 0;
    for(int i = 0;i<m;i++){
        sum0 += num[0][i];
        sum1 += num[1][i];
        sum2 += num[2][i];
        sum3 += num[3][i];
        if(sum0 >= ss && sum1 >= ss && sum2 >= ss &&sum3 >= ss){ sum0 = sum1 = sum2 = sum3 = 0; pos++;} 
        if(pos >= 4) return true;
    }
    return pos >= 4;
}
int Ok(int st1,int st2,int st3){
    for(int i = 0;i < m;i++){
        num[0][i] = sum[st1][i];
        num[1][i] = sum[st2][i] - sum[st1][i];
        num[2][i] = sum[st3][i] - sum[st2][i];
        num[3][i] = sum[n][i] - sum[st3][i];
    }
    int l = 0,r = 90000;
    int ac = 0 ;
    while(l <= r){
        int mid = (l+r) >>1;
        if(Judge(mid)){
            ac = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ac;
}
void solve(){
    ans = 0;
    for(int i = 1;i <= n-1;i++)
        for(int j = i+1; j <= n-1 ;j++)
            for(int k = j+1;k <= n-1;k++)
                ans = max(ans,Ok(i,j,k));
}
int chocolate[110][110];
int main(){ 
    rr("data1.in");
    ww("data1.out");
    while(~scanf("%d %d",&n,&m)){
        for(int i = 0;i<n;i++) 
            for(int j = 0;j<m;j++)
                scanf("%d",&chocolate[i][j]);
        memset(sum,0,sizeof(sum));
        for(int i = 0;i<n;i++)
              for(int j = 0 ;j<m;j++)
                  sum[i+1][j] = sum[i][j] + chocolate[i][j];
        solve();
        printf("%d\n",ans);
    }
    return 0;
}
