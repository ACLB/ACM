#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

const int Max = 1e5+100;

typedef long long LL;

LL L,R;

int n;

LL arr[Max];

struct node
{
    LL l,r;

    bool operator < (const node &a)const
    {
        return l == a.l? r > a.r:l<a.l;
    }

} b[Max];

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %I64d %I64d",&n,&L,&R);

        for(int i = 0; i<n; i++)
        {
            scanf("%I64d",&arr[i]);
        }

        sort(arr,arr+n);

        int num = 0;

        for(int i = 0; i<n; i++)
        {
            if(i)
            {
                b[num].l = arr[i]-arr[i-1]+1;

                b[num++].r = arr[i]+arr[i-1]-1;
            }
        }

        sort(b,b+num);

        LL ans = 0;

        LL last = b[0].r,be = b[0].l;

        for(int i = 1; i<num; i++)
        {
            if(b[i].l>last)
            {
                if(!(last < L || be > R))
                    ans += (min(R,last)-max(L,be)+1);

                be = b[i].l;

                last = b[i].r;
            }
            else  last = max(last,b[i].r);
        }

        if(num)
        {
            if(!(last < L || be > R))
                ans += (min(R,last)-max(L,be)+1);
        }

        printf("%I64d\n",R-L+1-ans);

    }

    return 0;
}
