#include <bits/stdc++.h>
using namespace std;
char s[2];
int main(){
    int n,m;
    bool flag = false;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j < m; j++) {
            cin>>s;
            if(s[0]!='B' && s[0]!='W' && s[0]!='G') flag = true;
        }
    }
    if(flag) cout<<"#Color"<<endl;
    else cout<<"#Black&White"<<endl;
    return 0;
}
