#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Max = 1e5;

typedef struct Point
{
    int x,y;

    Point(){}

    Point(int _x,int _y):x(_x),y(_y){}

    Point operator + (const Point &a)const
    {
        return Point(x+a.x,y+a.y);
    }

    Point operator - (const Point &a) const
    {
        return Point(x-a.x,y-a.y);
    }

    int operator * (const Point &a)const
    {
        return x*a.x+y*a.y;
    }

    int operator ^ (const Point &a)
    {
        return x*a.y-y*a.x;
    }
}Vector;

Point p[Max];

int p0;

bool cmp(Point a,Point b)
{
    int ans = (a-p[0])^(b-p[0]);

    if(ans>0) return true;

    if(ans == 0)
    {
        return (a-p[0])*(a-p[0]) < (b-p[0])*(b-p[0]);
    }

    return false;
}

Point Q[Max];

int main()
{
    int n;

    while(~scanf("%d",&n))
    {
        for(int i = 0 ;i<n;i++)
        {
            scanf("%d %d",&p[i].x,&p[i].y);

            if(i)
            {
                if((p[p0].x>p[i].x )|| (p[p0].x == p[i].x&& p[p0].y>p[i].y))
                {
                    p0 = i;
                }
            }
            else p0 = i;
        }

        swap(p[0],p[p0]);

        sort(p+1,p+n,cmp);


        p[n] = p[0];


        int num  = 0;

        Q[num++] = p[0];

        Q[num++] = p[1];

        for(int i = 2;i<=n;i++)
        {
            while(num>=2 &&((p[i]-Q[num-1])^(Q[num-1]-Q[num-2]))>0) num --;

            Q[num++] = p[i];
        }
        int ans = 0;
        for(int i = 0;i<num;i++)
        {
            for(int j = i+1;j<num;j++)
                ans = max(ans,(Q[j]-Q[i]) * (Q[j]-Q[i]));
        }

        printf("%d\n",ans);
    }
    return 0;
}
