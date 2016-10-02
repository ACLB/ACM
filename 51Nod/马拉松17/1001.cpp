#include <bits/stdc++.h>
using namespace std;
#define rr(x) freopen(x,"r",stdin)
#define ww(x) freopen(x,"w",stdout)
#define LL long long 
bool mex[100];
int Sg[100][100];
int  GetSg(int s,int k) {
    memset(mex,false,sizeof(mex));
    for(int i = (s+k-1)/k;i<s;i++) {
        mex[Sg[k][i]] = true;
    }
    for(int i = 0;i<100;i++) if(!mex[i]) return i;
}

int main() {
    ww("out.out");
    memset(Sg,0,sizeof(Sg));
    for(int i = 2;i<100;i++) {
        for(int j = 2;j<100;j++) 
        {
            Sg[i][j] = GetSg(j,i);
            printf("n = %d k = %d Sg = %d\n",j,i,Sg[i][j]);

        }
    }
    return 0;
}
