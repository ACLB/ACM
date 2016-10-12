#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Max  = 1e6+100;
int a[Max];
void Get(int x){
    for(int i = 1;i*i<=x;i++){
        if(x%i == 0) a[++a[0]] = i;
        if(x%i == 0 && x/i!=i) a[++a[0]] = x/i;
    }
}

int main(){
    int n,x,k;
    scanf("%d %d",&n,&k);
    a[0] = 0;
    for(int i = 0;i<n;i++){
        scanf("%d",&x);
        Get(x);
    }
    sort(a+1,a+a[0]+1);
    int ans  = 0;
    int num = 1;
    for(int i = a[0]-1;i>=1;i--){
        if(a[i]==a[i+1]) num++;
        else {
            if(num>=k) {ans = a[i+1];break;}
            num =1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
