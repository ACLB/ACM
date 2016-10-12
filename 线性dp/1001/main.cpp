#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 11234;
int has[30];
char str[maxn];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",str);
        int len = strlen(str);
        memset(has,false,sizeof(has));
        for(int i = 0 ;i<len;i++) {
            int st = str[i] - 'a';
            int ma = 0;
            for(int j = 0;j<st;j++) ma = max(ma,has[j]);
            has[st] = max(has[st],ma+1);
        }
        int ans = 0;
        for(int i = 0;i<26;i++) ans = max(ans,has[i]);
        printf("%d\n",ans);
    }
    return 0;
}
