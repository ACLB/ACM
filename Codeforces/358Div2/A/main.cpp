#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n,m;

int main()
{
    cin>>n>>m;

    LL sum = 0;

    sum = (n/5)*(m/5);

    for(int i = 1;i <= 4 && i <=  n ;i++)
    {
        if( m < 5-i) continue;
        sum+=((n-i)/5+1)*((m-5+i)/5+1);
    }

    cout<<sum<<endl;

    return 0;
}
