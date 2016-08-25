#include <bits/stdc++.h>
using namespace std;
#define fr(ch) freopen(ch,"r",stdin)
#define fw(ch) freopen(ch,"w",stdout)
char str[][111]= {
"and",
"one",
"two",
"three",
"four",
"five",
"six",
"seven",
"eight",
"nine",
"ten",
"eleven",
"twelve",
"thirteen",
"fourteen",
"fifteen",
"sixteen",
"seventeen",
"eighteen",
"nineteen",
"twenty",
"thirty"  ,
"forty"  ,
"fifty"  ,
"sixty"  ,
"seventy" ,
"sighty",
"ninety",
"hundred",
"thousand"
};
int ans[1100];
void Init() {
    ans[0] = 0;
    for(int i = 1;i<=1000;i++) {
        if(i<20) ans[i] = strlen(str[i]);
        else if(i>=20 && i<100) ans[i] = strlen(str[i/10+18])+(i%10 == 0?0:ans[i%10]);
        else if(i>=100&& i<1000) ans[i] = ans[i/100]+strlen(str[28])+(i%100 ==0 ?0:strlen(str[0]))+ans[i%100];
        else ans[i] = strlen(str[1])+strlen(str[29]);
    }

    for(int i = 1;i<=1000;i++) ans[i] += ans[i-1];
}
int main() {
    fr("test.out");
    fw("1011.out");
    Init();
    int T,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n); printf("%d\n",ans[n]);
    }
    return 0;
}
