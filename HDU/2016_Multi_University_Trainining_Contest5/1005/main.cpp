#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Max = 1100000;

const LL Mod = 1000000007;

LL dp1[Max];

LL dp2[Max];

char s[Max];

char Ma[Max*2];

int Mp[Max*2];

void Manacher(int len)
{
    int l =0 ;

    Ma[l++] = 'S';

    Ma[l++] = '#';

    for(int i = 0;i<len;i++)
    {
        Ma[l++] = s[i];

        Ma[l++] = '#';
    }

    Ma[l] = 0;

    int mx = 0,id = 0;

    for(int i = 0;i<l;i++)
    {
        Mp[i] = mx>i?min(Mp[2*id-1],mx-i):1;

        while(Ma[i+Mp[i]] == Ma[i-Mp[i]]) Mp[i]++;

        if(i+Mp[i]>mx)
        {
            mx = i+Mp[i];

            id = i;
        }
    }

}

int main()
{
    while(~scanf("%s",s))
    {
        int len = strlen(s);

        Manacher(len);

        memset(dp1,0,sizeof(dp1));

        memset(dp2,0,sizeof(dp2));

        for(int i =1;i<=2*len;i++)
        {
            if(i%2 ==0)
            {
                int s = Mp[i]/2;

                int t = i/2;

                dp1[t]=(dp1[t]+((2*t-s+1)*s/2)%Mod)%Mod;

                dp1[t+s]=((dp1[t+s]-((2*t-s+1)*s/2))%Mod+Mod)%Mod;

                dp2[t]=(dp2[t]+((2*t+s-1)*s/2))%Mod;

                dp2[t-s]=((dp2[t-s]-((2*t+s-1)*s/2))%Mod+Mod)%Mod;
            }
            else  if(i%2 && Mp[i]>1)
            {
                int s = Mp[i]/2;

                int t = i/2;

                dp1[t+1]=(dp1[t+1]+(2*t-s+1)*s/2)%Mod;

                dp1[t+1+s]=((dp1[t+1+s]-(2*t-s+1)*s/2)%Mod+Mod)%Mod;

                dp2[t]=(dp2[t]+(2*t+s+1)*s/2)%Mod;

                dp2[t-s]=((dp2[t-s]-(2*t+s+1)*s/2)%Mod+Mod)%Mod;
            }
        }

        for(int i = 1;i<=len;i++)
        {
            printf("i = %d %lld",i,dp1[i]);
            dp1[i]=((dp1[i]+dp1[i-1])%Mod+Mod)%Mod;

            printf(" %lld\n",dp1[i]);
        }

        printf("\n");



        for(int i = len;i>=1;i--)
        {
            dp2[i]=((dp2[i]+dp2[i+1])%Mod+Mod)%Mod;
        }

        LL ans = 0;

        for(int i = 1;i<len;i++)
        {
            ans = (ans+(dp1[i]*dp2[i+1])%Mod)%Mod;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
