#include <bits/stdc++.h>

using namespace std;

char s[1100];

int main()
{
    int T;

    int n,k;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&k);

        scanf("%s",s);

        int ans  =0;

        int sum = 1;

        int l = 0;

        for(int i = 0; i<n; i++)
        {
            if(s[i]-'0' == 0)
            {
                sum =1;
                for(int j = l; j<i; j++)
                {
                    sum*=s[j]-'0';
                    if(j-l+1 <k) continue;

                    if(j-l+1 >k) sum/=(s[j-k]-'0');

                    ans = max(ans,sum);
                }

                l = i+1;
            }
        }
        sum =1;
        for(int j = l; j<n; j++)
        {
            sum*=s[j]-'0';
            if(j-l+1 <k) continue;
            if(j-l+1 >k) sum/=(s[j-k]-'0');

            ans = max(ans,sum);
        }

        printf("%d\n",ans);
    }
    return 0;
}
