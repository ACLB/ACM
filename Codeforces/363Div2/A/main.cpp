#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

char s[230000];

int  a[230000];

int main()
{
    int n,data;

    scanf("%d",&n);

    scanf("%s",s);


    int ans = INF;

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);

        if(!i) continue;

        if(s[i]=='L' && s[i-1] == 'R')
        {
            ans  = min(ans,(a[i]-a[i-1])/2);
        }
    }
    if(ans == INF) ans = -1;

    printf("%d\n",ans);
    return 0;
}
