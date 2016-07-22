#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL Mod = 1e9+7;

struct Matrix
{
    int n,m;

    LL a[10][10];

    void Clear()
    {
        n = m = 0;

        memset(a,0,sizeof(a));
    }

    Matrix operator * (const Matrix &b) const
    {
        Matrix temp; temp.Clear();

        temp.n = n ,temp.m = b.m;

        for(int i =0 ;i<n;i++)
        {
            for(int j = 0;j<b.m;j++)
            {
                for(int k = 0;k<m;k++)
                {
                    temp.a[i][j] = (temp.a[i][j] +a[i][k]*b.a[k][j])%Mod;
                }
            }
        }

        return temp;
    }

};


int main()
{
    LL a,b,n,x;

    cin>>a>>b>>n>>x;

    Matrix s ,t;

    s.Clear(); t.Clear();

    s.n = 2;s.m = 1;

    s.a[0][0] = x; s.a[1][0] = 1;

    t.n = t.m = 2;

    t.a[0][0] = a; t.a[0][1] = b;

    t.a[1][1] = 1;

    while(n)
    {
        if(n%2)
        {
            s = t*s;
        }

        t = t*t;

        n>>=1;
    }

    cout<<s.a[0][0]<<endl;

    return 0;
}
