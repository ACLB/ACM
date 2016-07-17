#include <bits/stdc++.h>

using namespace std;

int a[55];

int main()
{
    int n,y;

    cin>>n;

    for(int i = 0;i<n;i++)
    {
        cin>>y;

        a[y]++;
    }

    for(int i = 0 ;i<=50;i++)
    {
        if(a[i])
        {
            cout<<i<<":"<<a[i]<<endl;
        }
    }
    return 0;
}
