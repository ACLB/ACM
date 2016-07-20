#include <iostream>

using namespace std;

int main()
{
    int n;

    int data;

    while(cin >> n)
    {
        int ans = 0;

        for(int i = 0;i<n;i++)
        {
            cin>>data;

            ans ^= data;
        }

        if(ans) cout<<"Yes"<<endl;

        else cout<<"No"<<endl;

    }


    return 0;
}
