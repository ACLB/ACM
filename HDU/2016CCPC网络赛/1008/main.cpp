#include <bits/stdc++.h>

using namespace std;

const int Max = 250;

struct node
{
    int x,y,z;

    node(){}

    node(int _x,int _y,int _z):x(_x),y(_y),z(_z){}

    node operator + (const node &a)const
    {
        return node(x+a.x,y+a.y,x+a.z);
    }

    node operator - (const node &a)const
    {
        return node(x-a.x,y-a.y,z-a.z);
    }

    int operator * (const node &a)const
    {
        return x*a.x+y*a.y+z*a.z;
    }

    node operator * (const int &a)const
    {
        return node(x*a,y*a,z*a);
    }

    node operator /(const int &a)const
    {
        return node(x/a,y/a,z/a);
    }

    node operator ^ (const node &a)const
    {
        return node(y*a.z-a.y*z,z*a.x-x*a.z,x*a.y-y*a.x);
    }
}p[Max],s[Max];


int dis(node a,node b)
{
    return (a-b)*(a-b);
}

node pvec(node a,node b,node c)
{
    return (a-b)^(b-c);
}
int dots_onplane(node a,node b,node c,node d)
{
    return pvec(a,b,c)*(d-a);
}
int main()
{
    int T,n,z = 1;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(int i = 0;i<n;i++)
        {
            scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
        }

        int ans1  = 0,ans2 = 0;

        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
               int cnt = 0;

               for(int k = 0;k<n;k++)
               {
                   if(k ==i || k == j)continue;

                   if(dis(p[k],p[i]) == dis(p[k],p[j]))s[cnt++] = p[k];
               }

               if(cnt<=1) continue;

               for(int k1 = 0;k1<cnt;k1++)
               {
                   for(int k2 = k1+1;k2<cnt;k2++)
                   {
                       if(dis(s[k1],p[i])!=dis(s[k2],p[i])) continue;

                       if(!dots_onplane(p[i],p[j],s[k1],s[k2])) continue;

                       if(dis(p[i],p[j]) == dis(p[i],s[k1]) && dis(p[i],p[j]) == dis(s[k1],s[k2])) ans1++;
                       else ans2++;
                   }
               }
            }
        }

        printf("Case #%d: %d\n",z++,ans1/6+ans2/2);
    }
    return 0;
}
