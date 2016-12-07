#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    int a,b,c;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&a,&b,&c);
        if(abs(a-c) == abs(b-c)) {
            printf("Mouse C\n");
        }
        else {
            if(abs(a-c)<abs(b-c)) printf("Cat A\n");
            else printf("Cat B\n");
        }
    }
    return 0;
}
