#include <bits/stdc++.h>

using namespace std;
const int maxn = 112345;
int n;
int arr[maxn];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i = 0 ;i<n;i++) scanf("%d",&arr[i]);
        stack<int>S;
        for(int i = n-1;i>=0;i--){
            while(!S.empty()&&S.top()<arr[i]) S.pop();
            S.push(arr[i]);
        }
        if(S.size()%2==0) printf("ANDY\n");
        else printf("BOB\n");
    }
    return 0;
}
