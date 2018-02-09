#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1e5+100;

char str[1100];
int a,b;
int Check(int L,int R) {
    int ans = 0;
    for(int i = L;i<=R;i++) {
        if(str[i] >= '0' && str[i]<='9')
        {
            ans = ans*10+str[i]-'0';
        }
        else return -1;
    }
    return ans;
}
int main() {
    int n;
    gets(str);
    int len = strlen(str);
    int i;
    for(i = 0;i<len;i++) if(str[i] != ' ') break;
    for(;i<len;i++) {
        if(str[i] ==' ') {

            a =  Check(0,i-1);
            for(;i<len;i++) if(str[i] != ' ') break;
            b = Check(i,len-1);
            break;
        }
    }
    if(a == -1 || b == -1) {
        if(a == -1 && b ==-1) printf("? + ? = ?\n");
        else if( a == -1) printf("? + %d = ?\n",b);
        else printf("%d + ? = ?\n",a);
    }
    else printf("%d + %d = %d\n",a,b,a+b);

    return 0;
}
