#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
    string name,ri,tel;

    bool operator < (const node &a)const
    {
        return ri<a.ri;
    }
}No;

No a[15];

int main()
{
    int n;

    cin>>n;

    for(int i =0 ;i<n;i++)
    {
        cin>>a[i].name>>a[i].ri>>a[i].tel;
    }

    sort(a,a+n);

    for(int i = 0;i<n;i++)
    {
        cout<<a[i].name<<" "<<a[i].ri<<" "<<a[i].tel<<endl;
    }
    return 0;
}
