#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 55555;
int n;
struct node {
    int po;
    char lab[100];
    int ne[2],fa;
    bool operator < (const node &a)const {
        return strcmp(lab,a.lab)<0;
    }
}p[maxn];
int main() {
    int n;
    while(~scanf("%d",&n)  && n) {
        top = 0;
        for(int i = ;i<n;i++) {
            scanf("%*[ ]%[^/]/%d",p[i].lab,&p[i].po);
            p[i].ne[0] = p[i].ne[1] = -1;
            p[i].fa = -1;
        }
        sort(s,s+n);
        int root = 0;
        for(int  i = 1;i<n;i++) ins(i);
    }
    return 0;
}
