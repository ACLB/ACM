#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; bool flag = false;

    cin>>n;

    for(int i = 0;i*1234567<=n;i++)
    {
        for(int j = 0;j*123456<=n-i*1234567;j++)
        {
            if((n - i*1234567 - j*123456)%1234 == 0)
            {
                flag= true;

                break;
            }
        }
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
