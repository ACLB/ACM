#include <bits/stdc++.h>
using namespace std;

int Get(int n) {
    int ans = 0;
    while(n) {
        ans+=n%10;
        n/=10;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    int ans = 0,num = 0;
    for(int i = 1;i*i<=n;i++) {
        if(n%i ==0 ){
            int a = Get(i);
            if(num<a || (num == a && ans>i)) {
                ans = i;
                num = a;
            }
            a = Get(n/i);
            if(num<a || (num == a && ans>n/i)) {
                ans = n/i;
                num = a;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
