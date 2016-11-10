#include <bits/stdc++.h>

using namespace std;

char str[110];

bool ok(char c) {
    if(c == 'A' || c == 'E' || c == 'I' || c== 'O' || c =='U' || c=='Y') return true;
    return false;
}

int main() {
    int ans = 0;
    scanf("%s",str);
    int len = strlen(str);
    int num =1;
    for(int i =0;i<len;i++) {
        if(ok(str[i])) {
            ans = max(ans,num);
            num = 1;
        }
        else num++;
    }
    ans = max(ans,num);

    printf("%d\n",ans);
    return 0;
}
