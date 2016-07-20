#include <bits/stdc++.h>

using namespace  std;

int main()
{
    int n;

    int m = 0;
    
    scanf("%d",&n);

    m = ((n%10+9)%10)*100+(((n/10)%10+9)%10)*1000+(((n/100)%10+9)%10)+((n/1000+9)%10)*10;

    printf("The encrypted number is %04d\n",m);
    return 0;
}
