#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#define LL long long
#define Pr pair<int,int>
#define fread(ch) freopen(ch,"r",stdin)
#define fwrite(ch) freopen(ch,"w",stdout)

using namespace std;
const LL INF = 0x3f3f3f3f;
const double eps = 1e-8;
const LL mod = 1000000007;
const LL Max = 1e5+100;

struct Node
{
    LL sum,lazy,bing;

}Tr[Max*5];

LL a[Max];

void up(LL st)
{
    if(Tr[st<<1].bing == Tr[st<<1|1].bing && Tr[st<<1].bing)
    {
        Tr[st].bing = Tr[st<<1].bing;
    }
    else Tr[st].bing = 0;

    Tr[st].sum  = Tr[st<<1].sum+Tr[st<<1|1].sum;
}

void down(LL st,LL l,LL r)
{
    LL mid = (l+r)>>1;

    if(Tr[st].bing)
    {
        Tr[st<<1|1].bing = Tr[st<<1].bing = Tr[st].bing;

        Tr[st<<1].sum=(Tr[st].bing*(mid-l+1));

        Tr[st<<1|1].sum=(Tr[st].bing*(r-mid));
    }

    if(Tr[st].lazy)
    {
        if(!Tr[st<<1].bing)
        {
            Tr[st<<1].lazy +=Tr[st].lazy;
        }
        else Tr[st<<1].bing+=Tr[st].lazy;

        if(!Tr[st<<1|1].bing)
        {
            Tr[st<<1|1].lazy += Tr[st].lazy;
        }
        else Tr[st<<1|1].bing+=Tr[st].lazy;

        Tr[st<<1|1].sum+=(Tr[st].lazy*(r-mid));

        Tr[st<<1].sum +=(Tr[st].lazy*(mid-l+1));

        Tr[st].lazy = 0;
    }
}

void Init(LL l,LL r,LL st)
{
    Tr[st].sum = 0; Tr[st].lazy = 0; Tr[st].bing = 0;

    if(l == r)
    {
        Tr[st].sum = a[l];

        Tr[st].bing= a[l];

        return ;
    }

    LL mid = (l+r)>>1;

    Init(l,mid,st<<1);

    Init(mid+1,r,st<<1|1);

    up(st);
}

void add(LL l,LL r,LL st,LL L,LL R,LL va)
{
    if(l == L&& R== r)
    {
        Tr[st].sum +=(va*(r-l+1));

        if(Tr[st].bing){

            Tr[st].bing+=va;
        }
        else Tr[st].lazy+=va;

        return ;
    }

    down(st,l,r);

    LL mid = (l+r)>>1;

    if(R<=mid) add(l,mid,st<<1,L,R,va);

    else if(L>mid) add(mid+1,r,st<<1|1,L,R,va);
    else
    {
        add(l,mid,st<<1,L,mid,va);

        add(mid+1,r,st<<1|1,mid+1,R,va);
    }

    up(st);
}

void Sqrt(LL l,LL r,LL st,LL L,LL R)
{
    if(l==L &&R == r && Tr[st].bing)
    {
        Tr[st].bing = (LL)sqrt(Tr[st].bing);

        Tr[st].sum = Tr[st].bing*(R-L+1);

        Tr[st].lazy = 0;

        return ;
    }

    down(st,l,r);

    LL mid = (l+r)>>1;

    if(R<=mid) Sqrt(l,mid,st<<1,L,R);
    else if(L>mid) Sqrt(mid+1,r,st<<1|1,L,R);
    else
    {
        Sqrt(l,mid,st<<1,L,mid);
        Sqrt(mid+1,r,st<<1|1,mid+1,R);
    }

    up(st);
}

LL Qu(LL l,LL r,LL st,LL L,LL R)
{
    if(L== l &&R == r) return Tr[st].sum;

    down(st,l,r);

    LL mid = (l+r)>>1;

    if(R<=mid) return Qu(l,mid,st<<1,L,R);

    else if(L>mid) return Qu(mid+1,r,st<<1|1,L,R);

    else
    {
        return Qu(l,mid,st<<1,L,mid)+Qu(mid+1,r,st<<1|1,mid+1,R);
    }
    up(st);
}

int main()
{
    LL T,n,m;

    LL op,l,r,va;

    scanf("%I64d",&T);

    while(T--)
    {
        scanf("%I64d %I64d",&n,&m);

        for(LL i = 1;i<=n;i++) scanf("%I64d",&a[i]);

        Init(1,n,1);

        while(m--)
        {
            scanf("%I64d",&op);

            if(op == 1)
            {
                scanf("%I64d %I64d %I64d",&l,&r,&va);

                add(1,n,1,l,r,va);
            }
            else if(op == 2)
            {
                scanf("%I64d %I64d",&l,&r);

                Sqrt(1,n,1,l,r);
            }
            else if(op == 3)
            {
                scanf("%I64d %I64d",&l,&r);

                printf("%I64d\n",Qu(1,n,1,l,r));
            }
        }
    }
    return 0;
}
