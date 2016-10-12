#include <bits/stdc++.h>

using namespace std;

const int Max = 3500;

int num[Max];

void Get()
{
    memset(num,0,sizeof(num));

    for(int i = 1;i<Max;i++)
    {
        for(int j = i+1;j<Max;j++)
        {
            int ans = i*i+j*j;

            int ant = (int)sqrt(ans);

            if(ans == ant*ant && i+j+ant<Max) num[i+j+ant] =  max(ant*i*j,num[i+j+ant]);

            if(i+j+ant>=Max) break;
        }
    }
}

int main()
{
    Get();

    int T,n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        printf("%d\n",num[n]==0?-1:num[n]);
    }
    return 0;
}
