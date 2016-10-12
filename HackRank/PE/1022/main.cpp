#include <bits/stdc++.h>

using namespace std;

const int Max = 5300;

string str[Max];

string c;

int main()
{
    int n,m;

    cin>>n;

    for(int i =0;i<n;i++)
    {
       cin>>str[i];
    }

    sort(str,str+n);

    cin>>m;

    while(m--)
    {
        cin>>c;

        int ans = lower_bound(str,str+n,c)-str+1;

        int sum = 0;

        for(int i = 0;i<c.size();i++) sum+=(c[i]-'A'+1);

        printf("%d\n",ans*sum);
    }
    return 0;
}
