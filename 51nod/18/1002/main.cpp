#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL Mod = 1e9+7;

struct matrix {
    LL a[5][5];
    int n,m;
    void Clear() {
        n = m = 0;
        memset(a,0,sizeof(a));
    }
    matrix operator * (const matrix &b) const {
        matrix temp;
        temp.Clear();
        temp.n = n;temp.m = b.m;
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=b.m;j++) {
                for(int k = 1;k<=m;k++) {

                    temp.a[i][j] = (temp.a[i][j] + (a[i][k] * b.a[k][j])%Mod)%Mod;
                }
            }
        }
        return temp;
    }
};

void solve(LL n){
    matrix ans;
    ans.Clear();
    ans.n = 4;
    ans.m = 1;
    ans.a[1][1] = ans.a[2][1] = ans.a[3][1] = ans.a[4][1] = 1;
    matrix s;
    s.Clear();
    s.n = 4; s.m=  4;
    s.a[1][1] =s.a[1][2] = s.a[2][4] = s.a[3][1] = s.a[3][2] = s.a[4][3] = s.a[4][4] = 1;
    while(n) {

        if(n &1) ans = s*ans;
        s = s*s;
        n>>=1;
    }
    LL sum =0;
    sum = (sum+ans.a[1][1])%Mod;
    sum = (sum+ans.a[2][1])%Mod;
    sum = (sum+ans.a[3][1])%Mod;
    sum = (sum+ans.a[4][1])%Mod;
    cout<<sum<<endl;
}
int main(){
    LL n;
    cin>>n;
    if(n == 0) cout<<0<<endl;
    else if(n==1) cout<<2<<endl;
    else if(n == 2) cout<<4<<endl;
    else solve(n-2);
    return 0;
}
