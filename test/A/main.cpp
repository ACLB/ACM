#include <bits/stdc++.h>

using namespace std;

int a[50],b[50];

long long Pow(int k)
{
    long long ans =1;

    for(int i = 1; i<=k; i++) ans*=2;

    return ans-2;
}

void GetBit(long long u,long long v)
{
    a[0] = 0;
    b[0]= 0 ;

    while(u)
    {
        a[++a[0]] = u%2;

        u>>=1;
    }

    while(v)
    {
        b[++b[0]] = v%2;

        v>>=1;
    }
}

int GetBitSize(long long u)
{
    int ans = 0;

    while(u)
    {
        u>>=1;

        ans++;
    }

    return ans;

}

bool Judge(long long u,long long v)
{
    GetBit(u,v);

    cout<<u<<" "<<v<<endl;

    cout<<a[0]<<" Size "<<b[0]<<endl;

    for(int i =a[0],j = b[0]; i>=1; i--, j--)
    {
        cout<<a[i]<<" == "<<b[j]<<endl;

        if(a[i] != b[j]) return true;
    }

    return false;

}

long long cal(int k,long long u)
{

    int ans = 1;

    for(int i = GetBitSize(u); i <= k; i++) ans *= 2;

    return ans-1;
}
int k,n;

vector<long long> table;

int main()
{
    cin>>k>>n;

    long long data;

    for(int i = 0;i<n;i++)
    {

        cin>>data;

        table.push_back(data);
    }

    long long n = Pow(k);

    long long ans = 0;

    sort(table.begin(),table.end());

    table.erase(unique(table.begin(),table.end()),table.end());

    int m = table.size();

    for(int i = 0; i < m; i++)
    {
        bool flag = false;

        for(int j = 0; j < i; j++)
        {
            if(!Judge(table[j],table[i]))
            {

                flag = true;

                break;
            }
        }

        if(!flag) ans+=cal(k,table[i]);

    }

    cout<<n - ans<<endl;;

}
