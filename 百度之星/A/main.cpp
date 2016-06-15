#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const double eps = 1-6;

const double Pi = acos(-1.0);

const double e = exp(1.0);

const int Max = 11000;

const int MaxN = 1e6;

struct node
{
    int s,d;
}LL[Max*3],RR[Max*3];

bool cmp1(node a1,node a2)
{
    return a1.s == a2.s ? a1.d<a2.d:a1.s>a2.s;
}
bool cmp2(node a1,node a2)
{
    return a1.s == a2.s ? a1.d<a2.d:a1.s<a2.s;
}
int Dp1[Max*2];
int Dp2[Max*2]
int main()
{
    int n,T,Z=1;
    int x,y,z,d;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int num1 =0 ;
        int num2 = 0;
        for(int i = 0;i<n;i++)
        {
            scanf("%d %d %d %d",&x,&y,&z,&d);
            int ans =y-x-2*z;
            if(ans>0) continue;
            int l = y-z;
            int r = x+z;
            if(d==-1)
            {
                RR[num1].d = 1;
                RR[num1++].s = r;
                RR[num1].d = -1;
                RR[num1++].s = l-1;
            }
            else
            {
                LL[num2].d = 1;
                LL[num2++].s = l;
                LL[num2].d = -1;
                LL[num2++].s = r+1;
            }
        }
        sort(LL,LL+num2,cmp2);
        sort(RR,RR+num1,cmp1);
        int ans = 0;
        for(int i = 0;i<num1;i++)
        {
            ans += RR[i].d;
            Dp1[i] = ans;
        }
        ans = 0;
        for(int i = 0;i<num2;i++)
        {
            ans+=LL[i].d;
            Dp2[i] = ans;
        }
        for(int i = 1;i<num1;i++) Dp1[i] = max(Dp1[i-1],Dp1[i]);
        for(int i = 1;i<num2;i++) Dp2[i] = max(Dp2[i-1],Dp2[i]);
        int j = num1-1;
        ans = 0;
        for(int i = 0;i<num2;i++)
        {
            for(;j>=0;j--)
            {
                if(RR[j].s<LL[i].s) j--;
                else break;
            }
            ans = max(Dp2[i]+Dp1[j],ans);
        }
        printf("Case #%d:\n",Z++);
        printf("%d\n",ans);
    }
    return 0;
}
