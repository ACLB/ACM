#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Max = 1e5+100;

int t1[Max],t2[Max],c[Max];

int sa[Max],ra[Max],he[Max];

char str[Max];

int n;

bool cmp(int *r,int a,int b,int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void DA(int m)
{
    n++;

    int *x = t1,*y = t2;

    for(int i = 0;i<m;i++) c[i] = 0;

    for(int i =0 ; i<n;i++) c[x[i] = str[i]] ++;

    for(int i = 1;i<m;i++) c[i]+=c[i-1];

    for(int i = n-1;i>=0;i--) sa[--c[x[i]]] = i;

    for(int j  =1;j<=n;j<<=1)
    {
        int p = 0;

        for(int i  =n-j;i<n;i++) y[p++] = i;

        for(int i =0 ;i<n;i++) if(sa[i]>=j) y[p++] = sa[i]-j;

        for(int i = 0;i<m;i++) c[i] =0 ;

        for(int i = 0;i<n;i++) c[x[y[i]]]++;

        for(int i = 1;i<m;i++) c[i]+=c[i-1];

        for(int i = n-1;i>=0;i--) sa[--c[x[y[i]]]] = y[i];

        swap(x,y);

        p =1;x[sa[0]] = 0;

        for(int i = 1;i<n;i++) x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;

        if(p >n) break;

        m = p;
    }

    int k = 0;

    n--;

    for(int i =1;i<=n;i++) ra[sa[i]] = i;

    for(int i = 0;i<n;i++)
    {
        if(k) k--;

        int j = sa[ra[i]-1];

        while(str[i+k] == str[j+k]) k++;

        he[ra[i]] = k;
    }
}

int pr[Max];

char s[5];

int main()
{

    int T;

    scanf("%d",&T);

    for(int z = 1;z<=T;z++)
    {
        scanf("%s",s);

        scanf("%s",str);

        n = strlen(str);

        int st = n+1;

        for(int i = n;i>=0;i--)
        {
            if(str[i] == s[0]) st = i;

            pr[i] = st;
        }

        DA(130);

        LL ans = 0 ;

        for(int i = 1;i<=n;i++)
        {
            ans +=max(0LL,(LL)(n-sa[i]-(max(he[i],pr[sa[i]]-sa[i]))));

        }

        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}
