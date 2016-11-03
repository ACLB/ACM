#include <map>  
#include <set>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <cmath>  
#include <time.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <cstring>  
#include <iostream>  
#include <limits.h>  
#include <algorithm>  
  
#define LL long long  
#define ULL unsigned long long  
#define FI first  
#define SE second  
#define PB push_back  
#define MP(A, B) make_pair(A, B)  
#define sqr(x) ((x)*(x))  
#define CLR(x) x.clear()  
#define SZ(x) ((int)(x).size())  
#define ALL(x) (x).begin(),(x).end()  
#define CPY(A, B) memcpy(A, B, sizeof(A))  
#define REP(I, N) for(int I = 0; I < int(N); ++I)  
#define REP_1(I, N) for(int I = 1; I <= int(N); ++I)  
#define FOR(I, A, B) for(int I = int(A); I < int(B); ++I)  
#define DWN(I, B, A) for(int I = int(B-1); I >= int(A); --I)  
#define FOR_1(I, A, B) for(int I = int(A); I <= int(B); ++I)  
#define DWN_1(I, B, A) for(int I = int(B); I >= int(A); --I)  
  
#define max(a,b) ((a)>(b)?(a):(b))  
#define min(a,b) ((a)<(b)?(a):(b))  
#define max3(a, b, c) (a>b?max(a, c):max(b, c))  
#define min3(a, b, c) (a<b?min(a, c):min(b, c))  
#define max4(a, b, c, d) max(max(a, b), max(c, d))  
#define min4(a, b, c, d) min(min(a, b), min(c, d))  
#define Read()  freopen("data.in", "r", stdin);  
#define Write() freopen("data.out", "w", stdout);  
  
const double Pi = acos(-1.0);  
const double eps = 1e-6;  
const double Ee = 2.718281828459045235360;  
const int INF = 0x3f3f3f3f;  
const LL INFF = 0x3f3f3f3f3f3f3f3fLL;  
const int MOD = 1000000007;  
  
const int dx4[] = {-1, 0, 1,  0};  
const int dy4[] = { 0, 1, 0, -1};  
const int dx8[] = {-1, 0, 1,  0, -1, -1,  1, 1};  
const int dy8[] = {0 , 1, 0, -1, -1,  1, -1, 1};  
const int dxhorse[] = {-2, -2, -1, -1, 1,  1, 2,  2};  
const int dyhorse[] = {1 , -1,  2, -2, 2, -2, 1, -1};  
  
