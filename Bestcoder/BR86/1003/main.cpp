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

int a[220000];

int main()
{
    int T;

    int n,m,k,data;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d %d",&n,&m,&k);

        for(int i = 0;i<n;i++)
        {
            scanf("%d",&data);

            if(data>=m) a[i] = 1;
            else a[i] = 0;
        }

        int l = 0,s =0;

        LL sum =0;

        for(int i= 0 ;i<n;i++)
        {
            s+=a[i];

            if(s>=k){
                while(s>=k){sum+=(n-i); s-=a[l]; l++;}
            }
        }

        printf("%I64d\n",sum);
    }

    return 0;
}
