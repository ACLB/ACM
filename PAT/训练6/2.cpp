#include <bits/stdc++.h>

using namespace std;

int a[10];

int GetNum(int u,int st)
{
    int s = 1;
    for(int i = 0;i<3;i++)
    {
        a[i] = (u/s)%10; s*=10;
    }

    sort(a,a+3);

    int n1 = 0,n2 = 0;
    for(int i = 2;i>=0;i--)
    {
        n1 = n1*10+a[i];
    }

    for(int i = 0;i<3;i++)
    {
        n2 = n2*10+a[i];
    }

    cout<<st<<": "<<n1<<" - "<<n2<<" = "<<n1-n2<<endl;

    return n1-n2;
}

int main()
{
    int n;

    cin>>n;

    int num = 1;
    while(1)
    {
        n = GetNum(n,num++);

        if(n == 0|| n== 495) break;
    }

    return 0;
}

