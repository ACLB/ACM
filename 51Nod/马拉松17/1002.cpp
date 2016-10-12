#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Mod = 1e9+7;
struct Matrix {
    LL a[5][5];

    int n,m;
    void Clear() {
        n = m = 0;
        memset(a,0,sizeof(a));
    }
    Matrix  operator * (const Matrix  & b) const {
        Matrix temp; temp.Clear();

        temp.n = n; temp.m = b.m;
        for(int i = 0;i<n;i++) {
            for(int j = 0 ;j<b.m;j++) {
                for(int k = 0 ;k<m;k++) {
                    temp.a[i][j] = (temp.a[i][j] + (a[i][k] * b.a[k][j])%Mod)%Mod;
                }
            }
        }
        return temp;
    }
};
Matrix Pow(LL m) {
    Matrix ans ; ans.Clear();
    ans.n = 1; ans.m = 2;
    ans.a[0][0] = ans.a[1][0] = 1;
    Matrix s ; s.Clear();
    s.n = s.m = 2;
    s.a[0][0] = s.a[0][1] = 1;
    s.a[1][0] =2; s.a[1][1] = 1;

    while(m) {
        if(m&1) ans = s*ans;

        s = s*s;
        m>>=1;
    }
    return ans;
}
int main() {
    LL n;
    while(~scanf("%lld",&n)) {
        if(n == 0) {
            printf("1\n");
            continue;
        }
        Matrix ans = Pow(n-1);
        LL an;
        if(n&1) {
            an =(((ans.a[0][0]*ans.a[0][0])%Mod)*2)%Mod;
        }
        else an = (ans.a[1][0]*ans.a[1][0])%Mod;

        printf("%lld\n",an);
    }
    return 0;
}
