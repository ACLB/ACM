#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;;i++) {
        if(((i*n)%10)%k ==0 && ((i*n)%10)/k <=1) {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
