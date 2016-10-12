#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Max = 10;
const LL Mod = 1e9+7;
struct Matrix {
    int n,m;
    LL a[Max][Max];
    void Clear() {n = m = 0; memset(a,0,sizeof(a));}
    Matrix operator * (const Matrix & b) const {
        Matrix temp; temp.Clear();
        temp.n = n; temp.m = b.m;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<b.m;j++) {
                for(int k = 0;k<m;k++) 
                    temp.a[i][j] = (temp.a[i][j]+(a[i][k]*b.a[k][j])%Mod)%Mod;
            }
        }
        return temp;
    }
};
Matrix Pow(LL n,Matrix m) {
    Matrix ans ;
    ans.Clear();
    ans.n = 4; ans.m = 1;
    ans.a[0][0] = 1;
    while(n) {
        if(n%2) ans = m*ans;
        m = m*m;
        n>>=1;
    }
    return ans;
}
int main() {
    LL n;
    while(~scanf("%lld",&n)) {
        Matrix s ; s.Clear();
        s.n = s.m = 4;
        s.a[0][0] = 2; s.a[0][1] = 1; s.a[0][2] = 1;
        s.a[1][0] = 1; s.a[1][1] = 2; s.a[1][3] = 1;
        s.a[2][0] = 1; s.a[2][2] = 2; s.a[2][3] = 1;
        s.a[3][1] = 1; s.a[3][2] = 1; s.a[3][3] = 2;
        Matrix ans = Pow(n,s);
        printf("%lld\n",ans.a[0][0]);
    }
    return 0;
}
