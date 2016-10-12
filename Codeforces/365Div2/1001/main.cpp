#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;

    cin>>n;

    int num1 = 0;

    int num2 = 0;

    for(int i =0;i<n;i++)
    {
        cin>>a>>b;

        if(a>b)
        {
            num1++;
        }
        else if(a<b) num2++;
    }

    if(num1>num2) cout<<"Mishka"<<endl;

    else if(num1<num2) cout<<"Chris"<<endl;

    else cout<<"Friendship is magic!^^"<<endl;
    return 0;
}
