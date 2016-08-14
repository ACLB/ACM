#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Max = 1e5;

int num[Max];


int digt(int s)
{
    int ans = 0;

    while(s)
    {
        ans+=s%10;

        s/=10;
    }
    return ans;
}

void Get()
{
    num[0] = 0;

    for(int i = 1;i<Max;i++)
    {
        num[i] = digt(i);
    }
}

int ans[Max];

vector<int>s;

void solve()
{
    ans[0] = 1;

    ans[1] = 1;

    s.clear();

    s.push_back(1);

    for(int i =2;i<=1000;i++)
    {
        int an=0;

        int temp = 0;

        for(int j = 0;j<s.size();j++)
        {
            int t = s[j];

            s[j] = (s[j]*i+temp)%Max;

            temp = (t*i+temp)/Max;

            an+=num[s[j]];
        }
        if(temp) s.push_back(temp);

        an+=num[temp];

        ans[i] = an;
    }
}

int main()
{
    Get();

    solve();

    int T,n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        printf("%d\n",ans[n]);
    }
    return 0;
}
