#include <bits/stdc++.h>

using namespace std;

int a[5];
int main() {
    for(int i = 0;i<4;i++) {
        scanf("%d",&a[i]);
    }
    int num1 = min(a[0],min(a[2],a[3]));
    a[0]-=num1;
    int num2 = min(a[0],a[1]);
    printf("%d\n",num1*256+num2*32);
    return 0;
}
