#include <bits/stdc++.h>

using namespace std;
char str[1100][6];
int main() {
    int n;
    scanf("%d",&n);
    bool flag = false;
    for(int i = 0;i<n;i++) {
        scanf("%s",str[i]);
        if(flag) continue;
        if(str[i][0] == 'O' && str[i][1] == 'O') {
            flag = true;
            str[i][0] = str[i][1] = '+';
        }
        else if(str[i][3] == 'O' && str[i][4] == 'O') {
            flag = true;
            str[i][3] = str[i][4] = '+';
        }
    } 
    if(flag){
        printf("YES\n");
        for(int i = 0 ;i<n;i++) printf("%s\n",str[i]);
    }
    else printf("NO\n");
    return 0;
}
