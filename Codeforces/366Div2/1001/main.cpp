#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    int n;

    cin>> n;

    for(int i = 1;i<=n;i++)
    {
        if(i!=1) cout<<" that ";

        if(i%2) cout<<"I hate";

        else cout<<"I love";
    }

    cout<<" it"<<endl;
    return 0;
}

