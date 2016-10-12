#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#define rr() freopen("in.in","r",stdin)
#define ww() freopne("out.out","w",stdout)

using namespace std;

typedef long long LL;

const int Max = 110000;

int a[Max],rmq[Max][21];

int n,m,Bo;

LL sumL[Max],sumR[Max];

LL ans[Max];

int L[Max],R[Max];

stack<int>St;

typedef struct node
{
    int L,R,Id;

    bool operator < (const node &a)const
    {
        return (L/Bo == a.L/Bo)?R<a.R:(L/Bo<a.L/Bo);
    }
}Section;

Section S[Max];

void GetRmq()
{
    for(int i = 1;i<=n;i++) rmq[i][0] = i;

    for(int i  =1;(1<<i)<=n;i++)
        for(int j =1;j+(1<<i)-1<=n;j++)
            rmq[j][i] = a[rmq[j][i-1]]<a[rmq[j+(1<<(i-1))][i-1]]?rmq[j][i-1]:rmq[j+(1<<(i-1))][i-1];
}

int Qu(int L,int R)
{
    int k =(int)log2(R-L+1);

    return a[rmq[L][k]]<a[rmq[R-(1<<k)+1][k]] ? rmq[L][k]:rmq[R-(1<<k)+1][k];
}

LL Rcal(int l,int r)
{
    int s = Qu(l+1,r);

    return (1LL*(s-l)*a[s]+sumR[r]-sumR[s]);
}

LL Lcal(int l,int r)
{
    int s = Qu(l,r-1);

    return (1LL*(r-s)*a[s]+sumL[l]-sumL[s]);
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        for(int i = 1;i<=n;i++) scanf("%d",&a[i]);

        GetRmq(); Bo = (int)sqrt(n);
    
        for(int i = 1;i <= m; i++) scanf("%d %d",&S[i].L,&S[i].R),S[i].Id = i;
        
        sort(S+1,S+m+1);

        St.push(0);

        for(int i = 1;i <= n;i++)
        {
            while(St.size() > 1 && a[St.top()] > a[i]) St.pop();

            R[i] = St.top(); St.push(i);
        }

        while(!St.empty()) St.pop();

        St.push(n+1);

        for(int i = n;i>=1;i--)
        {
            while(St.size() > 1 && a[St.top()] > a[i]) St.pop();

            L[i] = St.top(); St.push(i);
        }

        while(!St.empty()) St.pop();

        memset(sumL,0,sizeof(sumL));

        memset(sumR,0,sizeof(sumR));

        sumR[1] =a[1];

        for(int i = 2;i<=n;i++) sumR[i] = sumR[R[i]]+(1LL)*(i-R[i])*a[i];

        sumL[n] = a[n];

        for(int i = n-1;i >= 1;i--) sumL[i] = sumL[L[i]]+(1LL)*(L[i]-i)*a[i];

        LL sum = 0;

        int l = 0,r = 1;

        for(int i = 1;i<=m;i++)
        {
            while(r <= S[i].R) sum +=Rcal(l,r),r++;

            while(r > S[i].R+1) r --,sum-=Rcal(l,r);

            while(l < S[i].L-1) l++,sum-=Lcal(l,r);
            
            while(l >= S[i].L) sum+=Lcal(l,r),l--;

            ans[S[i].Id] =sum;
        }

        for(int i = 1;i<=m;i++) printf("%lld\n",ans[i]);
    }
    return 0;
}
