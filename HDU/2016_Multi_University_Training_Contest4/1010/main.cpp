#include <bits/stdc++.h>

using namespace std;

const int Max =101000;

int dp[Max*2];

int Find(int x,int l,int r)
{
    while(l<=r)
    {
        int mid = (l+r)>>1;

        if(dp[mid] == x) return mid;

        if(dp[mid]<x)
            l = mid+1;
        else r =mid-1;
    }

    return l;
}

int main()
{
    int T,n,x;

    scanf("%d",&T);

    for(int z = 1;z<=T;z++)
    {
        scanf("%d",&n);

        int num = 0;

        int l  = Max,r = Max;

        for(int i  =0;i<n;i++)
        {
            scanf("%d",&x);

            if(!x)
            {
                num++;

                dp[--l] = -num;
            }

            x-=num;

            int st = Find(x,l,r-1);

            if(st == r)
            {
                dp[r++] = x;
            }
            else dp[st] = min(dp[st],x);
        }

        printf("Case #%d: %d\n",z,r-l);
    }
    return 0;
}
