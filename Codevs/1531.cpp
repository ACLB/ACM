#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,h;
    scanf("%d",&n);
    stack<int>St;
    long long  sum = 0;
    for(int i = 0;i<n;i++) {
        scanf("%d",&h);
        sum+=St.size();
        while(!St.empty() && St.top()<h) St.pop();
        St.push(h);
    }
    cout<<sum<<endl;
    return 0;
}
