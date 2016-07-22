#include <bits/stdc++.h>

using namespace std;

int arr[110];

int main()
{
    int n,m;

    int T;
    scanf("%d",&T);

    while(T--)
    {
        memset(arr,0,sizeof(arr));

        scanf("%d %d",&n,&m);

        int index;
        for(int i = 1;i<=m;i++)
        {
            scanf("%d",&index);

            scanf("%d",&arr[index]);
        }

        if(!arr[1]) arr[1] = 100;

        if(!arr[2]) arr[2] = arr[1];

        int  k = arr[1]+arr[2];

        int s = 0;

        int st = 0;
        for(int i = n;i>=3;i--)
        {
            if(arr[i])
            {
               st = arr[i];
            }
            else arr[i] = st;

            s+=arr[i];
        }

        int g = __gcd(k,(k+s));

        printf("%d/%d\n",k/g,(k+s)/g);
    }
    return 0;
}
