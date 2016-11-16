#include <bits/stdc++.h>

using namespace std;
int n,sum1,sum2;
char str[110000];
int main() {
    scanf("%d",&n);
    scanf("%s",str);
    sum1= sum2 =0;
    for(int i = 0;i<n;i++) {
        if(str[i] == 'A') sum1++;
        else sum2++;
    }
    if(sum1 == sum2) printf("Friendship\n");
    else if(sum1<sum2) printf("Danik\n");
    else printf("Anton\n");
    return 0;
}
