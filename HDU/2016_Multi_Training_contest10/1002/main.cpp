#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#define LL long long
#define Pr pair<int,int>
#define fread(ch) freopen(ch,"r",stdin)
#define fwrite(ch) freopen(ch,"w",stdout)
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double  Pi = acos(-1.0);
const int mod = 1000000007;
int main(){
    int T; double l;
    scanf("%d",&T);
    while(T--){
        scanf("%lf",&l);
        double c = acos(-sqrt(2)/4);
        double d = acos(sqrt(2)*5/8);
        double area1 =  (l/2)*(l/2)*(Pi-c);
        double area2 = l*l*d;
        double area3 = sqrt(2)*l*l*sin(d)/2;
        printf("%.2f\n",(area1-(area2-area3))*2);
    }
    return 0;
}
