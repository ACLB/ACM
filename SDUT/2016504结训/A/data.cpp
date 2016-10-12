#include <bits/stdc++.h>
#define Random(x) rand()%x
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)

using namespace std;

int main() {
    ww("data1.in");
    srand((unsigned)time(NULL));
    for(int i = 0;i<100;i++) {
        int n = Random(10)+1;
        int m = Random(10)+1;
        printf("%d %d\n",n,m);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(j) printf(" ");
                printf("%d",Random(5)+1);
            }
            printf("\n");
        }
    }
    for(int i = 0;i<200;i++) {
        int n = Random(30)+1;
        int m = Random(30)+1;
        printf("%d %d\n",n,m);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(j) printf(" ");
                printf("%d",Random(5)+1);
            }
            printf("\n");
        }
    }
    return 0;
}
