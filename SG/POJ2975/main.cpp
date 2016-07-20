#include <iostream>
#include <cstdio>


using namespace std;

int arr[50];

void GetBite(int s)
{
    arr[0] = 0;

    while(s)
    {
        arr[++arr[0]] = s%2;

        s>>=1;
    }
}
int main()
{
    int n,m;

    int ans = 0;

    while(~scanf("%d",&n))
    {
        ans = 0;

        for(int i = 0;i<n;i++)
        {
            scanf("%d",&m);

            ans ^= m;

            printf("%d\n",ans);


        }
        printf("%d\n",ans);

        GetBite(ans);

        int num = 0;

        for(int i = 1;i<arr[0];i++)
        {
            if(arr[i])
            {
                num ^=(1<<(i-1));
            }
        }


        printf("%d\n",(1<<(arr[0]-1))-num);
    }
    return 0;
}
