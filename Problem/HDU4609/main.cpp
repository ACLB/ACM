#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5+100;
const double Pi = acos(-1.0);
struct Complex {
    double real,imag;
    Complex(){}
    Complex(double _r,double _i):real(_r),imag(_i){}
    Complex operator + (const Complex &a) const {
        return Complex(real+a.real,imag+a.imag);
    }
    Complex operator -(const Complex &a) const {
        return Complex(real-a.real,imag -a.imag);
    }
    Complex operator * (const Complex &a) const {
        return Complex(real*a.real-imag*a.imag,real*a.imag+imag*a.real);
    }
    void SetValue(double r,double i) {
        real = r; imag =  i;
    }
    void Output() {
        printf("%lf %lf\n",real,imag);
    }
}a[maxn*2];
int len,n,len1;
int s[maxn];
int num[maxn];
LL sum[maxn*2];
void Get() {
    len = 1;
    while(len<(2*len1)) len<<=1;
    for(int i=0;i<len1;i++) a[i].SetValue(num[i],0);
    for(int i = len1;i<len;i++) a[i].SetValue(0,0);
}
void Readr(Complex y[]) {
    for(int i = 1,j = len>>1;i<len-1;i++) {
        if(i<j) swap(y[i],y[j]);
        int k = len>>1;
        while(j>=k) {
            j -= k;
            k>>=1;
        }
        if(j<k) j+=k;
    }
}
void FFT(Complex y[],int op) {
    Readr(y);
    for(int h  = 2;h<=len;h<<=1) {
        Complex wn(cos(2*Pi*op/h),sin(2*Pi*op/h));
        for(int i = 0;i<len;i+=h) {
            Complex w(1,0);
            for(int j = i;j<i+h/2;j++) {
                Complex u = y[j];
                Complex v = w*y[j+h/2];
                y[j] = u+v;
                y[j+h/2] = u-v;
                w = w*wn; 
            }
        }
    }
    if(op == -1) {
        for(int i = 0;i<len;i++) y[i].real/=len;
    }
}
LL Convolution() {
    FFT(a,1);
    for(int i =0;i<len;i++) a[i] = a[i]*a[i];
    FFT(a,-1);
    LL ans = 0;
    for(int i = 0;i < len;i++) sum[i] = (LL)(a[i].real+0.5);
    for(int i = 0;i < n; i++)  sum[s[i]+s[i]]--; 
    for(int i = 0;i < len;i++) sum[i]/=2;
    for(int i = 1;i < len;i++) sum[i] +=sum[i-1];
    for(int i = 0;i<n;i++) {
        ans+=sum[len-1]-sum[s[i]];
        ans-=LL(n-1-i)*i;
        ans-=(n-1);
        ans-=LL(n-1-i)*(n-2-i)/2;
    }
    return ans;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(int i = 0;i<n;i++) {
            scanf("%d",&s[i]);
            num[s[i]]++;
        }
        sort(s,s+n);
        len1 = s[n-1]+1;
        Get();
        LL p = Convolution();
        LL q = 1LL*(n)*(n-1)*(n-2)/6;
        printf("%.7f\n",p*1.0/q);
    }
    return 0;
}
