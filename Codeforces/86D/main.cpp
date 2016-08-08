#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int BO = 1000;

const int Max = 210000;

const int MaxM = 1e6+100;

typedef struct node
{
    int L,R,Id;

    bool operator < (const node &a)const
    {
        return (L/BO == a.L/BO)?(R<a.R) : (L/BO<a.L/BO);
    }
}Section;

Section s[Max];

int a[Max];

LL num[MaxM];

LL ans[Max];

int main()
{
    int n,m;

    scanf("%d %d",&n,&m);

    for(int i = 1;i<=n;i++) scanf("%d",&a[i]);

    for(int i = 1;i<=m;i++) scanf("%d %d",&s[i].L,&s[i].R),s[i].Id = i ;

    sort(s+1,s+m+1);

    memset(num,0,sizeof(num));

    LL sum = 0;

    int l  = 0,r=  1;

    for(int i = 1;i<=m;i++)
    {
        while(r<=s[i].R)
        {
            sum+=((num[a[r]]*2+1)*a[r]);

            num[a[r]] ++;

            r++;
        }
        while(r>s[i].R+1)
        {
            r--;

            sum-=((num[a[r]]*2-1)*a[r]);

            num[a[r]]-- ;
        }

        while(l<s[i].L-1)
        {
            l++;

            sum-=((num[a[l]]*2-1)*a[l]);

            num[a[l]]-- ;
        }


        while(l>=s[i].L)
        {
            sum+=((num[a[l]]*2+1)*a[l]);

            num[a[l]]++;

            l--;
        }

        ans[s[i].Id] = sum;
    }

    for(int i = 1;i<=m;i++)
    {
        printf("%I64d\n",ans[i]);
    }
    return 0;
}
