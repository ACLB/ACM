#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;

const int Bo = 400;

const int Max = 55000;

const int MaxN = 50000;

typedef struct node
{
    int L,R,Id;

    bool operator < (const node &a)const
    {
        return (L/Bo == a.L/Bo)?(R<a.R):(L/Bo<a.L/Bo);
    }
}Section;

Section S[Max];

int Tr[Max];

int a[Max];

int b[Max];

LL ans[Max];

int n,m;

int Lowbite(int x) {return x&(-x);}

void add(int x,int va)
{
    while(x<=MaxN)
    {
        Tr[x]+=va;

        x+=Lowbite(x);
    }
}

int  Qu(int x)
{
    int ans = 0;

    while(x>0)
    {
        ans+=Tr[x];

        x-=Lowbite(x);
    }

    return ans;

}

int Search(int L,int R,int s)
{
    while(L<=R)
    {
        int mid = (L+R)>>1;

        if(b[mid] == s) return mid;

        if(b[mid]<s) L = mid+1;

        else R = mid-1;
    }

    return 0;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i<=n;i++) scanf("%d",&a[i]),b[i] = a[i];

        sort(b+1,b+n+1);

        b[0] = 1;

        for(int i  = 1;i<=n;i++)
        {
            if(b[b[0]]!= b[i]) b[++b[0]] = b[i];
        }

        for(int i = 1;i<=n;i++)//离散化
        {
            a[i] = Search(1,b[0],a[i]);
        }

        scanf("%d",&m);

        for(int i  =1;i<=m;i++) scanf("%d %d",&S[i].L,&S[i].R),S[i].Id = i;

        sort(S+1,S+m+1);

        memset(Tr,0,sizeof(Tr));

        LL sum = 0;

        int l = 0 ,r =  1;

        for(int i  = 1;i<=m;i++)
        {
            while(r<=S[i].R)
            {
                sum+=Qu(MaxN)-Qu(a[r]);

                add(a[r],1);

                r++;
            }

            while(r>S[i].R+1)
            {
                r--;

                sum-=(Qu(MaxN)-Qu(a[r]));

                add(a[r],-1);
            }

            while(l<S[i].L-1)
            {
                l++;

                add(a[l],-1);

                sum-=(Qu(a[l]-1));

            }

            while(l>=S[i].L)
            {
                sum+=(Qu(a[l]-1));

                add(a[l],1);

                l--;
            }

            ans[S[i].Id] = sum;
        }


        for(int i  =1;i<=m;i++)
        {
            printf("%lld\n",ans[i]);
        }

    }
    return 0;
}
