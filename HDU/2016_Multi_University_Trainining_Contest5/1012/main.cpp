#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Max = 55000;

int a[Max],b[Max];

LL Tr[Max];

LL lu[Max],ld[Max],ru[Max],rd[Max];

int num[Max];

int n,m;

int sum[Max];

int Lowbite(int x)
{
    return x&(-x);
}

void Up(int x)
{
    while(x<=m)
    {
        Tr[x]++;

        x+=Lowbite(x);
    }
}

LL Qy(int x)
{
    LL ans =0;

    while(x>0)
    {
        ans+=Tr[x];

        x-=Lowbite(x);
    }

    return ans;
}

LL Sum(LL *st,int l,int r)
{
    LL ans =0;

    for(int i = l;i<=r;i++) ans+=st[i];

    return ans;
}

void Out(LL *st,int l,int r)
{
    for(int i = l;i<=r;i++)
    {
        if(i!=l) printf(" ");

        printf("%lld",st[i]);
    }
    printf("\n");
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&a[i]);

            b[i] =a[i];
        }

        sort(a,a+n);

        m = 0;

        for(int i = 1;i<n;i++) if(a[m]!= a[i]) a[++m] =a[i];

        m++;

        for(int i = 1;i<=n;i++) num[i] = lower_bound(a,a+m,b[i-1])-a+1;

        memset(Tr,0,sizeof(Tr));

        memset(sum,0,sizeof(sum));

        for(int i = 1;i<=n;i++)
        {
            ru[i] = Qy(num[i]-1);

            rd[i] = (i-1-ru[i]-sum[num[i]]);

            Up(num[i]);

            sum[num[i]] ++;
        }

        memset(Tr,0,sizeof(Tr));

        memset(sum,0,sizeof(sum));

        for(int i = n;i>=1;i--)
        {
            lu[i] = Qy(num[i]-1);

            ld[i] = (n-i-lu[i]-sum[num[i]]);

            Up(num[i]);

            sum[num[i]]++;
        }

        LL ans =Sum(ru,1,n)*Sum(lu,1,n);


        for(int i = 1;i<=n;i++)
        {
            ans -=(ru[i]*rd[i]+lu[i]*ld[i]+ru[i]*lu[i]+rd[i]*ld[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
