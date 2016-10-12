#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int Max = 1100;
bool vis[Max];
int pr[Max];
void Get() {
    memset(vis,false,sizeof(vis)); pr[0] =0;
    for(int i = 2;i<Max;i++) {
        if(!vis[i]) {
            pr[++pr[0]] = i;
            for(int j = i+i;j<Max;j+=i) vis[j] = true;
        }
    }
    printf("%d\n",pr[0]);
}
int main(){
    Get();
    return 0;
}
