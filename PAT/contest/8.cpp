#include <iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    if(n%10!=0)
    {
        cout<<n%10;
    }
    n/=10;
     if(n%10!=0)
    {
        cout<<n%10;
    }
    n/=10;
    cout<<n%10<<endl;



    return 0;
}
