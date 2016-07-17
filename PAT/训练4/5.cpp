
#include <bits/stdc++.h>

using namespace std;

int a1,b1,a2,b2;

int main()
{
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);

    if(a1*b2<a2*b1)
    {
        printf("%d/%d < %d/%d\n",a1,b1,a2,b2);
    }
    else if(a1*b2 == a2*b1)
    {
        printf("%d/%d = %d/%d\n",a1,b1,a2,b2);
    }
    else printf("%d/%d > %d/%d\n",a1,b1,a2,b2);
    return 0;
}
