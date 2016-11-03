#include <bits/stdc++.h>

using namespace std;
char str1[110],str2[110];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",str1);
    scanf("%s",str2);
    int ans = n+n;
    for(int i = 0;i<n;i++) {
        bool flag = false;
        for(int j = i,k = 0;j<n;j++,k++) {
            if(str1[j] != str2[k]) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            ans -= (n-i);
            break;
        }
    }
    printf("%d\n",ans);
    return 0;

}
