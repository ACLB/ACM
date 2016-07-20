#include <bits/stdc++.h>

using namespace std;

int n,m;

string s;

int main()
{
    cin>>n>>m;

    while(n--)
    {
        cin>>s;

        int ant = 0;

        for(int i =0 ;i<s.size();i++)
        {
            if(s[i] == 'S') ant++;

            else ant --;

            if(ant<0 || ant>m) break;
        }

        if(ant == 0)
        {
            cout<<"YES"<<endl;

        }
        else cout<<"NO"<<endl;

    }
    return 0;
}
