#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Max  = 20;

typedef long long LL;

LL X[Max],Y[Max],n;

bool vis[Max];

void ExGcd(LL a,LL b,LL &x,LL &y)
{
    if(b == 0)
    {
        x = 1;

        y = 0;
    }
    else
    {
        ExGcd(b,a%b,y,x);

        y -= a/b*x;

    }
}

LL CRT(LL r,LL l)
{
    LL M = 1;

    for(int i = 0;i<=n;i++)
    {
        if(!vis[i]) continue;

        M *= X[i];
    }

    LL an =  0;

    LL x,y;

    for(int i = 0;i<=n;i++)
    {
        if(!vis[i]) continue;

        LL ant = M/X[i];

        ExGcd(ant,X[i],x,y);

        x = (x%X[i]+X[i])%X[i];

        an = (an +(((Y[i]*ant)%M)*x)%M+M)%M;
    }
    return (r+M-an)/M-(l-1+M-an)/M;
}

LL x,y;

int main()
{
    int T,z  = 1;

    cin>>T;

    while(T--)
    {
        cin>>n>>x>>y;

        LL num =0;

        for(int i = 0;i<n;i++)
        {
            cin>>X[i]>>Y[i];
        }

        X[n] = 7;

        Y[n] = 0;

        for(int i = 0;i<(1<<n);i++)
        {
            memset(vis,false,sizeof(vis));

            int st = 0;

            for(int j = 0;j<n;j++)
            {
                if(((1<<j)&i))
                {
                    st ++;
                    vis[j] = true;
                }
            }

            vis[n] = true;

            if(st%2)
            {
                num-=CRT(y,x);
            }
            else num+=CRT(y,x);
        }

        cout<<"Case #"<<z++<<": "<<num<<endl;

    }
    return 0;
}
