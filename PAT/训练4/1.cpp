#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;

    cin>>m>>n;

    int s = m%100;

    int h = m/100;

    m = h*60+s+n;

    s = m%60;

    h = m/60;

    printf("%d%02d\n",h,s);

    return 0;
}
