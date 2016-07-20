#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const int Max = 1e5+100;

typedef long long LL;

const long long Mod =  998244353;

int a[Max],b[Max];

int Tr[Max];

int n;

int lowbit(int x)
{
    return x&(-x);
}

void Up(int x)
{
    while(x<=n)
    {
        Tr[x]++;

        x+=lowbit(x);
    }
}

int Qey(int x)
{
    int sum = 0;

    while(x)
    {
        sum+=Tr[x];

        x-=lowbit(x);
    }
    return sum;
}

LL Judge()
{
    if(a[0] != b[0]) return 0;

    Up(a[0]);

    LL ans = 1;

    for(int i =1;i<n;i++)
    {
        int op = (a[i] !=a[i-1])+(b[i]!=b[i-1]);

        if(op == 2) return 0;

        if(op == 0)
        {
            ans = (ans *(b[i]-a[i]+1-(Qey(b[i])-Qey(a[i]-1))))%Mod;

            Up(a[i]);
        }
        else
        {
            Up(a[i] == a[i-1]?b[i]:a[i]);
        }

    }

    return ans;
}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        memset(Tr,0,sizeof(Tr));

        for(int i = 0;i<n;i++) scanf("%d",&a[i]);

        for(int i = 0; i<n;i++) scanf("%d",&b[i]);

        LL ans = Judge();

        cout<<ans<<endl;
    }
    return 0;
}
