#include <bits/stdc++.h>
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
using namespace std;
const int Max = 100100;
int a[Max],n,m;
int pre[Max];
void Init() {
    for(int i = 1;i<=n;i++) pre[i] = i;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        Init();
        for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
        stack<int>st;
        for(int i = n;i>=1;i--) {
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(st.empty())
                pre[i] = n+1;
            else
                pre[i] = st.top();
            st.push(i);
        }
        scanf("%d",&m);
        int l,r;
        for(int i = 1;i<=m;i++) {
            scanf("%d %d",&l,&r);
            int ans = a[l]; l = pre[l];
            while(l<=r) {
                ans %= a[l];
                l = pre[l];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
