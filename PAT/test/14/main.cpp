#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

map<LL,LL>mp;

char str[20];

LL Trans() {
    LL ans = 0;
    for(int i = 0;i<17;i++) {
        ans = ans*10 + str[i]-'0';
    }
    ans *=10;
    if(str[17] == 'x') ans+=10;
    else ans += str[17]-'0';
    return ans;
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int w ;
    for(int i = 0;i<n;i++) {
        scanf("%s %d",str,&w);
        w = max(w,m);
        mp[Trans()] += w;
    }
    scanf("%d",&m);
    for(int i= 0;i<m;i++) {
        scanf("%s",str);
        LL  op = Trans();
        if(mp[op]) printf("%lld\n",mp[op]);
        else printf("No Info\n");
    }
    return 0;
}