using namespace std;  
  
  
namespace Math {  
    typedef long long typec;  
    ///Lib functions  
    typec GCD(typec a, typec b)    {  
        return b ? GCD(b, a % b) : a;  
    }  
    typec extendGCD(typec a, typec b, typec& x, typec& y) {  
        if(!b) return x = 1, y = 0, a;  
        typec res = extendGCD(b, a % b, x, y), tmp = x;  
        x = y, y = tmp - (a / b) * y;  
        return res;  
    }  
    ///for x^k  
    typec power(typec x, typec k) {  
        typec res = 1;  
        while(k)  
        {  
            if(k&1) res *= x;  
            x *= x, k >>= 1;  
        }  
        return res;  
    }  
    ///for x^k mod m  
    typec powerMod(typec x, typec k, typec m)  
    {  
        typec res = 1;  
        while(x %= m, k)  
        {  
            if(k&1) res *= x, res %= m;  
            x *= x, k >>=1;  
        }  
        return res;  
    }  
    /*************************************** 
    Inverse in mod p^t system 
    ***************************************/  
    typec inverse(typec a, typec p, typec t = 1)  
    {  
        typec pt = power(p, t);  
        typec x, y;  
        y = extendGCD(a, pt, x, y);  
        return x < 0 ? x += pt : x;  
    }  
    /*************************************** 
    Linear congruence theorem 
    x = a (mod p) 
    x = b (mod q) 
    for gcd(p, q) = 1, 0 <= x < pq 
    ***************************************/  
    typec linearCongruence(typec a, typec b, typec p, typec q)  
    {  
        typec x, y;  
        y = extendGCD(p, q, x, y);  
        while(b < a) b += q / y;  
        x *= b - a, x = p * x + a, x %= p * q;  
        if(x < 0) x += p * q;  
        return x;  
    }  
    /*************************************** 
    prime table 
    O(n) 
    mobous[i] == -1; i is prime 
    ***************************************/  
    const int PRIMERANGE = 1000000;  
    int prime[PRIMERANGE + 1];  
    int mobius[PRIMERANGE + 1];  
    int getPrime()  
    {  
        memset (prime, 0, sizeof (int) * (PRIMERANGE + 1));  
        memset(mobius , 0 , sizeof(mobius));  
        mobius[1] = 1;  
        for (int i = 2; i <= PRIMERANGE; i++)  
        {  
            if (!prime[i]) prime[++prime[0]] = i , mobius[i] = -1;  
            for (int j = 1; j <= prime[0] && prime[j] <= PRIMERANGE / i; j++)  
            {  
                prime[prime[j]*i] = 1;  
                if (i % prime[j] == 0) break;  
                else mobius[i * prime[j]] = -mobius[i];  
            }  
        }  
        return prime[0]; ///prime's quantity;  
    }  
    /*************************************** 
    get factor of n 
    O(sqrt(n)) 
    factor[][0] is prime factor 
    factor[][1] is factor generated by this prime 
    factor[][2] is factor counter 
 
    need: Prime Table 
    ***************************************/  
    ///you should init the prime table before  
    int factor[100][3], facCnt;  
    int getFactors(int x)  
    {  
        facCnt = 0;  
        int tmp = x;  
        for(int i = 1; prime[i] <= tmp / prime[i]; i++)  
        {  
            factor[facCnt][1] = 1, factor[facCnt][2] = 0;  
            if(tmp % prime[i] == 0)  
                factor[facCnt][0] = prime[i];  
            while(tmp % prime[i] == 0)  
                factor[facCnt][2]++, factor[facCnt][1] *= prime[i], tmp /= prime[i];  
            if(factor[facCnt][1] > 1) facCnt++;  
        }  
        if(tmp != 1)  
            factor[facCnt][0] = tmp, factor[facCnt][1] = tmp, factor[facCnt++][2] = 1;  
        return facCnt;  
    }  
    ///combination  
    typec combinationModP(typec n, typec k, typec p)  
    {  
        if(k > n) return 0;  
        if(n - k < k) k = n - k;  
        typec a = 1, b = 1, x, y;  
        int pcnt = 0;  
        for(int i = 1; i <= k; i++)  
        {  
            x = n - i + 1, y = i;  
            while(x % p == 0) x /= p, pcnt++;  
            while(y % p == 0) y /= p, pcnt--;  
            x %= p, y %= p, a *= x, b *= y;  
            b %= p, a %= p;  
        }  
        if(pcnt) return 0;  
        extendGCD(b, p, x, y);  
        if(x < 0) x += p;  
        a *= x, a %= p;  
        return a;  
    }  
    ///combination mod MOD efficient  
    typec inv[100005];  
    typec ba[100005];  
    typec rba[100005];  
    void Init_Com()  
    {  
        inv[0] = inv[1] = 1;  
        ba[0] = ba[1] = 1;  
        rba[0] = rba[1] = 1;  
        for(int i = 2; i < 100005; i++) {  
            inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;  
            ba[i] = (ba[i - 1] * i)%MOD;  
            rba[i] = (rba[i - 1] * inv[i])%MOD;  
        }  
    }  
    typec C(int n, int m)  
    {  
        return (ba[n]*rba[m]%MOD)*rba[n-m]%MOD;  
    }  
    ///calculate f(0)=a,f(1)=b Fibonacci's number n item  
    int fib[1000000];  
    int Fib(int a, int b, int n)  
    {  
        if (n==0) return a;  
        if (n==1) return b;  
        return (a*fib[n-1]%MOD+b*fib[n]%MOD)%MOD;  
    }  
};  
  
