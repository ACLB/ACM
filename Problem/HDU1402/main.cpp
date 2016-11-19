#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5+100;
const double Pi = acos(-1.0);
struct Complex {
    double real,imag;
    Complex(){}
    Complex(double _r,double _i):real(_r),imag(_i){}
    Complex operator + (const Complex &a)const {
        return Complex(real+a.real,imag+a.imag);
    }
    Complex operator - (const Complex &a)const {
        return Complex(real-a.real,imag - a.imag);
    }
    Complex operator * (const Complex &a) const {
        return Complex(real*a.real-imag*a.imag,real*a.imag+imag*a.real);
    }
    void SetValue(double a,double b) {
        real = a; imag = b;
    }
    void Output() {
        printf("%f %f\n",real,imag);
    }
}a[2*maxn],b[2*maxn];
char str1[maxn],str2[maxn];
int len,len2,len1;
int res[maxn*2];
void Get(){
    len1 = strlen(str1);
    len2 = strlen(str2);
    int mlen = 2*max(len1,len2);
    len = 1; 
    while(len < mlen) len<<=1;
    for(int i = 0;i<len1;i++) a[i].SetValue(str1[len1-i-1]-'0',0);
    for(int i = 0;i<len2;i++) b[i].SetValue(str2[len2-i-1]-'0',0);
    for(int i = len1;i<len;i++) a[i].SetValue(0,0);
    for(int i = len2;i<len;i++) b[i].SetValue(0,0);   
}
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
    for(int h = 2;h<=len;h<<=1){
        Complex wn(cos(op*2*Pi/h),sin(op*2*Pi/h));
        for(int i = 0;i<len;i+=h) {
            Complex w(1,0);
            for(int j = i;j<i+h/2;j++){
                Complex u = y[j];
                Complex v = w*y[j+h/2];
                y[j] = u + v;
                y[j+h/2] = u - v;
                w = w*wn;
            }
        }
    }
    if(op == -1) {
        for(int i = 0;i<len;i++) y[i].real/=len;
    }
}
void Convolution() {
    FFT(a,1);
    FFT(b,1);
    for(int i = 0;i<len;i++) a[i] = a[i]*b[i];
    FFT(a,-1);
    for(int i = 0;i<len;i++) res[i] = (int)(a[i].real+0.5);
}
void Adopt() {
    for(int i = 0;i<len;i++) {
        res[i+1] += res[i]/10;
        res[i]%=10;
    }
    while(--len&&res[len] == 0); 
}
int main() {
    while(gets(str1) && gets(str2)){
        Get();
        Convolution();
        Adopt();
        for(int i = len;i>=0;i--) {
            putchar(res[i]+'0');
        }
        putchar('\n');
    }
    return 0;
}
