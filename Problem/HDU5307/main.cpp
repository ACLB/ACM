#include <bits/stdc++.h>
#define CLR(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
typedef long double LD;
const LD Pi = acos(-1.0);
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
LL ans[maxn*2];
void Rader(Complex y[]) {
    for(int i = 1, j = len>>1;i<len-1;i++) {
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
    for(int h =  2;h<=len;h<<=1) {
        Complex wn(cos(2*op*Pi/h),sin(2*op*Pi/h));
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
        for(int i = 1;i<=n;i++) {
            if(lent[i]==lent[i-1]) {
                int j  = i;
                for(;j<n&&lent[j+1] == lent[i];j++) ;
                ans[0] += sum[j-i+1];
               i = j; 
            }
        }
        printf("%lld\n",ans[0]);
        len = 1;
        while(len<=(2*lent[n])) len<<=1;
        CLR(a,0); CLR(b,0);
        for(int i = 1;i<=n;i++) a[lent[i]].real+=i;
        for(int i = 1;i<=n;i++) b[lent[n]-lent[i-1]].real+=1;
        FFT(a,1);FFT(b,1);
        for(int i = 0;i<len;i++) a[i] = a[i]*b[i];
        FFT(a,-1);
        for(int i = 0;i<len;i++) ans[i] = LL(a[i].real+0.5);
        CLR(a,0); CLR(b,0);
        for(int i = 1;i<=n;i++) a[lent[i]].real+=1;
        for(int i = 1;i<=n;i++) b[lent[n] - lent[i-1]].real+=(i-1);
        FFT(a,1);FFT(b,1);
        for(int i = 0;i<len;i++) a[i] = a[i]*b[i];
        FFT(a,-1);
        for(int i = 0;i<len;i++) ans[i] -= LL(a[i].real+0.5);
        for(int i = lent[n]+1;i<=lent[n]*2;i++) printf("%lld\n",ans[i]);
    }
    return 0;
}
