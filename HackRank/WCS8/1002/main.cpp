#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+100;
int a[2*maxn];
int b[2*maxn];
int n,m;
int Rank[2*maxn];
int main()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i = 0;i<m;i++) scanf("%d",&b[i]);
    int s = 1;
    Rank[0]= 1;
    for(int i = 1;i<n;i++) {
        if(a[i] == a[i-1]) Rank[i] = s;
        else Rank[i] = ++s;
    }
    for(int i = 0,j = n-1;i<m;i++) {
        while(j>=0 && b[i]>a[j] ) j--;
        if(j == -1) printf("1\n");
        else{
            if(b[i] == a[j]) printf("%d\n",Rank[j]);
            else if(b[i] <a[j]) printf("%d\n",Rank[j]+1);
        }
    }
    return 0;
}
