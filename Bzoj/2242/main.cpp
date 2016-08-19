#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
LL y,z,p;
LL Pow(LL n,LL m){
    n%=p;
    LL ans =1 ;
    while(m){
        if(m&1) ans = (ans*n)%p;
        n = (n*n)%p;
        m>>=1;
    }
    return ans;
}
void exgcd(LL a,LL b,LL &g,LL &fx ,LL &fy){
    if(b == 0){
        g = a;
        fx = 1;
        fy = 0;
    }
    else {
        exgcd(b,a%b,g,fy,fx);
        fy-=fx*(a/b);
    }
}
LL Inv()
{
    LL g,fx,fy;
    exgcd(y,p,g,fx,fy);
    if(z%g) return -1;
    y/=g;z/=g;p/=g;
    return ((fx*z)%p+p)%p;
}

LL bsgs(LL a,LL b, LL n){
    a%=n;
    if(!a && !b)
    {
        return 1;
    }

    if(!a) return -1;

    LL m = (LL)sqrt(n)+1;
    LL inv = Pow(Pow(a,m),n-2);
    map<LL,LL>mp; mp.clear();
    mp[1] = 0;
    LL st = 1;
    for(int i =1;i<m;i++){
        st=(st*a)%p;
        if(!mp.count(st)) mp[st] = i;
    }
    for(int i = 0;i<m;i++){
        if(mp.count(b)) return i*m+mp[b];
        b = (b*inv)%p;
    }
    return -1;
}
int main()
{
    int T,k;

    while(~scanf("%d %d",&T,&k))
    {
        while(T--)
        {
            scanf("%lld %lld %lld",&y,&z,&p);
            if(k == 1) printf("%lld\n",Pow(y,z));
            else if(k == 2)
            {
                LL ans = Inv();

                if(ans == -1) printf("Orz, I cannot find x!\n");
                else printf("%lld\n",ans);
            }
            else
            {
                LL ans = bsgs(y,z,p);

                if(ans == -1) printf("Orz, I cannot find x!\n");
                else printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
