#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<queue>
#include<stack>
#include<list>
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

typedef long long ll;
const int maxn=50000+1000;
const ll inf=1e9;
const ll mod=1e9+7;

int a[maxn];
int b[maxn];
ll Li[maxn],La[maxn],Ri[maxn],Ra[maxn];
int cnt[maxn];
int bit[maxn];

int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

void add(int i,int x){
    while(i<maxn){
        bit[i]+=x;
        i+=i&-i;
    }
}

void Pu(ll *st,int l,int r)
{
    for(int i =l;i<=r;i++)
    {
        if(i!=l) printf(" ");

        printf("%lld",st[i]);
    }

    printf("\n");
}

int main()
{
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        int m=unique(b,b+n)-b;
        for(int i=0;i<n;i++){
            a[i]=lower_bound(b,b+m,a[i])-b;
            a[i]+=1;
            //cout<<a[i]<<endl;
        }
        ll la=0,lb=0;
        memset(cnt,0,sizeof(cnt));
        memset(bit,0,sizeof(bit));
        for(int i=0;i<n;i++){
            Li[i]=sum(a[i]-1);
            La[i]=i-Li[i]-cnt[a[i]];
            add(a[i],1);
            cnt[a[i]]++;
            la+=Li[i];
        }
        memset(cnt,0,sizeof(cnt));
        memset(bit,0,sizeof(bit));
        for(int i=n-1;i>=0;i--){
            Ri[i]=sum(a[i]-1);
            Ra[i]=n-1-i-Ri[i]-cnt[a[i]];
            add(a[i],1);
            cnt[a[i]]++;
            lb+=Ri[i];
        }

//        Pu(Li,0,n-1);
//        Pu(La,0,n-1);
//        Pu(Ri,0,n-1);
//        Pu(Ra,0,n-1);
        ll ans=la*lb;
        printf("%lld\n",ans);
        for(int i=0;i<n;i++){
            ans=ans-Ri[i]*Ra[i];
            ans=ans-Li[i]*La[i];
            ans=ans-Li[i]*Ri[i];
            ans=ans-La[i]*Ra[i];
        }
        printf("%I64d\n",ans);
    }
	return 0;
}
