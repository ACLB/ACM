#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char str[110];

int main() {
    int ans = 0;
    scanf("%s",str);
    int len = strlen(str);
    int st  = 'a';
    for(int i = 0;i<len;i++) {
        int ant = abs(str[i]-st);
        ans+=min(ant,26-ant);
        st = str[i];
    }
    printf("%d\n",ans);
    return 0;
}
