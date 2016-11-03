#include <bits/stdc++.h>

using namespace std;
const int maxn = 550;
int n,k;
int a[maxn];
int b[maxn];
vector<pair<int,int> >vp;
bool ok() {
    int num = 0,sum = 0,st = 1;
    for(int i = 1;i<=n;i++) {
        sum+=a[i];
        if(sum>=b[st]) {
            st++;
            num++;
            sum = 0;
        }
        if(num>k) return false;
    }
    if(num<k) return false;
    sum =0 ,st = 1,l = 1;
    for(int i = 1;i<=n;i++) {
        sum+=a[i];
        if(sum>=b[st]) {
            int Ma = 0;
            for(int j = l;j<=i;j++) Ma = max(Ma,a[j]);
            for(int j = l;j<=i;j++) {
                if(a[j]!=ma) continue;
                if(j == l && a[j]>a[j+1]) {
                    for(int k = l;k<i;k++) {
                        vp.push_back(make_pair<l,0>);
                    }
                    break;
                }
                else if(j == i && a[j]>a[j-1]) {
                    for(int k = l;k<i;k++) vp.push_back(make_pair<i,1>);
                    break;
                }
                else if(a[j]>a[j-1]) {
                    for(int k = i;k>a[])
                }
            }
            st++;
            sum = 0;
            l = i+1;
        }
    }
}
int main() {
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&k);
    for(int i = 1;i<=k;i++) scanf("%d",&b[i]);
    if(ok()) {
        
    }
    return 0;
}
