#include <bits/stdc++.h>

using namespace std;

int arr[110];

int n,a;

int main()
{
    scanf("%d %d",&n,&a);

    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int i,j;

    int ans = arr[a];

    for(i = a-1,j = a+1;i>=1&&j<=n;i--,j++)
    {
        if(arr[i]^arr[j])  continue;

        ans+=(arr[i]+arr[j]);
    }

    while(i>=1) ans+=arr[i--];
    while(j<=n) ans+=arr[j++];

    printf("%d\n",ans);
    return 0;
}
