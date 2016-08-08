#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=110000;

int n,val[N],a[N];

int len,arr[N];

int an[N];

int lowbit(int x)
{
    return x&(-x);
}

void update(int i,int x)
{
    while(x<=len)
    {
        if(i>arr[x])
            arr[x]=i;
        x+=lowbit(x);
    }
}

int query(int x)
{
    int ans=0;
    while(x)
    {
        if(arr[x]>ans)
            ans=arr[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d",&val[i]);

            a[i]=val[i];
        }
        sort(a,a+n);

        len=unique(a,a+n)-a;

        memset(arr,0,sizeof(arr));

        int tmp;

        for(int i=0; i<n; i++)
        {
            val[i]=lower_bound(a,a+len,val[i])-a+1;

            tmp=query(val[i]-1)+1;

            update(tmp,val[i]);

            an[i] = tmp;
        }
        for(int  i = 0;i<n;i++)
        {
            if(i) printf(" ");

            printf("%d",an[i]);
        }

        printf("\n");
    }
    return 0;
}
