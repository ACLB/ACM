#include <bits/stdc++.h>

using namespace std;

int arr[110];

int n;

bool vis[110];

int main()
{
    int sum = 0;

    cin>>n;

    for(int i =0;i<n;i++)
    {
        cin>>arr[i];

        sum+=arr[i];
    }

    sum/=(n/2);

    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;

            for(int j = i+1;j<n;j++)
            {
                if(vis[j]) continue;
                if(arr[i] + arr[j] == sum)
                {
                    printf("%d %d\n",i+1,j+1);

                    vis[j] = true;

                    break;
                }
            }
        }
    }
    return 0;
}
