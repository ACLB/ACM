#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,l;

    string s;

    cin>>n;

    bool flag = false;

    for(int i = 0;i<n;i++)
    {
        cin>>s>>a>>l;

        if(a>=2400 && l>a)
        {
            flag = true;

            break;
        }
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