namespace Geo {  
    #define typec double  
    const typec eps=1e-9;  
    int dblcmp(double d){  
        return d < -eps ? -1 : d > eps;  
    }  
    struct Point{  
        typec x,y;  
        Point(){}  
        Point(typec _x,typec _y):x(_x),y(_y){};  
        void input(){  
            scanf("%lf%lf",&x,&y);  
        }  
        void output(){  
            printf("%.2f %.2f\n",x,y);  
        }  
        bool operator==(Point a)const{  
            return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;  
        }  
        bool operator<(Point a)const{  
            return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;  
        }  
        typec len(){  
            return hypot(x,y);  
        }  
        typec len2(){  
            return x*x+y*y;  
        }  
        typec distance(Point p){  
            return hypot(x-p.x,y-p.y);  
        }  
        typec distance2(Point p){  
            return sqr(x-p.x)+sqr(y-p.y);  
        }  
        Point add(Point p){  
            return Point(x+p.x,y+p.y);  
        }  
        Point operator + (const Point & p) const{  
            return Point(x+p.x,y+p.y);  
        }  
        Point sub(Point p){  
            return Point(x-p.x,y-p.y);  
        }  
        Point operator - (const Point & p) const{  
            return Point(x-p.x,y-p.y);  
        }  
        Point mul(typec b){  
            return Point(x*b,y*b);  
        }  
        Point div(typec b){  
            return Point(x/b,y/b);  
        }  
        typec dot(Point p){  
            return x*p.x+y*p.y;  
        }  
        typec operator * (const Point & p) const{  
            return x*p.x+y*p.y;  
        }  
        typec det(Point p){  
            return x*p.y-y*p.x;  
        }  
        typec operator ^ (const Point & p) const{  
            return x*p.y-y*p.x;  
        }  
        typec rad(Point a,Point b){  
            Point p=*this;  
            return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));  
        }  
        Point trunc(typec r){  
            typec l=len();  
            if (!dblcmp(l))return *this;  
            r/=l;  
            return Point(x*r,y*r);  
        }  
        Point rotleft(){  
            return Point(-y,x);  
        }  
        Point rotright(){  
            return Point(y,-x);  
        }  
        Point rotate(Point p,typec angle){  
            Point v=this->sub(p);  
            typec c=cos(angle),s=sin(angle);  
            return Point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);  
        }  
    #undef typec  
    };  
    struct Line{  
        Point a, b;  
    };  
};  
  
namespace BigNum {  
    #define MAXN 9999  
    #define MAXSIZE 1010  
    #define DLEN 4  
  
    /// /*  
    /// 完全大数模板  
    /// 输入 cin >> a  
    /// 输出 a.print();  
    /// 注意这个输入不能自动去掉前导 0 ，可以先读到 char 数组里，去掉前导 0 ，在调用构造函数。  
    /// */  
  
    class BigInteger  
    {  
    private:  
        int a[10010];    ///可以控制大数的位数  
        int length;       ///大数长度  
    public:  
        BigInteger(){ length = 1;memset(a,0,sizeof(a)); }   ///构造函数  
        BigInteger(const int);       ///将一个int类型的变量转化为大数  
        BigInteger(const char*);     ///将一个字符串类型的变量转化为大数  
        BigInteger(const BigInteger &);  ///拷贝构造函数  
        BigInteger &operator=(const BigInteger &);   ///重载赋值运算符，大数之间进行赋值运算  
  
        friend istream& operator>>(istream&,  BigInteger&);   ///重载输入运算符  
        friend ostream& operator<<(ostream&,  BigInteger&);   ///重载输出运算符  
  
