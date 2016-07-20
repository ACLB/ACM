
#include <bits/stdc++.h>

using namespace std;

int n;

int a[12];

int main()
{
    cin>>n;

    for(int i = 0;i<=n;i++) cin>>a[i];

    sort(a,a+n+1);
    for(int i = 0;i<=n;i++)
    {

        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
