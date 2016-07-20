#include <bits/stdc++.h>

using namespace std;

map<long long,int>S;

long long s,t;

int main()
{
    int n;

    scanf("%d",&n);

    for(int i = 0;i<n;i++)
    {
        scanf("%lld %lld",&s,&t);

        S[s]++;

        S[t]++;
    }


    map<long long ,int>::iterator ant = S.begin();

    int ans = 1;

    for(map<long long,int>::iterator it = S.begin();it!=S.end();it++)
    {
        if(ant->second < it->second)
        {
            ans =1;
            ant = it;
        }
        else if(ant->second == it->second)
        {
            ans++;
            if(ant->first>it->first)
            {
                ant = it;
            }
        }
    }

    if(ans == 1)
    cout<<ant->first<<" "<<ant->second<<endl;
    else 
    cout<<ant->first<<" "<<ant->second<<" "<<ans<<endl;

    return 0;
}
