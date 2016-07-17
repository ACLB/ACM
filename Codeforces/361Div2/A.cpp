#include <bits/stdc++.h>


using namespace std;

int n;

char s[11];

int a[11];

int main()
{

    cin >>n;

    cin>>s;

    for(int i =0;i<n;i++)
    {
        a[i] = a[i]-'0';

        if(!a[i]) a[i] = 11;
    }

    for(int i = -9;i<=9;i+=3)
    {
        bool flag = false;
        for(int j = 0;j<n;j++)
        {
            if(a[j]- i<=0)
            {
                flag = true;

                break;
            }
        }

        if(!flag)
        {
            cout<<"NO"<<endl;

            return 0;
        }

    }

    cout<<"YES"<<endl;
    
    return 0;
}
