#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

const int Max = 110000;

int Tr[Max*8];

int arr[Max];

int n;

map<int,long long >M;

int GCD(int a,int b)
{
    return b == 0?a:GCD(b,a%b);
}

void PushUp(int st)
{
    Tr[st] = GCD(Tr[st<<1],Tr[st<<1|1]);
}

void Build(int L,int R,int st)
{
    if(L == R)
    {
        Tr[st] = arr[L];

        return ;
    }

    int mid = (L+R)>>1;

    Build(L,mid,st<<1);

    Build(mid+1,R,st<<1|1);

    PushUp(st);
}

int Query(int L,int R,int st,int l,int r)
{
    if(L == l && R == r) return Tr[st];

    int mid = (L+R)>>1;

    if(r<=mid) return Query(L,mid,st<<1,l,r);
    else if(l>mid) return Query(mid+1,R,st<<1|1,l,r);
    else return GCD(Query(L,mid,st<<1,l,mid),Query(mid+1,R,st<<1|1,mid+1,r));
}

void Op(int s)
{
    int r =s;

    int g;

    while(r<=n)
    {
        g = Query(1,n,1,s,r);

        int L = r,R = n;

        while(L<R)
        {

            int mid = (L+R+1)>>1;

            if(Query(1,n,1,s,mid) == g)
            {
                L = mid;
            }
            else R = mid-1;
        }
        M[g]+=(L-r+1);

        r = L+1;

    }
}

int main()
{


    int T;

    int z = 1;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(int i = 1;i<=n;i++) scanf("%d",&arr[i]);

        Build(1,n,1);

        M.clear();

        for(int i = 1;i<=n;i++)
        {
            Op(i);
        }

        int m;

        scanf("%d",&m);

        int l,r;
        printf("Case #%d:\n",z++);

        while(m--)
        {
            scanf("%d %d",&l,&r);

            int g = Query(1,n,1,l,r);

            printf("%d %lld\n",g,M[g]);
        }
    }
    return 0;
}
