#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;
struct node {
    int a[30];
    void init() {
        memset(a,0,sizeof(a));
    }
    int Count() {
        int ans = 0;
        for(int i = 0;i<30;i++) {
            if(a[i]) ans++;
        } 
        return ans;
    }
    void add(int x) {
        for(int i = 29;i>=0;i--) {
            if((x>>i)&1) {
                if(a[i]) x^=a[i];
                else{
                    a[i] = x;
                    break;
                }
            }
        }
    }
}tr[10*maxn];
int n,q;
int main() {
    scanf("%d %d",&n,&q);
    for(int i
    return 0;
}
