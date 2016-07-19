#include <iostream>

using namespace std;

typedef long long LL;

LL GCD(LL a,LL b)
{
    return b ==0?a:GCD(b,a%b);
}

int main()
{
    LL n,a,b,p,q;

    cin>>n>>a>>b>>p>>q;

    LL m = n/(a*b/GCD(a,b));

    cout<<(n/a-m)*p+(n/b-m)*q+(m*(p>q?p:q))<<endl;

    return 0;
}
