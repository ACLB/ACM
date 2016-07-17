
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    int data;

    priority_queue<int, vector<int> ,greater<int> >Q;

    cin>>n;

    for(int  i =0;i<n;i++)
    {
        cin>>data;

        Q.push(data);
    }
    int ans = 0;
    while(Q.size()>1)
    {
        int u  =  Q.top();

        Q.pop();

        int v = Q.top(); Q.pop();

       

        ans+=(u+v);
        Q.push(u+v);
    }

    cout<<ans<<endl;
    return 0;
}
