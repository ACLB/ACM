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
<<<<<<< HEAD
        return (l == a.l) ? (r < a.r ): (l < a.l);
=======
        return l == a.l? r > a.r:l<a.l;
>>>>>>> 0cb576ae3a1f15ec03ffe131c0c1cc7dd0222900
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
<<<<<<< HEAD
                b[num].l = max(L,arr[i]-arr[i-1]+1);

                b[num++].r = min(R,arr[i]+arr[i-1]-1);

                if(b[num-1].l>b[num-1].r) num--;
=======
                b[num].l = arr[i]-arr[i-1]+1;

                b[num++].r = arr[i]+arr[i-1]-1;
>>>>>>> 0cb576ae3a1f15ec03ffe131c0c1cc7dd0222900
            }
        }

        sort(b,b+num);

        LL ans = 0;

        LL last = b[0].r,be = b[0].l;

        for(int i = 1; i<num; i++)
        {
            if(b[i].l>last)
            {
<<<<<<< HEAD
                    ans += (last-be+1);
=======
                if(!(last < L || be > R))
                    ans += (min(R,last)-max(L,be)+1);
>>>>>>> 0cb576ae3a1f15ec03ffe131c0c1cc7dd0222900

                be = b[i].l;

                last = b[i].r;
            }
            else  last = max(last,b[i].r);
        }

        if(num)
        {
<<<<<<< HEAD
             ans += (last-be+1);
=======
            if(!(last < L || be > R))
                ans += (min(R,last)-max(L,be)+1);
>>>>>>> 0cb576ae3a1f15ec03ffe131c0c1cc7dd0222900
        }

        printf("%I64d\n",R-L+1-ans);

    }

    return 0;
}
