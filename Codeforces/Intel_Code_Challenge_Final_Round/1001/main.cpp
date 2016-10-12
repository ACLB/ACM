#include <bits/stdc++.h>

using namespace std;

int check(char *s) {
    if(strcmp(s,"monday")==0) return 1;
    if(strcmp(s,"tuesday")==0) return 2;
    if(strcmp(s,"wednesday") ==0 ) return 3;
    if(strcmp(s,"thursday")==0) return 4;
    if(strcmp(s,"friday")==0) return 5;
    if(strcmp(s,"saturday")==0)return 6;
    return 0;
}

int main(){
    char str[100];
    scanf("%s",str);
    int f = check(str);
    scanf("%s",str);
    int s = check(str);
    bool op = false;
    if((f+28)%7 == s) op = true;
    if((f+30)%7 == s) op = true;
    if((f+31)%7 == s) op = true;
    if(op) printf("YES\n");
    else printf("NO\n");
    return 0;
}
