#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int num[110];

int main() {

    int n,data,k;

    scanf("%d %d",&n,&k);

    memset(num,0,sizeof(num));

    for(int i = 0;i<n;i++) {
        scanf("%d",&data);
        num[data%k]++;
    };

    int ans = 0;
    if(num[0] == 1) ans++;

    int m = k%2 ==0 ?k/2-1:k/2;

    for(int i = 1;i<=m;i++) ans+=max(num[i],num[k-i]);

    if(k%2 ==0 && num[k/2] == 1) ans++;

    if(ans == 0) ans = 1;
     printf("%d\n",ans);

    return 0;
}
