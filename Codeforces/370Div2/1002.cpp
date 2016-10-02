#include <bits/stdc++.h>
using namespace std;
char str[100100];
int main() {
    int x = 0,y= 0 ;
    scanf("%s",str);
    int len = strlen(str);
    for(int i  = 0;i<len;i++) {
        if(str[i] == 'U') y++;
        else if(str[i] == 'D') y--;
        else if(str[i] == 'L') x--;
        else if(str[i] == 'R') x++; 
    }
    x = abs(x);
    y = abs(y);
    if((x+y)%2) printf("-1\n");
    else printf("%d\n",(x+y)/2);
    return 0;
}
