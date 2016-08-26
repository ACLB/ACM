#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
#define Random(x) rand()%x
using namespace std;
int main() {
    ww("data1.in");
    srand((unsigned)time(NULL));
    int n,x1,x2,y1,y2;
    for(int i = 1;i<=100;i++) {
        n = Random(10)+1;
        printf("%d\n",n);
        for(int j = 0;j<n;j++)
        {
            x1 = Random(10)+1;
            x2 = Random(10)+1;
            if(x1>x2) swap(x1,x2);
            y1 = Random(10)+1;
            y2 = Random(10)+1;
            if(y1>y2) swap(y1,y2);

           printf("%d %d %d %d\n",x1,y1,x2,y2); 
        }
    }
    for(int i = 1;i<=100;i++) {
        n = Random(100)+1;
        printf("%d\n",n);
        for(int j = 0;j<n;j++)
        {
            x1 = Random(100)+1;
            x2 = Random(100)+1;
            if(x1>x2) swap(x1,x2);
            y1 = Random(100)+1;
            y2 = Random(100)+1;
            if(y1>y2) swap(y1,y2);

           printf("%d %d %d %d\n",x1,y1,x2,y2); 
        }
    }
    for(int i = 1;i<=200;i++) {
        n = Random(500)+501;
        printf("%d\n",n);
        for(int j = 0;j<n;j++)
        {
            x1 = Random(500)+501;
            x2 = Random(500)+501;
            if(x1>x2) swap(x1,x2);
            y1 = Random(500)+501;
            y2 = Random(500)+501;
            if(y1>y2) swap(y1,y2);
           printf("%d %d %d %d\n",x1,y1,x2,y2); 
        }
    }
    n = 1000;
    printf("%d\n",n);
    for(int i = 0;i<n;i++) {
        printf("1 1 1000 1000\n");
    }
    return 0;
}
