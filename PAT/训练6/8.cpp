#include <bits/stdc++.h>

using namespace std;

int a[1100];

int main()
{
    int n,m;

    cin>>n>>m;

    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];

        int s = i;
        
        while(s!=1)
        {
            if(a[s]<a[s/2])
            {
                swap(a[s],a[s/2]);
            }
            s/=2;
        }
    }

    int s;

    for(int i = 1;i<=m;i++)
    {
        cin>>s;

        bool flag =false;
        while(s!=0)
        {
            if(flag) cout<<" ";

            else flag = true;

            cout<<a[s];

            s/=2;
        }

        cout<<endl;
    }
    return 0;
}
