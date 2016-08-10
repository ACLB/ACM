#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

//int Sg[110];
//
//bool mex[1100];
//
//int GetSg(int x)
//{
//    memset(mex,false,sizeof(mex));
//
//    for(int  i =  x-1;i>=0;i--)
//    {
//        mex[Sg[i]] = true;
//    }
//
//    int ans;
//
//    for(int i = 1;i<x;i++)
//    {
//        for(int j = 1;j+i<x;j++)
//        {
//            mex[Sg[i]^Sg[j]^Sg[x-i-j]] = true;
//        }
//    }
//
//    for(int i = 0;i<=1000;i++) if(!mex[i]) return i;
//}
//int main()
//{
//    memset(Sg,-1,sizeof(Sg));
//
//    Sg[0] = 0;
//
//    for(int i = 1;i<=100;i++)
//    {
//        Sg[i] = GetSg(i);
//    }
//
//    for(int i = 0;i<=100;i++)
//    {
//        printf("Sg[%d] = %d\n",i,Sg[i]);
//    }
//    return 0;
//}

LL Solve(LL x)
{
    if(x == 0) return x;

    if(x%8 ==0) return x-1;

    if(x%8 ==7) return x+1;

    return x;
}

int main()
{
    int T,n;

    LL ans ,x;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        ans = 0;

        for(int i =0 ;i<n;i++)
        {
           scanf("%lld",&x);

           ans^=Solve(x);
        }

        if(ans) printf("First player wins.\n");

        else printf("Second player wins.\n");
    }
    return 0;

}
