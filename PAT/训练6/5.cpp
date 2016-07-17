#include <bits/stdc++.h>

using namespace std;

int a;

int main()
{

    int n;

    cin>>n;

    int sum = 0;

    for(int i = 0;i<n;i++)
    {
        for(int j =0 ;j<n;j++)
        {
            cin>>a;
            if(i == n-1 || j== n-1 || i+j == n-1) continue;

            sum+=a;

        }
    }
    cout<<sum<<endl;
    return 0;
}
