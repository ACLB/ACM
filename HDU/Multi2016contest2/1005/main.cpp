#include <bits/stdc++.h>

using namespace std;

const int Max = 1100;

typedef long long LL;

const LL Mod = 1e9+7;

typedef struct node
{
    LL x,y;

    node() {}

    node(LL _x,LL _y):x(_x),y(_y) {}

    bool operator < (const node &a) const{
        return x == a.x ?y<a.y:x<a.x;
    }

    bool operator == (const node &a)const{
        return (x == a.x&&y == a.y);
    }

    node operator - (const node &a) const{
        return node(x-a.x,y-a.y);
    }

    node operator * (const LL &a)const{
        return node(x*a,y*a);
    }

    node operator / (const LL &a)const{
        return node(x/a,y/a);
    }

} Point;


Point p[Max];

int cnt[Max];

LL C[1100];

void Init(){
    C[0] = 1;

    for(int i = 1; i<=1000; i++) C[i] = (C[i-1]*2)%Mod;

}

map<Point,LL>mp;

int main(){
    int T,n;

    Init();

    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);

        for(int i = 0; i<n; i++) scanf("%lld %lld",&p[i].x,&p[i].y);

        int m = 0;

        sort(p,p+n);

        memset(cnt,0,sizeof(cnt));

        cnt[0] = 1;

        for(int i = 1; i<n; i++){
            if(p[m] == p[i]) cnt[m]++;

            else{
                p[++m] = p[i];

                cnt[m]++;
            }
        }

        LL ans = 0;

        if(m == 0) ans = (C[cnt[0]] -1-cnt[0])%Mod;
        else{
            for(int i = 0; i<=m; i++){
                mp.clear();

                Point v;

                for(int j = i+1; j<=m; j++){
                    v = p[i]-p[j];

                    if(v.x < 0) v = v*-1;

                    LL g = __gcd(abs(v.x),abs(v.y));

                    v=v/g;

                    mp[v]+=cnt[j];
                }
                for(auto it :mp) ans = ((ans+((C[cnt[i]]-1)*(C[it.second]-1))%Mod))%Mod;

                ans = (ans+(C[cnt[i]]-1-cnt[i])%Mod)%Mod;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}
