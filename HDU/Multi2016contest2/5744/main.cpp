#include <bits/stdc++.h>

using namespace std;

const int Max = 1e5+100;

int arr[Max];


int main()
{
    int n,T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        int sum = 0,num =0;

        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&arr[i]);

            if(arr[i]%2)
            {
                num++;

                sum--;
            }

            sum+=arr[i];
        }

        if(num)
        {
            printf("%d\n",(((sum)/2)/num)*2 +1);
        }
        else printf("%d\n",sum);
    }
    return 0;
}
