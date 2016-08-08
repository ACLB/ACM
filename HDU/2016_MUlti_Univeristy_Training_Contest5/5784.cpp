#include <bits/stdc++.h>

using namespace std;

const int Max = 2200;

typedef long long LL;

typedef struct node
{
    LL x,y;

    node(){}

    node(LL _x,LL _y):x(_x),y(_y){}

    node operator + (const node &a)const
    {
        return node(x+a.x,y+a.y);
    }

    node operator - (const node &a) const
    {
        return node(x-a.x,y-a.y);
    }

    LL operator * (const node &a) const
    {
        return x*a.x+y*a.y;
    }

    LL operator ^ (const node &a) const
    {
        return x*a.y-y*a.x;
    }

    bool operator < (const node &a) const
    {
        if(y*a.y <= 0)
        {
            if(y>0||a.y>0) return y<a.y;

            if(y ==0 && a.y ==0) return x<a.x;
        }

        return ((*this)^a)>0;
    }
}Point;

Point p[Max];

int n;

int main()
{
    while(~scanf("%d",&n))
    {
        LL sum1 = 0,sum2 = 0;

        for(int i = 0;i<n;i++)
        {
            scanf("%lld %lld",&p[i].x,&p[i].y);
        }

        vector<Point>vp;

        for(int z = 0;z<n;z++)
        {
            vp.clear();

            for(int j = 0;j<n;j++)
            {
                if(z ==j) continue;

                vp.push_back(p[j]-p[z]);
            }

            sort(vp.begin(),vp.end());

            vp.insert(vp.end(),vp.begin(),vp.end());

            for(int i = 0,j = 0,k = 0,r = 0;i<n-1;i++)
            {
                while(j<i+n-1 && !(vp[i]^vp[j]) && vp[i]*vp[j]>0) j++;  

                k = max(k,j);

                while(k<i+n-1 &&((vp[i]^vp[k])>0) &&(vp[i]*vp[k])>0) k++;

                r = max(r,k);

                while(r<i+n-1&& ((vp[i]^vp[r])>0)) r++;

                sum1+=(k-j);

                sum2+=(r-k);
            }
        }

        printf("%lld\n",(sum1-2*sum2)/3);
    }
    return 0;
}
