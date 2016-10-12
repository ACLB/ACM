#include <bits/stdc++.h>

using namespace std;
const int maxn = 101000;
char str[maxn];
int m,len;
int vis[30];
int ok(int s) {
    int l = - 1,r = -1;
    int num = 0;
    for(int i = 0;i<len;i++) {
        if(str[i] -'a' < s) l = i,r = i;
        if(str[i]-'a' ==s) r = i;
        if(i - l  == m) {
            if(r>l) {
                num++;
                l = r;
            }
            else return -1;
        }
    }
    return num;
}
int main() {
    scanf("%d",&m);
    scanf("%s",str);
    len = strlen(str);
    for(int i = 0;i<len;i++) vis[str[i]-'a'] ++;
    for(int i = 0;i<26;i++) {
        int st = ok(i);
        if(~st) {
            for(int j = 0;j<i;j++) {
                for(int k = 0;k<vis[j];k++) putchar('a'+j);
            }
            for(int j = 0;j<st;j++) putchar('a'+i);
            puts("");
            return 0;
        }
    }
    return 0;
}
