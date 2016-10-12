#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n == 1 || n==2) cout<<"-1"<<endl;
    else {
        if(n&1) {
            n>>=1;
            cout<<2*n*n+2*n<<" "<<2*n*n+2*n+1<<endl;
        }
        else {
            n>>=1;
            cout<<n*n-1<<" "<<n*n+1<<endl;
        }
    }
    return 0;
}
