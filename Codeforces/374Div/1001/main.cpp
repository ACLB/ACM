#include <bits/stdc++.h>

using namespace std;

char str[1100];
int a[1100];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    int num = 0 ;
    int op = 0;
    for(int i = 0; i<n; i++) {
        if(str[i] == 'B') {
            num++;
        } else {
            if(num)
                a[op++] = num;
            num = 0;
        }
    }
    if(num) a[op++] = num;

    printf("%d\n",op);
    for(int i =0; i<op; i++) {
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    if(op)
        printf("\n");
    return 0;
}
