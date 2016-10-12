#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#define LL long long
#define Pr pair<int,int>
#define fread(ch) freopen(ch,"r",stdin)
#define fwrite(ch) freopen(ch,"w",stdout)

using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1000000007;

bool vis[666];

char str[][111]={
"and",
"one",
"two",
"three",
"four",
"five",
"six",
"seven",
"eight",
"nine",
"ten",
"eleven",
"twelve",
"thirteen",
"fourteen",
"fifteen",
"sixteen",
"seventeen",
"eighteen",
"nineteen",
"twenty",
"thirty"  ,
"forty"  ,
"fifty"  ,
"sixty"  ,
"seventy" ,
"sighty",
"ninety",
"hundred",
"thousand"
};

int hund = 7;
int ad = 3;

int ans;
void solve(int x)
{
    if(x <= 20)
   {
        ans += strlen(str[x]);
   }
   else if(x < 100)
   {
       ans += strlen(str[20+x/10-2]);
       if(x%10) ans += strlen(str[x%10]);
   }
   else if(x == 1000) ans += 11;
   else if(x < 1000)
   {
        ans += strlen(str[x/100]);
        ans += hund;
        if(x%100 == 0) return;
        ans += ad;
        solve(x%100);
   }
}

int main()
{
   fread("test.out");
   fwrite("dp.out");

    int t,n;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            solve(i);
        }

        printf("%d\n",ans);
    }

    return 0;
}
