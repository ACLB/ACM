#include <bits/stdc++.h>

using namespace std;

int a[1100];

int main()
{
    int n,m;

    cin>>n;

    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>m;

        for(int j = 1;j<=n;j++)
        {
            if(a[j]+m<=100)
            {
                a[j]+=m;

                cout<<m<<" "<<j<<endl;

                ans = max(ans,j);
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
