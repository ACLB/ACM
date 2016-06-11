#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

struct node
{
    double x,y;

    node(){}

    node(double _x,double _y):x(_x),y(_y){}

    node operator - (const node &a)const
    {
        return node(a.x-x,a.y-y);
    }

    node operator + (const node &a)const
    {
        return node(x+a.x,y+a.y);
    }

    double operator * (const node &a)const
    {
        return a.x*x+a.y*y;
    }

    double operator ^ (const node &a)const
    {
        return a.x*y-a.y*x;
    }
}a,b,c;


int dbcmp(double x)
{
    return fabs(x)<eps?0:(x>0?1:-1);
}


int main()
{
    int n;

    stack<node>S;

    scanf("%d",&n);

    scanf("%lf %lf",&a.x,&a.y); S.push(a);

    scanf("%lf %lf",&a.x,&a.y); S.push(a);

    for(int i = 3;i<=n;i++)
    {
        scanf("%lf %lf",&a.x,&a.y);

        while(S.size()>=2)
        {
            b = S.top();

            S.pop();

            c = S.top();

            S.pop();

            if(dbcmp((b.y-a.y)*(c.x-b.x) -(b.x-a.x)*(c.y-b.y)) >= 0)
            {
                S.push(c);
            }
            else
            {
                S.push(c); S.push(b);

                break;
            }
        }

        S.push(a);
    }

    printf("%d\n",S.size());

    return 0;
}
