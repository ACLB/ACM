#include <bits/stdc++.h>

using namespace std;

int n,num;

int a[50];

void dfs(int u,int m,int op)
{
    if(m ==0 )
    {
        for(int i = 0;i<op;i++)
        {
            if(i)
            {
                cout<<"+"<<a[i];
            }
            else cout<<n<<"="<<a[i];
        }

        if(num%4 == 3 || op == 1)
            cout<<endl;
        else cout<<";";
        num++;
        return ;
    }

    for(int i = u;i<=m;i++)
    {
        a[op] = i;

        dfs(i,m-i,op+1);
    }


}

int main()
{
    cin>>n;

    dfs(1,n,0);

    return 0;
}

