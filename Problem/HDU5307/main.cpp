#include <bits/stdc++.h>
#define CLR(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
typedef long double LD;
const int maxn = 101000;
const int maxm = 110000;
struct Complex{
    LD real,imag;
    Complex(){}
    Complex(LD _r,LD _I):real(_r),imag(_I){}
    Complex operator + (const Complex &a) const {
        return Complex(real+a.real,imag+a.imag);
    }
    Complex operator - (const Complex &a) const {
        return Complex(real-a.real,imag- a.imag);
    }
    Complex operator * (const Complex &a) const {
        return Complex(real*a.real-imag*a.imag,real*a.imag+imag*a.real);
    }
    void SetValue(LD r,LD i) {
        real= r,imag = i;
    }
    void Output() {
        printf("%Lf %Lf\n",real,imag);
    }
}a[maxn*2],b[maxn*2];
LL sum[maxn];
int lent[maxm];
int n,len;
LL ans[maxn];
int main() {
    int T;
    sum[0] = 0;
    for(int i =1;i<maxn;i++) sum[i] = sum[i-1]+LL(i*(i+1))/2;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)) {
        lent[0] = 0;
        for(int i = 1;i<=n;i++) {
            scanf("%d",&lent[i]);
            lent[i] +=lent[i-1];
        }
        CLR(ans,0);
        for(int i = 1;i<n;i++) {
            if(lent[i]==lent[i+1]) {
                for(int j = i;lent[j] == lent[i];j++) ;
                ans[0] += sum[j-i+1]; 
            }
        }
        len = 1;
        while(len<=(2*sum[n])) len<<=1;
        CLR(a,0); CLR(b,0);
        for(int i = 1;i<=n;i++) a[sum[i]].rea+=i;
        for(int i = 1)
    }
    return 0;
}
