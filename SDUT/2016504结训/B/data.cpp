#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
#define Random(x) rand()%x
using namespace std;
int main() {
    srand((unsigned)time(NULL));
    ww("data1.in");
    int n,m;
    for(int i = 1;i<=20;i++) {
        n = Random(10)+4;
        m = Random(10)+4;
        printf("%d %d\n",n,m);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++){
                if(j) printf(" ");
                printf("%d",Random(10));
            }
            printf("\n");
        }
    }
    for(int i = 1;i<=10;i++) {
    
        n = Random(10)+41;
        m = Random(10)+41;
        printf("%d %d\n",n,m);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++){
                if(j) printf(" ");
                printf("%d",Random(10));
            }
            printf("\n");
        }
    }
    return 0;
}
