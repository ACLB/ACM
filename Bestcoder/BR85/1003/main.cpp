#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);

const double e = exp(1);

const int INF = 0x3f3f3f3f;

typedef long long LL;

const int Max = 1e6+100;

bool vis[Max];

LL pr[Max];

void Init()
{
    pr[0] = 0;

    for(int i = 2; i<Max; i++)
    {
        if(!vis[i])
        {
            pr[++pr[0]] = i;

            for(int j = i+i; j<Max; j+=i)
            {
                vis[j] = true;
            }
        }
    }
}

bool ok(LL s)
{
    if(s == 1) return false;

    for(int i = 1; i<=pr[0] && pr[i] * pr[i] <=s ; i++)
    {
        if(s%(pr[i]*pr[i]) ==0) return false;
    }

    return true;
}

LL Check(LL s,LL d)
{
    while(s>0)
    {
        if(ok(s)) return s;

        s+=d;
    }

    return -1;
}

int main()
{
    Init();

    int T;

    LL x;

    cin>>T;

    while(T--)
    {
        cin>>x;

        if(x == 1)
        {
            printf("3\n");

            continue;
        }

        if(x == 2)
        {
            printf("2\n");

            continue;
        }

        LL y = sqrt(x);

        LL a1 = Check(y,-1);

        LL a2 = Check(y+1,1);

        LL ans = min(abs(a1*a1-x),abs(a2*a2-x));

        cout<<ans<<endl;
    }
    return 0;
}
