#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <string>

using namespace std;
int a[550][550];
int b[550][550];
int c[550][550];
int main() {
    int n;
    scanf("%d",&n);
    for(int i =0 ;i<n;i++)
        for(int j = 0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(int i = 0 ;i<n;i++)
        for(int j =0;j<n;j++)
            scanf("%d",&b[i][j]);
    for(int i = 0;i<n;i++)
        for(int j =0;j<n;j++)
            scanf("%d",&c[i][j]);
    bool flag = false;
    for(int  i = 0;i<n;i++) {
        int co = i;
        int  r = i;
        int sum = 0;
        for(int j =0;j<n;j++) {
            sum+=a[r][j]*b[j][co];
        }
        if(sum != c[r][co]) {
            flag = true;
            break;
        }
    }
    if(flag) printf("NO\n");
    else printf("YES\n");
    return 0;
}
