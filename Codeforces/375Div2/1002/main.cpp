#include <bits/stdc++.h>

using namespace std;
char str[1100];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    bool op = false;
    int  num = 0;
    int ans1 = 0,ans2 = 0;
    for(int i = 0; i<n; i++) {
        if(str[i] == '(') {
            if(num) {
                if(op) {
                    ans2++;
                } else ans1 = max(ans1,num);
            }
            op = true;
            num = 0;
            continue;
        }
        if(str[i] == ')') {
            if(num) {
                if(op) {
                    ans2++;

                } else ans1 = max(ans1,num);
            }
            op = false;
            num = 0;
            continue;
        }
        if(str[i] == '_') {
            if(num) {
                if(op) {
                    ans2++;
                } else ans1 = max(ans1,num);
            }
            num = 0;
        } else num++;
    }
    if(num) {
        if(op) {
            ans2++;
        } else ans1 = max(ans1,num);
    }
    num = 0;
    printf("%d %d\n",ans1,ans2);
    return 0;
}
