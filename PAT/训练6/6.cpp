#include <bits/stdc++.h>

using namespace  std;

typedef struct node
{
    int num1,num2,Id;

    double avg1,avg2;

    int op; int mc;
}No;

bool cmp1(node a,node b)
{
    return a.num1>b.num1;
}

bool cmp2(node a,node b)
{
    return a.num2>b.num2;
}

bool cmp3(node a,node b)
{
    return a.avg1>b.avg1;
}

bool cmp4(node a,node b)
{
    return a.avg2>b.avg2;
}


No s[1100],t[1100];

int  main()
{
    int n,m,num;

    cin>>n>>m;

    for(int i = 0;i<n;i++)
    {
        cin>>s[i].num1>>s[i].num2>>num;

        s[i].Id = i;

        s[i].avg1 = s[i].num1*1.0/num;

        s[i].avg2 = s[i].num2*1.0/num;

        s[i].mc = n;

        t[i] = s[i];
    }

    sort(t,t+n,cmp1);

    num = 0;

    int st = -1;

    for(int i = 0;i<n;i++)
    {
        if(st!=t[i].num1)
        {
            st = t[i].num1;

            num = i;
        }
        if(s[t[i].Id].mc>num)
        {
            s[t[i].Id].mc = num;

            s[t[i].Id].op = 1;
        }
    }
    sort(t,t+n,cmp2);

    num = 0;

    st = -1;

    for(int i = 0;i<n;i++)
    {
        if(t[i].num2 != st)
        {
            st  =t[i].num2;

            num = i;
        }
        if(s[t[i].Id].mc>num)
        {
            s[t[i].Id].mc = num;

            s[t[i].Id].op = 2;
        }
    }

    sort(t,t+n,cmp3);

    double sst =-1;

    num = 0;

    for(int i = 0;i<n;i++)
    {
        if(t[i].avg1!=sst)
        {
            sst = t[i].avg1 ;

            num = i;
        }
        if(s[t[i].Id].mc>num)
        {
            s[t[i].Id].mc = num;

            s[t[i].Id].op = 3;
        }
    }

    sort(t,t+n,cmp4);

    sst = -1;

    num= 0;

    for(int i = 0;i<n;i++)
    {
        if(t[i].avg2 != sst)
        {
            sst = t[i].avg2;

            num = i;
        }
        if(s[t[i].Id].mc>num)
        {
            s[t[i].Id].mc = num;

            s[t[i].Id].op = 4;
        }
    }

    int Id;
    for(int i = 0;i<m;i++)
    {
        cin>>Id;

        if(i) cout<<" ";

        cout<<s[Id].mc+1<<":"<<s[Id].op;

    }

    cout<<endl;
    return 0;
}
