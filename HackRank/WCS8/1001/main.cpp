#include <bits/stdc++.h>
using namespace std;
char str[110];
int main(){
    scanf("%s",str);
    int ans = 0;
    int len = strlen(str);
    for(int i = 1;i<len;i++) {
        if(str[i] == '_' && str[i-1]!='_') ans++;
    }
    if(str[len-1]!='_') ans++;
    printf("%d\n",ans);
    return 0;
}
