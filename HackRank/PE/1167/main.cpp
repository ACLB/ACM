#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6+100;

bool vis[maxn];

int a[maxn];

int main() {
    a[0] = 2; a[1] = 3;
    vis[2] = true; vis[3 ] = true;
    for(int i = 2;i<100;i++) {
        for(int j =0;j<i;j++) {
            if(!vis[a[j]+a[i-1]]) {
                vis[a[j]+a[i-1]] = true;
                a[i] = a[i-1]+a[j];
                break;
            }
        }
        for(int j =0;j<i;j++) {
            vis[a[j]+a[i-1]] = true;
        }
    }
    for(int i = 0;i<100;i++) printf("%d\n",a[i]);
    return 0;
}
