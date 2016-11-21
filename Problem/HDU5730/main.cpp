#include <bits/stdc++.h>
#define CLR(a,b) memset(a,b,sizeof(a))
using namespace std;
const double Pi = acos(-1.0);
const int maxn = 1e5+100;
const int Mod = 313;
struct Complex{
    double real, imag;
    Complex(){}
    Complex(double _r,double _i):real(_r),imag(_i){}
    Complex operator + (const Complex &a) const {
        return Complex(real+a.real,imag + a.imag);
    }
    Complex operator - (const Complex &a) const {
        return Complex(real-a.real,imag - a.imag);
    }
    Complex operator * (const Complex &a) const {
        return Coomplex(real*a.real-imag*a.imag,real*a.imag+imag*a.real);
    }
    void Setvalue(double r,double i) {
        real = r; imag = i;
    }
    void Output() {
        printf("%f %f\n",real,imag);
    }
}a[maxn*2],b[maxn*2];
int dp[maxn],num[maxn];
int n,len;
void Rader(Complex y[]) {
    for(int i = 1,j = len>>1;i<len-1;i++) {
        if(i<j) swap(y[i],y[j]);
        int k = len>>1;
        while(j>=k) {
            j-=k;
            k>>=1;
        }
        if(j<k) j+=k;
    }
}
void FFT(Complex y[],int op) {
    Rader(y);
    for(int h = 2;h<=len;h<<=1) {
        Complex wn(cos(2*Pi*op/h),sin(2*Pi*op/h));
        for(int i = 0;i<len;i+=h) {
            Complex w(1,0);
            for(int j = i;j<i+h/2;j++) {
                Complex u = y[j];
                Complex v = w*y[j+h/2];
                y[j] = u+v;
                y[j+h/2] = u-v;
                w  =w*wn;
            }
        }
    }
    if(op == -1) {
        for(int i = 0;i<len;i++) y[i].real /= len;
    }
}
void CDQ(int L,int R) {
    if(L == R) {
        dp[L]+=num[L];
        dp[L]%=Mod;
        return ;
    }
    int mid = (L+R)>>1;
    CDQ(L,mid);
    len = 1;
    while(len<=(r-1+1)) len<<=1;
    CLR(a,0); CLR(b,0);
    for(int i = 1;i <= mid; i++)  a[i-1].real+=dp[i];
    for(int i = 0;i <r-l+1; i++)  b[i].real += num[i+1];
    FFT(a,1);FFT(b,1);
    for(int i = 0;i<len;i++) a[i] = a[i]*b[i];
    FFT(a,-1);
    for(int i = mid+1;i<=r;i++) {
        dp[i]+=
    }
}
int main() {
    while(~scanf("%d",&n) && n) {
        CLR(dp,0);
        for(int i = 1;i<=n;i++) scanf("%d",&num[i]);
    }
    return 0;
}