        BigInteger operator+(const BigInteger &) const;   ///重载加法运算符，两个大数之间的相加运算  
        BigInteger operator-(const BigInteger &) const;   ///重载减法运算符，两个大数之间的相减运算  
        BigInteger operator*(const BigInteger &) const;   ///重载乘法运算符，两个大数之间的相乘运算  
        BigInteger operator/(const int   &) const;    ///重载除法运算符，大数对一个整数进行相除运算  
  
        BigInteger operator^(const int  &) const;    ///大数的n次方运算  
        int operator%(const int  &) const;    ///大数对一个int类型的变量进行取模运算  
        bool operator>(const BigInteger & T)const;   ///大数和另一个大数的大小比较  
        bool operator>(const int & t)const;      ///大数和一个int类型的变量的大小比较  
  
        void print();       ///输出大数  
    } ;  
    ///将一个int类型的变量转化为大数  
    BigInteger::BigInteger(const int b) {  
        int c, d = b;  
        length = 0;  
        memset(a, 0, sizeof(a));  
        while(d > MAXN) {  
            c = d - (d / (MAXN + 1)) * (MAXN + 1);  
            d = d / (MAXN + 1);  
            a[length++] = c;  
        }  
        a[length++] = d;  
    }  
    ///将一个字符串类型的变量转化为大数  
    BigInteger::BigInteger(const char*s) {  
        memset(a, 0, sizeof(a));  
        int L = strlen(s);  
        length = L/DLEN;  
        if(L % DLEN) length++;  
        int index = 0;  
        for(int i = L-1; i >= 0; i -= DLEN) {  
            int t = 0;  
            int k = i-DLEN+1;  
            if(k < 0) k=0;  
            for(int j = k; j <= i; ++j)  
                t = t*10+s[j]-'0';  
            a[index++] = t;  
        }  
    }  
    ///拷贝构造函数  
    BigInteger::BigInteger(const BigInteger &T) : length(T.length) {  
        memset(a, 0, sizeof(a));  
        for(int i = 0; i < length; i++)  
            a[i] = T.a[i];  
    }  
    ///重载赋值运算符，大数之间进行赋值运算  
    BigInteger & BigInteger::operator =(const BigInteger &n) {  
        length = n.length;  
        memset(a, 0, sizeof(a));  
        for(int i = 0; i < length; i++)  
            a[i] = n.a[i];  
        return *this;  
    }  
    ///重载输入运算符  
    istream& operator>>(istream &in,  BigInteger &b) {  
        char ch[MAXSIZE*4];  
        in >> ch;  
        int i = -1, L = strlen(ch), count = 0, sum = 0;  
        for(i = L-1; i >= 0; ) {  
            sum = 0;  
            int t = 1;  
            for(int j = 0; j < 4 && i >= 0; j++, i--, t *= 10) {  
                sum += (ch[i]-'0')*t;  
            }  
            b.a[count] = sum;  
            count++;  
        }  
        b.length =count++;  
        return in;  
    }  
    ///重载输出运算符  
    ostream& operator <<(ostream &out,  BigInteger &b) {  
        cout << b.a[b.length - 1];  
        for(int i = b.length - 2 ; i >= 0 ; i--) {  
            cout.width(DLEN);  
            cout.fill('0');  
            cout << b.a[i];  
        }  
        return out;  
    }  
    ///两个大数之间的相加运算  
    BigInteger BigInteger::operator +(const BigInteger &T) const {  
        BigInteger t(*this);  
        int big;      ///位数  
        big = T.length > length ? T.length : length;  
        for(int i = 0; i < big; ++i) {  
            t.a[i] += T.a[i];  
            if(t.a[i] > MAXN) {  
                t.a[i + 1]++;  
                t.a[i] -= MAXN+1;  
            }  
        }  
        if(t.a[big] != 0) t.length = big + 1;  
        else t.length = big;  
        return t;  
    }  
    ///两个大数之间的相减运算  
    BigInteger BigInteger::operator -(const BigInteger &T) const {  
        int big;  
        bool flag;  
        BigInteger t1, t2;  
        if(*this > T) {  
            t1 = *this;  
            t2 = T;  
            flag = 0;  
        }  
        else {  
            t1 = T;  
            t2 = *this;  
            flag = 1;  
        }  
        big = t1.length;  
        for(int i = 0; i < big; ++i) {  
            if(t1.a[i] < t2.a[i]) {  
                int j = i + 1;  
                while(t1.a[j] == 0) j++;  
                t1.a[j--]--;  
                while(j > i) t1.a[j--] += MAXN;  
                t1.a[i] += MAXN + 1 - t2.a[i];  
            }  
            else t1.a[i] -= t2.a[i];  
        }  
        t1.length = big;  
        while(t1.a[t1.length - 1] == 0 && t1.length > 1) {  
            t1.length--;  
            big--;  
        }  
        if(flag) t1.a[big-1] = 0-t1.a[big-1];  
        return t1;  
    }  
    ///两个大数之间的相乘运算  
    BigInteger BigInteger::operator *(const BigInteger &T) const {  
        BigInteger ret;  
        int i, j, temp, temp1;  
        for(i = 0; i < length; ++i) {  
            int up = 0;  
            for(j = 0; j < T.length; ++j) {  
                temp = a[i] * T.a[j] + ret.a[i + j] + up;  
                if(temp > MAXN) {  
                    temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);  
                    up = temp / (MAXN + 1);  
                    ret.a[i + j] = temp1;  
                }  
                else {  
                    up = 0;  
                    ret.a[i + j] = temp;  
                }  
            }  
            if(up != 0) ret.a[i + j] = up;  
        }  
        ret.length = i + j;  
        while(ret.a[ret.length - 1] == 0 && ret.length > 1) ret.length--;  
        return ret;  
    }  
    ///大数对一个整数进行相除运算  
    BigInteger BigInteger::operator /(const int &b) const {  
        BigInteger ret;  
        int down = 0;  
        for(int i = length-1; i >= 0; --i) {  
            ret.a[i] = (a[i] + down * (MAXN + 1)) / b;  
            down = a[i] + down * (MAXN + 1) - ret.a[i] * b;  
        }  
        ret.length = length;  
        while(ret.a[ret.length-1] == 0 && ret.length > 1) ret.length--;  
        return ret;  
    }  
    ///大数对一个int类型的变量进行取模运算  
    int BigInteger::operator %(const int &b) const {  
        LL d = 0;  
        for(int i = length-1; i >= 0; --i) {  
            d = ((d * (MAXN+1))% b + a[i])% b;  
        }  
        return (int)d;  
    }  
    ///大数的n次方运算  
    BigInteger BigInteger::operator ^(const int &n) const {  
        BigInteger t, ret(1);  
        if(n < 0) exit(-1);  
        if(n == 0) return 1;  
        if(n == 1) return *this;  
        int m = n;  
        while(m > 1) {  
            t = *this;  
            int i;  
            for(i = 1; (i<<1) <= m; i <<= 1) {  
                t = t*t;  
            }  
            m -= i;  
            ret = ret*t;  
            if(m == 1) ret = ret*(*this);  
        }  
        return ret;  
    }  
    ///大数和另一个大数的大小比较  
    bool BigInteger::operator >(const BigInteger &T) const {  
        int ln;  
        if(length > T.length) return true;  
        else if(length == T.length) {  
            ln = length-1;  
            while(a[ln] == T.a[ln] && ln >= 0) ln--;  
            if(ln >= 0 && a[ln] > T.a[ln]) return true;  
            else return false;  
        }  
        else return false;  
    }  
    ///大数和一个int类型的变量的大小比较  
    bool BigInteger::operator >(const int &t) const {  
        BigInteger b(t);  
        return *this > b;  
    }  
    ///输出大数  
    void BigInteger::print() {  
        printf("%d", a[length-1]);  
        for(int i = length-2; i >= 0; --i) {  
            printf("%04d", a[i]);  
        }  
        puts("");  
    }  
  
};  
  
