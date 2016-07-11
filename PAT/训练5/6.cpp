#include <bits/stdc++.h>

using namespace std;

int a[15][15];

int main()
{
    int n,num;

    cin>>n;

    num =  1;

    int l = 1;
    while(num<=n*n)
    {
        for(int i = l;i<=n-l+1;i++)
        {
            a[l][i] = num++;
        }

        for(int i = l+1;i<=n-l+1;i++)
        {
            a[i][n-l+1] = num++;
        }

        for(int i = n-l;i>=l;i--)
        {
            a[n-l+1][i] = num++;
        }

        for(int i = n-l;i>=l+1;i--)
        {
            a[i][l] = num++;
        }

        l++;

    }

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            printf("% 3d",a[i][j]);
        }

        cout<<endl;
    }
    return 0;
}
