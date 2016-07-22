#include <iostream>
#include <cstdio>


using namespace std;

int arr[1100];


int main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        int ans = 0;
        for(int i =0;i<n;i++)
        {
            scanf("%d",&arr[i]);

            ans ^= arr[i];
        }

        int num = 0;

        for(int i = 0;i<n;i++)
        {

            if(arr[i]>(arr[i]^ans)) num++;
        }

        printf("%d\n",num);

    }
    return 0;
}
