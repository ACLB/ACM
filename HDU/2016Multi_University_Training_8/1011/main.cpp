#include <bits/stdc++.h>

using namespace std;

int T,n;

char str[100100];

bool ok()
{
    int Mi = n;

    int sum = 0;

    for(int i = 0; i<n; i++)
    {
        sum+=(str[i] == '('?1:-1);

        Mi = min(Mi,sum);
    }
    if(sum!=0) return false;

    if(n == 2) return str[0] == ')';

    return Mi>=-2;
}

int main()
{
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        scanf("%s",str);

        if(ok()) printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
