#include <bits/stdc++.h>
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
#define Random(x) rand()%x
using namespace std;
const int Max = 1e7;
bool vis[Max+100];
int main() {
    ww("data1.in");
    srand((unsigned)time(NULL));
    int n;
    for(int i = 1;i<=3;i++) {
        n = Random(10)+1;
        printf("%d\n",n);
        memset(vis,false,sizeof(vis));
        bool flag = false;
        for(int j = 0;j<n;j++) {
            int s  = Random(10)+1;
            if(vis[s]) {
                j -- ;
                continue;
            }
            else vis[s] = true;
            if(flag) printf(" ");
            else flag = true;
            printf("%d",s);
        }
        printf("\n");
    }
    for(int i = 1;i<=3;i++) {
        n = Random(10)+91;
        printf("%d\n",n);
        memset(vis,false,sizeof(vis));
        bool flag =false;
        for(int j = 0;j<n;j++) {
            int s  = Random(1000)+1;
            if(vis[s]) {
                j -- ;
                continue;
            }
            else vis[s] = true;
            if(flag) printf(" ");
            else flag = true;
            printf("%d",s);
        }
        printf("\n");
    }
    for(int i = 1;i<=2;i++) {
        n = Random(100000)+900001;
        printf("%d\n",n);
        memset(vis,false,sizeof(vis));
        bool flag = false;
        for(int j = 0;j<n;j++) {
            int s  = Random(1000000)+1;
            if(vis[s]) {
                j -- ;
                continue;
            }
            else vis[s] = true;
            if(flag) printf(" ");
            else flag = true;
            printf("%d",s);
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
