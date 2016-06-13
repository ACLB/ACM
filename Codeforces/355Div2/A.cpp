#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,h,data;

    int sum = 0;

    scanf("%d %d",&n,&h);

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&data);

        sum+=(data>h?2:1);
    }

    printf("%d\n",sum);

    return 0;
}
