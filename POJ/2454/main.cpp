#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct node {
    int da,ind;
    bool operator < (const node &a) const {
        return da>a.da;
    }
} a[300],a1[100],a2[100];
int main() {
    int n;
    scanf("%d",&n);
    for(int i =0 ;i<3*n;i++) scanf("%d",&a[i].da),a[i].ind = i+1;
    sort(a,a+3*n);
    int sum1 = 0,sum2 = 0;
    for(int i = 0;i<2*n;i+=2) {
        sum1 += a[i].da;
        a1[i/2] = a[i];
    }
    for(int i = 1 ;i<2*n;i+=2) {
        sum2+=a[i].da;
        a2[i/2] = a[i];
    }
    while(sum1<=500*n || sum2 <= 500*n) {
        int in1 = rand()%n;
        int in2 = rand()%n;

        sum1 = sum1-a1[in1].da +a2[in2].da;
        sum2 = sum2 - a2[in2].da + a1[in1].da;
        swap(a1[in1],a2[in2]);
    }
    for(int i = 0;i<n;i++) printf("%d\n",a1[i].ind);
    for(int i= 0 ;i<n;i++) printf("%d\n",a2[i].ind);
    for(int i = 2*n;i<3*n;i++) printf("%d\n",a[i].ind);

    return 0;
}
