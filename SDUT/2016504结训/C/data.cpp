#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
#define Random(x) rand()%x
using namespace std;
const int Max = 1e6;
int main() {
    ww("data1.in");
    srand((unsigned)time(NULL));
    int n;
    for(int i = 1;i<=3;i++) {
        n = Random(10)+1;
        printf("%d\n",n);
        for(int j = 0;j<n;j++) {
            if(j) printf(" ");
            printf("%d",Random(10)+1);
        }
        printf("\n");
    }
    for(int i = 1;i<=3;i++) {
        n = Random(10)+91;
        printf("%d\n",n);
        for(int j = 0;j<n;j++) {
            if(j) printf(" ");
            printf("%d",Random(10000)+1);
        }
        printf("\n");
    }
    for(int i = 1;i<=2;i++) {
        n = Random(100000)+900001;
        printf("%d\n",n);
        for(int j = 0;j<n;j++) {
            if(j) printf(" ");
            printf("%d",Random(1000000)+1);
        }
        printf("\n");
    }
    n = 1000000;
    printf("%d\n",n);
    for(int i = n;i>=1;i--) {
        if(i!=n) printf(" ");
        printf("%d",i);
    }
    printf("\n");
    return 0;
}
