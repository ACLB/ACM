#include <bits/stdc++.h>

using namespace std;

set<int>S;

int main()
{
    int n,m;

    scanf("%d",&n);

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&m);

        set<int>::iterator it = S.upper_bound(m);

        if(it != S.end())
        {
            S.erase(it);
            S.insert(m);
        }
        else S.insert(m);
    }

    printf("%d\n",S.size());

    return 0;

}
