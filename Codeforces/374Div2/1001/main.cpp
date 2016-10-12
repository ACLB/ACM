#include <bits/stdc++.h>

using namespace std;

#define DB double
#define ll I64
#define LDB long double
#define LL long long
#define VLI vector<LL,int>
#define VII vector<int,int>
#define MES(a,x) memset(a,x,sizoe(a))
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)

const double eps = 1e-8;
const double e = exp(1.0);
const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f3f3f3f3f3f3f;

char str[10000];

int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    set<int>st;
    st.insert(0);
    int num = 0;
    for(int i = 0;i<n;i++) {
        if(str[i] == 'B') num++;
        else  {
            st.insert(num);
            num = 0;
        }
    }
    st.insert(num);
    int m = st.size();
    printf("%d\n",m-1);
    set<int>::iterator it = st.begin();
    it++;
    bool falg = false;
    for(;it!=st.end();it++) {
        if(falg) printf(" ");
        else falg = true;
        printf("%d",*it);
    }
    if(m -1) printf("\n");
    return 0;
}
