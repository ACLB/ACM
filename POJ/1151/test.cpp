#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstring>

#include <cstdlib>

#include <queue>

#include <vector>

#include <map>

#include <algorithm>

using namespace std;

const int Max = 210;

typedef struct Tree
{
    int c;

    double m;
}Tree;

typedef struct Line
{
    double x;

    double y1,y2;

    double op;

    bool operator < (const struct Line a)const
    {
        return x<a.x;
    }
    
}Line;

Tree Tr[Max*10];

Line Li[Max];

vector <double >y;

int n;

void Pushup(int L,int R,int st)
{
    if(Tr[st].c)
    {
        Tr[st].m = y[R-1]-y[L-1];
    }
    else if(R-L==1)
    {
        Tr[st].m=0;
    }
    else
    {
        Tr[st].m = Tr[st<<1].m+Tr[st<<1|1].m;

    }
}

void Build(int L,int R,int st)
{
    Tr[st].c=0;
    Tr[st].m=0;
    if(R-L<=1)
    {
        return ;
    }

    int mid = (L+R)>>1;

    Build(L,mid,st<<1);

    Build(mid,R,st<<1|1);

    Pushup(L,R,st);
}

void Update(int L,int R,int st,int l,int r,int s)
{
    if(l<=L&&R<=r)
    {
        Tr[st].c+=s;
        Pushup(L,R,st);
        return ;
    }

    int mid = (L+R)>>1;

    if(l<mid)
    {
        Update(L,mid,st<<1,l,r,s);
    }
    if(r>mid)
    {
        Update(mid,R,st<<1|1,l,r,s);
    }

    Pushup(L,R,st);
}

int main()
{
    int T=1;
    
    double x1,y1,x2,y2;
    
    while(scanf("%d",&n)&&n)
    {
        int m=0;

        y.clear();

        map<double ,int >M;

        for(int i=0;i<n;i++)
        {
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);

            Li[m].x=x1; Li[m].y1=y1; Li[m].op=true; Li[m++].y2=y2;

            Li[m].x=x2, Li[m].y1=y1; Li[m].op=false; Li[m++].y2=y2;

            y.push_back(y1); y.push_back(y2);
        }

        sort(Li,Li+m);

        sort(y.begin(),y.end());

        y.erase(unique(y.begin(),y.end()),y.end());

        int len = y.size();

        for(int i=0;i<len;i++)
        {
            M[y[i]]=i+1;
        }

        Build(1,len,1);

        double area=0;

        for(int i=0;i<m-1;i++)
        {
            if(Li[i].op)
            {
                Update(1,len,1,M[Li[i].y1],M[Li[i].y2],1);
            }
            else
            {
                Update(1,len,1,M[Li[i].y1],M[Li[i].y2],-1);
            }
            area += (Tr[1].m*(Li[i+1].x-Li[i].x));
        }

        printf("Test case #%d\n",T++);

        printf("Total explored area: %.2f\n\n",area);
    }
    return 0;
}
