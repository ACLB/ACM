#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
char str[1000100];
int main() {
    int n;
    scanf("%d",&n);
    int m = 1;
    for(;m*(m+1)/2<n;m++);
    for(int i = 0;i<m;i++) str[i] = ')';
    for(int i = m;i<2*m;i++) str[i]= '(';
    str[2*m] = '\0';
    int st = m;
    for(int i  = 0;i<m*(m+1)/2-n;i++,st--) {
        swap(str[st],str[st-1]);
    }
    printf("%s\n",str);
    return 0;
}
