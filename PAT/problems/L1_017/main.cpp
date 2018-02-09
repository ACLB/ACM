#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    cin>>s;
    double bite = 1;
    if(s[0] == '-') bite*=1.5;
    int sum = 0,num = 0;
    int Mod = 0;
    for(int i= s[0] == '-'?1:0;i<s.size();i++) {
        if(s[i] == '2') sum++;
        num++;
        Mod = (Mod*10+s[i]-'0')%2;
    }
    if(!Mod) bite*=2;
    printf("%.2f%%\n",sum*1.0/num*bite*100);
    return 0;
}