namespace IO_Optimize {  
    template<class T> inline T& RD(T &);  
    template<class T> inline T& RDD(T &);  
    inline LL RD(){LL x; return RD(x);}  
    inline LL RDD(){LL x; return RDD(x);}  
    inline double& RF(double &);  
    inline double RF(){double x; return RF(x);}  
    template<class T0, class T1> inline T0& RD(T0 &x0, T1 &x1){RD(x0), RD(x1); return x0;}  
    template<class T0, class T1, class T2> inline T0& RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2); return x0;}  
    template<class T0, class T1, class T2, class T3> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3){RD(x0), RD(x1), RD(x2), RD(x3); return x0;}  
    template<class T0, class T1, class T2, class T3, class T4> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4); return x0;}  
    template<class T0, class T1, class T2, class T3, class T4, class T5> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5); return x0;}  
    template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6); return x0;}  
    template<class T0,class T1>inline void RDD(T0&a, T1&b){RDD(a),RDD(b);}  
    template<class T0,class T1,class T2>inline void RDD(T0&a, T1&b, T2&c){RDD(a),RDD(b),RDD(c);}  
    inline double& RF(double &a, double &b){RF(a), RF(b); return a;}  
    inline double& RF(double &a, double &b, double &c){RF(a), RF(b), RF(c); return a;}  
    inline double& RF(double &a, double &b, double &c, double &d){RF(a), RF(b), RF(c), RF(d); return a;}  
    inline double& RF(double &a, double &b, double &c, double &d, double &e){RF(a), RF(b), RF(c), RF(d), RF(e); return a;}  
    inline double& RF(double &a, double &b, double &c, double &d, double &e, double &f){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f); return a;}  
    inline double& RF(double &a, double &b, double &c, double &d, double &e, double &f, double &g){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f), RF(g); return a;}  
  
    /** I/O Accelerator Interface .. **/  
    #define g (c=getchar())  
    #define d isdigit(g)  
    #define p x=x*10+c-'0'  
    #define n x=x*10+'0'-c  
    #define pp l/=10,p  
    #define nn l/=10,n  
    template<class T> inline T& RD(T &x){  
        char c;while(!d);x=c-'0';while(d)p;  
        return x;  
    }  
    template<class T> inline T& RDD(T &x){  
        char c;while(g,c!='-'&&!isdigit(c));  
        if (c=='-'){x='0'-g;while(d)n;}  
        else{x=c-'0';while(d)p;}  
        return x;  
    }  
    inline double& RF(double &x){  
        //scanf("%lf", &x);  
        char c;while(g,c!='-'&&c!='.'&&!isdigit(c));  
        if(c=='-')if(g=='.'){x=0;double l=1;while(d)nn;x*=l;}  
            else{x='0'-c;while(d)n;if(c=='.'){double l=1;while(d)nn;x*=l;}}  
        else if(c=='.'){x=0;double l=1;while(d)pp;x*=l;}  
            else{x=c-'0';while(d)p;if(c=='.'){double l=1;while(d)pp;x*=l;}}  
        return x;  
    }  
    #undef nn  
    #undef pp  
    #undef n  
    #undef p  
    #undef d  
    #undef g  
} ;  
  
using namespace Math;  
//using namespace Geo;  
//using namespace BigNum;  
//using namespace IO_Optimize;   
/*------------------------------------------------------------------*/  
char str[10010];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",str);
        int len = strlen(str);
        int ans =0;
        for(int i = 1;i<=len;i++) {
            for(int j = 2;i*j<=len;j++) {
                int st = i*j*j;
                if(st>len) break;
                else {
                    if(str[i-1] == 'y' && str[i*j-1]=='r' && str[i*j*j-1] == 'x') ans++;
                    if(str[i-1] == 'x' && str[i*j-1]=='r' && str[i*j*j-1] == 'y') ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
  
