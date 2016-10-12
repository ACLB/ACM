#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s,t,x;

    cin>>t>>s>>x;

    if(x<t) printf("NO\n");

    else
    {
        if(((x-t)%s == 0|| (x-t)%s ==1 && x-t>1)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
