#include <bits/stdc++.h>
#define rr() freopen("in.in","r",stdin)
#define ww() freopen("out.out","w",stdout)

using namespace std;

typedef long long LL;

const int Max=  1<<22;

int num[Max],Bo;

int pre[100100];

typedef struct node
{
    int L,R,Id;

    bool operator < (const node &a)const
    {
        return (L/Bo == a.L/Bo)?R<a.R:(L/Bo<a.L/Bo);
    }
}Section;

Section S[100100];

LL ans[100100];

int main()
{
    int n,data,m,k;

    //rr();

    scanf("%d %d %d",&n,&m,&k);

    Bo = (int)sqrt(n);

    pre[0] = 0;

    for(int i =1;i<=n;i++)
    {
        scanf("%d",&data);

        pre[i] = pre[i-1]^data;
    }

    for(int i = 1;i<=m;i++)
    {
        scanf("%d %d",&S[i].L,&S[i].R);

        S[i].Id = i;
    }

    sort(S+1,S+m+1);

    LL sum = 0;

    int l = 0,r = 0;

    memset(num,0,sizeof(num));

    for(int i = 1;i<=m;i++)
    {
        while(r<=S[i].R)
        {
            sum+=num[pre[r]^k];
            
            num[pre[r]]++;

            r++;
        }

        while(r>S[i].R+1)
        {
            r--;

            --num[pre[r]];
           
            sum-=num[pre[r]^k];

        }
        while(l<S[i].L-1)
        {

            --num[pre[l]];
            
            sum-=num[pre[l]^k];
            
            l++;

        }

        while(l>=S[i].L)
        {
            l--;
            
            sum+=num[pre[l]^k];

            num[pre[l]]++;

        }
        ans[S[i].Id] = sum;
    }

    for(int i = 1;i<=m;i++) printf("%I64d\n",ans[i]);
    return 0;
}
