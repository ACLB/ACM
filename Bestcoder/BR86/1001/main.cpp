#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

const double Pi = acos(-1.0);

const double eps = 1e-8;

typedef long long LL;

LL sum,q;

int main()
{
    int T;

    int n,m,x;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&m);

        sum = 0;

        for(int i = 0;i<n;i++)
        {
            scanf("%d",&x);

            sum+=x;
        }

        for(int i  = 0;i<m;i++)
        {
            scanf("%I64d",&q);

            if(sum>=q) printf("0");
            else printf("1");
        }

        printf("\n");
    }
    return 0;
}
