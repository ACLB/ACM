#include <bits/stdc++.h>
using namespace std;
int cal(int a,int b) {
    int ans = 1;
    while(a||b){
        if(a%2) {
            if(b%2) ans<<=1;
            else return 0;
        }
        b>>=1;a>>=1;
    }
    return ans;
}
int main() {
    int a,b;
    while(~scanf("%d %d",&a,&b)){
        printf("%d\n",cal(a,b));
    }
    return 0;
}
