#include <bits/stdc++.h>

using namespace std;

int h[50],z[50];

queue<int>Q;

void Build(int L1,int R1,int L2,int R2)
{
    if(L1>R1 || L2>R2) return ;

    int i;

    for(i = L1;i<=R1;i++)
    {
        if(z[i] == h[R2]) break;
    }

    Q.push(h[R2]);

    Build(L1,i-1,L2,L2+i-L1-1);

    Build(i+1,R1,L2+i-L1,R2-1);
}

int main()
{
    int n;
 
    cin>>n;

    for(int i =0 ;i<n;i++)
    {
        cin>>h[i];
    }

    for(int i = 0 ;i<n;i++)
    {
        cin>>z[i];
    }

    int i;

    for(i = 0;i<n;i++)
    {
        if( z[i] == h[n-1])
        {
            break;
        }
    }

    Q.push(h[n-1]);

    Build(0,i-1,0,i-1);

    Build(i+1,n-1,i,n-2);

    
    bool flag = false;


    cout<<"Preorder: ";

    while(!Q.empty())
    {
        if(flag) cout<<" ";
        else flag = true;

        cout<<Q.front();

        Q.pop();
    }

    cout<<endl;

    return 0;
}
