#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int c[200100];


int main()
{
    int n;

    int data;

    scanf("%d",&n);

    n*=2;

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&c[i]);
    }

    sort(c,c+n);

    printf("%d\n",c[n/2-1]);

    return 0;
}
