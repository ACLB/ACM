#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int Max = 1e5+100;

map<int,vector<int > >mp;

vector<pair<int ,pair<int ,int > > > E[Max];

int n,x;

struct node
{
    int lazy;

    int ci;

    int sum;

}Tr[Max*5];

void PushUp(int st)
{
    Tr[st].sum = Tr[st<<1].sum + Tr[st<<1|1].sum;
}

void PushDown(int st,int L,int R)
{
    if(Tr[st].lazy)
    {
        int mid = (L+R)>>1;
        
        Tr[st<<1].lazy = Tr[st].lazy;

        Tr[st<<1].ci += Tr[st].lazy;

        Tr[st<<1].sum = (mid-L+1) *(Tr[st<<1].ci >0?1:0);

        Tr[st<<1|1].lazy = Tr[st].lazy;

        Tr[st<<1|1].ci += Tr[st].lazy;

        Tr[st<<1|1].sum = (R-mid) *(Tr[st<<1|1].ci >0?1:0);
        
        Tr[st].lazy = 0;
    }
}

void Build(int L,int R,int st)
{
    Tr[st].lazy = Tr[st].ci = Tr[st].sum = 0;

    if(L == R) return ;

    int mid = (L+R) >> 1;

    Build(L,mid,st<<1);

    Build(mid+1,R,st<<1|1);

    PushUp(st);
}

void Up(int L,int R,int st,int l,int r,int value)
{
    if(l>=L && r<=R)
    {
        Tr[st].lazy = value;

        Tr[st].ci += value;
        
        Tr[st].sum = (R-L+1)*(Tr[st].ci>0?1:0);

        return ;
    }

    PushDown(st,L,R);

    int mid = (L+R)>>1;

    if(r<=mid) Up(L,mid,st<<1,l,r,value);

    else if(l>mid) Up(mid+1,R,st<<1,l,r,value);

    else
    {
        Up(L,mid,st<<1,l,mid,value);

        Up(mid+1,R,st<<1|1,mid+1,r,value);
    }

    PushUp(st);
 
}


int Query(int L,int R,int st,int l,int r)
{
    if(L == l && r == R) return Tr[st].sum;

    int mid = (L+R)>>1;

    if(r<=mid)
    {
        return Query(L,mid,st<<1,l,r);
    }
    else if(l>mid)
    {
        return Query(mid+1,R,st<<1|1,l,r);
    }
    else return Query(L,mid,st<<1,l,mid)+Query(mid+1,R,st<<1|1,mid+1,r);

}
int main()
{
    int T,data;

    scanf("%d",&T);

    while(T--)
    {
        mp.clear();
        
        scanf("%d %d",&n,&x);
        
        for(int i = 0;i <=n ;i++) E[i].clear();

        for(int i = 0;i<n;i++)
        {
            scanf("%d",&data);

            mp[data].push_back(i);

        }

        for(map<int,vector<int> >::iterator it = mp.begin(); it != mp.end();it++)
        {
            if(it->second.size() < x)
            {
                continue;
            }

            vector<int > &pos = it->second;

            for(int i = 0 ;i + x <= pos.size();i++)
            {
                int l1 = i == 0?0:pos[i-1]+1;

                int l2 =pos[i]+1;

                int r1 = pos[i+x-1];

                int r2 = (i+x == pos.size() ? n-1:pos[i+x]-1);

                E[l1].push_back(make_pair(1,make_pair(r1,r2)));

                E[l2].push_back(make_pair(-1,make_pair(r1,r2)));
            }
        }

            Build(0,n-1,1);

            long long ans = 0;

            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<E[i].size();j++)
                {
                    Up(0,n-1,1,E[i][j].second.first,E[i][j].second.second,E[i][j].first);

                    printf("%d %d %d\n",E[i][j].second.first,E[i][j].second.second,E[i][j].first);

                }
                ans += Query(0,n-1,1,i,n-1);
            }

            cout<<ans<<endl;
    }
    return 0;
}
