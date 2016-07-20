#include <bits/stdc++.h>

using namespace std;

const int Max = 1e6;

int Tr[Max*5];

int a[Max];

int n;

void Build(int L,int R,int st)
{
    if(L==R) Tr[st] = a[L];

    else 
    {
        int mid = (L+R) >>1;
        Build(L,mid,st<<1);

        Build(mid+1,R,st<<1|1);

        Tr[st] = min(Tr[st<<1],Tr[st<<1|1]);
    }
}

void PushUp(int st)
{

    Tr[st] = min(Tr[st<<1],Tr[st<<1|1]);
}

void Update(int L,int R,int st,int index,int value)
{
    if(L == R)
    {
        Tr[st] = value;

        return ;
    }

    int mid = (L+R)>>1;

    if(index <= mid) Update(L,mid,st<<1,index,value);
    
    else Update(mid+1,R,st<<1|1,index,value);

    PushUp(st);
}


int Query(int L,int R,int st,int l,int r)
{
    if(L == l && R == r) return Tr[st];

    int mid = (L+R)>>1;

    if(r<=mid) return Query(L,mid,st<<1,l,r);

    else if(l>mid) return Query(mid+1,R,st<<1|1,l,r);


    else return min(Query(L,mid,st<<1,l,mid),Query(mid+1,R,st<<1|1,mid+1,r));
}

int op,l,r;

int main()
{
    scanf("%d",&n);

    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    Build(1,n,1);

    int Q;

    scanf("%d",&Q);

    while(Q--)
    {
        scanf("%d %d %d",&op,&l,&r);

        if(op)
        {
            Update(1,n,1,l,r);
        }
        else
        {
            printf("%d\n",Query(1,n,1,l,r));
        }
    }

    return 0;
}
