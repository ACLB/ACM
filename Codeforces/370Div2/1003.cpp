#include <bits/stdc++.h>
using namespace std;
int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    if(2*y > x) printf("3\n");
    else if(2*y == x) printf("4\n");
    else {
        int a1 = y,a2 = y,a3 =y;
        int num = 0;
        while(a1<x || a2<x  || a3< x) {
            if(a1>a2) swap(a1,a2);
            if(a1>a3) swap(a1,a3);
            a1 = a2+a3-1;
            num++;
        }
       printf("%d\n",num);
    }
    return 0;
}
