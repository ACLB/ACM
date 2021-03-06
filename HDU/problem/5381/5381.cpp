#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Bo = 200;

const int Max = 1e4+100;

typedef struct node
{
    int L,R,Id;

    bool operator < (const node &a)const
    {
        return (L/Bo == a.L/Bo)?(R<a.R):(L/Bo<a.L/Bo);
    }
}Section;

Section S[Max];

int n,m;

int rmq[Max][15];

int a[Max];

LL ans[Max];


vector<pair<int,int> >VL[Max];

vector<pair<int,int> >VR[Max];

int GCD(int a,int b)
{
    return b == 0 ?a:GCD(b,a%b);
}

void GetRmq()
{
    for(int i = 1;i<=n;i++)
        rmq[i][0] = a[i];

    for(int  i = 1;(1<<i)<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(j+(1<<i)-1<=n)
            {
                rmq[j][i] =GCD(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
            }
        }
    }

}

int Qu(int l,int r)
{
    int k = (int)log2(r-l+1);

    return GCD(rmq[l][k],rmq[r-(1<<k)+1][k]);
}

int RSearch(int s,int L,int R,int t)
{
    int ans ;

    while(L<=R)
    {
        int mid = (L+R)>>1;

        if(Qu(mid,s) == t)
        {
            ans = mid;
            R = mid-1;
        }
        else L = mid+1;
    }
    return ans;
}

int LSearch(int s,int L,int R,int t)
{
    int ans ;

    while(L<=R)
    {
        int mid = (L+R)>>1;

        if(Qu(s,mid) == t)
        {
            ans = mid;
            L = mid+1;
        }
        else R= mid-1;
    }
    return ans;
}

LL Rcal(int s,int t)
{
    LL ans = 0;

    int ss = s;

    for(int i = 0;i<VR[s].size();i++)
    {
        
        ans +=(1LL*(ss-max(t,VR[s][i].second)+1)*VR[s][i].first);
        
        ss = VR[s][i].second-1;

        if(ss<t) break;
    }

    return ans;
}

LL Lcal(int s,int t)
{
    LL ans = 0;

    int ss = s;

    for(int i = 0;i<VL[s].size();i++)
    {
        
        ans+=(1LL*(min(t,VL[s][i].second)-ss+1)*VL[s][i].first);

        ss = VL[s][i].second+1;

        if(ss>t) break;
    }

    return ans;
}

int main()
{
    int T;

    freopen("in.in","r",stdin); 
    
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(int i = 1;i<=n;i++) scanf("%d",&a[i]);

        GetRmq();

        for(int i = 1;i<=n;i++)
        {
            int r = i;

            VL[i].clear();

            while(r<=n)
            {
                int ant = Qu(i,r);

                r = LSearch(i,r,n,ant);

                VL[i].push_back(make_pair(ant,r));

                r++;
            }
        }

        for(int i =n;i>=1;i--)
        {
            int l = i;

            VR[i].clear();

            while(l>=1)
            {
                int ant = Qu(l,i);

                l = RSearch(i,1,l,ant);

                VR[i].push_back(make_pair(ant,l));

                l--;
            }
        }
        
        scanf("%d",&m);
        
        for(int i = 1;i<=m;i++) scanf("%d %d",&S[i].L,&S[i].R) , S[i].Id = i;

        sort(S+1,S+m+1);

        LL sum = 0;

        int l = 0,r = 1;

        for(int i = 1;i<=m;i++)
        {

            while(r<=S[i].R) 
            {
                sum+=Rcal(r,l+1);

                r++;
            }

            while(r>S[i].R +1)
            {

                r --;

                sum-=Rcal(r,l+1);
            }

            while(l<S[i].L-1)
            {
                l++;

                sum-=Lcal(l,r-1);
            }

            while(l>=S[i].L)
            {
                sum+=Lcal(l,r-1);

                l--;
            }

            ans[S[i].Id] = sum;
        }

        for(int i = 1;i<=m;i++) printf("%I64d\n",ans[i]);
  }
    return 0;
}
